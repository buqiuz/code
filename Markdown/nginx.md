# nginx

## 注册为系统服务

>只需要在 /usr/lib/systemd/system/nginx.service中填入

```js
[Unit]
Description=The nginx HTTP and reverse proxy server
After=network.target remote-fs.target nss-lookup.target

[Service]
Type=forking
PIDFile=/run/nginx.pid
# Nginx will fail to start if /run/nginx.pid already exists but has the wrong
# SELinux context. This might happen when running `nginx -t` from the cmdline.
# https://bugzilla.redhat.com/show_bug.cgi?id=1268621
ExecStartPre=/usr/bin/rm -f /run/nginx.pid
ExecStartPre=/usr/sbin/nginx -t
ExecStart=/usr/sbin/nginx
ExecReload=/bin/kill -s HUP $MAINPID
KillSignal=SIGQUIT
TimeoutStopSec=5
KillMode=mixed
PrivateTmp=true

[Install]
WantedBy=multi-user.target
```

## 设置环境变量

### 直接在/etc/profile中设置

1. `export PATH=$PATH:/my/bin`
2. `source /etc/profile`

### 通过在profile.d中创建脚本(这是更为推荐的做法)

>profile.d中的脚本会在有用户通过shell登录启动时自动全部遍历加载

1. `vim etc/profile.d/custom.sh`
2. `export PATH=$PATH:/opt/myapp/bin`
3. `source /etc/profile`

## nginx配置文件

### 地址

`/etc/nginx/nginx.conf`

>其中nginx.conf会包含诸如日志地址,pid地址,模块地址,等等都可以在其中查询到.

### 全局块

- `user [username]`:指定运行nginx的用户
  - 需要有用户存在系统中
- `master_process [default:on|off]`:默认开启,只有开启才能配置work_process
- `work_process [number/auto]`:用于配置工作进程的数量
- `error_log file [debug|info|notice|warn|error|crit|alert|emerge]`:从左到右,信息越来越详细,建议不要设置为info以下,因为磁盘io消耗很大.
- `include [file]`:可用通配符

### events块

- `accept_mutex [default on | off]`:设置nginx网络连接序列化,避免惊群效应,也就是当有一个请求来临时,同时唤醒多个work_process,这样会导致性能开销.只需要唤醒一个进程就行.
- `multi_accept [default off | on]`:禁止状况下,一个work_process只能同时接收一个新的连接,建议打开.
- `work_connections [default 512]`:单个work_process最大连接数.与操作系统支持的最大句柄数有关
- `use method`:选用哪种事件处理模型来处理网络消息,默认值为操作系统定

### http

#### MIME-Type

>浏览器可以展示多种静态资源,如何区分资源类型,就需要用到MIMe.Type,即网络资源类型.

默认会包含以下

```conf
include mime.type;
default_type application/octet-stream
```

`default_type application/octet-stream`:通用二进制数据类型,会提示用户下载文件内容

#### 日志

>nginx支持两种日志,access_log和error_log,我们可以自定义access_log

示例:

```conf
log_format  main  '$remote_addr - $remote_user [$time_local] "$request" '
                      '$status $body_bytes_sent "$http_referer" '
                      '"$http_user_agent" "$http_x_forwarded_for"';

access_log  /var/log/nginx/access.log  main;
//日志配置有就近原则,会使用最近的块的日志配置
```

#### 其他一些配置

- `sendfile            on;`:默认关闭建议开启,提高nginx处理静态资源的能力
- `tcp_nopush          on;`
- `tcp_nodelay         on;`
- `keepalive_timeout   65;`:hhtp握手需要耗费时间,所以建立连接后,可以保持长连接,长连接超时时间如果不设置默认为75s
- `types_hash_max_size 4096;`

#### 静态资源

##### listen

>一般只写端口

`listen 80 [default_server];`

##### server_name

>支持通配符,正则表达式
>工作原理(虚拟主机)

- DNS解析： shop.example.com 会解析到服务器的 IP 地址，并把请求发送到该 IP 上的 Nginx。
- Nginx接收请求： 当 Nginx 收到请求后，它会根据客户端的 Host 头信息（即你在浏览器地址栏输入的域名）来匹配 server_name。
- 匹配到 server_name 为 shop.example.com 的 server 块：
  - 在你的 Nginx 配置中，有一个 server 块配置了 server_name shop.example.com;，所以 Nginx 会选择这个 server 块来处理请求。
  - 也就是说，浏览器请求 shop.example.com 会被 Nginx 定向到 /var/www/shop 目录下的网站。

>假如使用ip进行访问,如果nginx中没配置server_name的ip则会访问default_server;如果没设置default_server,则默认设置为第一个server

这是虚拟host,会与请求头中的host进行匹配,请求头的host为输入网址的域名,不匹配则使用default_server

##### location

- `/abc`:则会匹配`/abc*`
- `=`:精确匹配
- `~`:正则表达式匹配

##### root

>定义路径的上层目录,会将请求路径直接依附在root路径后面

##### alias

>定义路径的别名,会将匹配到的location路径全部替换为alias设置的值

##### index

>设置默认的html页面,当然也可以设置默认的静态资源

##### error_page

>直接跳转

- `error_page [response] http://www.baidu.com`

>重定向地址

```conf
error_page [response] 40x.html
location =40x.html{
    root html;
}
```
