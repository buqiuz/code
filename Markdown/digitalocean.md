# digitalocean

## 无法使用ssh连接问题

可能原因：linux系统软件包太旧
解决方法：使用`sudo yum update`  # 更新所有软件包

## 延迟问题

- New York：231ms
- Singapore：电信丢包严重，移动稳定

## 流程

- `sudo yum update`
- `bash <(curl -Ls https://raw.githubusercontent.com/vaxilu/x-ui/master/install.sh)`

### 使用nginx代理

>先删除digitalocean的默认nginx配置

`sudo rm /etc/nginx/sites-enabled/digitalocean`

```json
server {
    listen 80;
    server_name my.buqiu.me;

    # 重定向所有 HTTP 请求到 HTTPS
    location / {
        return 301 https://$server_name$request_uri;
    }
}

server {
    listen 443 ssl;
    server_name my.buqiu.me;

    ssl_certificate /etc/letsencrypt/live/my.buqiu.me/fullchain.pem;
    ssl_certificate_key /etc/letsencrypt/live/my.buqiu.me/privkey.pem;
    ssl_protocols TLSv1.2 TLSv1.3;
    ssl_ciphers HIGH:!aNULL:!MD5;

    # 代理 code-server
    location / {
        proxy_pass http://localhost:8080/;
        proxy_set_header Host $http_host;
        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection upgrade;
        proxy_set_header Accept-Encoding gzip;
    }

    # 代理 x-ui
    location /x-ui {
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
        proxy_set_header X-Forwarded-Proto $scheme;
        proxy_set_header Host $http_host;
        proxy_set_header X-Real-IP $remote_addr;
        proxy_set_header Range $http_range;
        proxy_set_header If-Range $http_if_range;
        proxy_redirect off;
        proxy_pass http://127.0.0.1:10000;  # 确认 x-ui 是否在使用 HTTP
    }
}
```

## 解锁chatgpt

### 下载并执行warp脚本

[wrap网址](https://gitlab.com/fscarmen/warp)

`wget -N https://gitlab.com/fscarmen/warp/-/raw/main/menu.sh && bash menu.sh`

输入2，选择简体中文

输入13，安装 `wireproxy`，让 WARP 在本地创建一个 socks5 代理 (`bash menu.sh w`)

直接回车，自定义client端口号为40000。【第一次接触warp可以直接回车，安装完warp socks代理。以后慢慢熟悉了，可以将免费版本的warp可以升级为warp+或者team。】

接着就是修改xui面板的xray配置。将下面代码替换掉默认的xray配置，比默认的xray配置多了一个socks出站和一个路由规则，凡是openai的请求全部交给warp的socks端口处理。

```js
{
    "api": {
        "services": [
            "HandlerService",
            "LoggerService",
            "StatsService"
        ],
        "tag": "api"
    },
    "inbounds": [
        {
            "listen": "127.0.0.1",
            "port": 62789,
            "protocol": "dokodemo-door",
            "settings": {
                "address": "127.0.0.1"
            },
            "tag": "api"
        }
    ],
    "outbounds": [
        {
            "protocol": "freedom",
            "settings": {}
        },
        {
            "protocol": "blackhole",
            "settings": {},
            "tag": "blocked"
        },
        {
            "tag": "warp",
            "protocol": "socks",
            "settings": {
                "servers": [
                    {
                        "address": "127.0.0.1",
                        "port": 40000
                    }
                ]
            }
        }
    ],
    "policy": {
        "levels": {
            "0": {
                "handshake": 10,
                "connIdle": 100,
                "uplinkOnly": 2,
                "downlinkOnly": 3,
                "statsUserUplink": true,
                "statsUserDownlink": true,
                "bufferSize": 10240
            }
        },
        "system": {
            "statsInboundDownlink": true,
            "statsInboundUplink": true
        }
    },
    "routing": {
        "rules": [
            {
                "type":"field",
                "domain":[
                    "geosite:openai"
                ],
                "outboundTag":"warp"
            },
            {
                "inboundTag": [
                    "api"
                ],
                "outboundTag": "api",
                "type": "field"
            },
            {
                "ip": [
                    "geoip:private"
                ],
                "outboundTag": "blocked",
                "type": "field"
            },
            {
                "outboundTag": "blocked",
                "protocol": [
                    "bittorrent"
                ],
                "type": "field"
            }
        ]
    },
    "stats": {}
}
```

保存配置，重启xui面板，原本不解锁GPT APP的节点就解锁了。

原本配置

```js
{
  "api": {
    "services": [
      "HandlerService",
      "LoggerService",
      "StatsService"
    ],
    "tag": "api"
  },
  "inbounds": [
    {
      "listen": "127.0.0.1",
      "port": 62789,
      "protocol": "dokodemo-door",
      "settings": {
        "address": "127.0.0.1"
      },
      "tag": "api"
    }
  ],
  "outbounds": [
    {
      "protocol": "freedom",
      "settings": {}
    },
    {
      "protocol": "blackhole",
      "settings": {},
      "tag": "blocked"
    }
  ],
  "policy": {
    "system": {
      "statsInboundDownlink": true,
      "statsInboundUplink": true
    }
  },
  "routing": {
    "rules": [
      {
        "inboundTag": [
          "api"
        ],
        "outboundTag": "api",
        "type": "field"
      },
      {
        "ip": [
          "geoip:private"
        ],
        "outboundTag": "blocked",
        "type": "field"
      },
      {
        "outboundTag": "blocked",
        "protocol": [
          "bittorrent"
        ],
        "type": "field"
      }
    ]
  },
  "stats": {}
}
```

## tun模式

在网络层进行代理，所有网络请求都经过代理，手机默认就是这个，而电脑不开tun模式则是部分代理，浏览器是全部走代理，但其他软件可能不支持代理模式
