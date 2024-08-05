# spring security

## 1. 介绍

spring security是一个开源的java安全框架，提供了一套安全解决方案，可以轻松实现对web应用和数据库访问的认证和授权。

- 认证：用户登录
- 授权：用户访问权限
- 安全管理： 防攻击

### 1.1 原理

```plaintext
                       请求
                    |       ^
                    v       |
+---------------------------------------------+
| +-----------------------------------------+ |
| | Username Password Authentication Filter | |
| +-----------------------------------------+ |
|                       |                     |
|                       v                     |
|       +--------------------------------+    |
|       | Basic Authentication Filter    |    |
|       +--------------------------------+    |
|                       |                     |
|                       v                     |
|                    +-----+                  |
|                    | ... |                  |
|                    +-----+                  |
|                       |                     |
|                       v                     |
| +-----------------------------------------+ |
| | Exception Translation Filter            | |
| +-----------------------------------------+ |
|                       |                     |
|                       v                     |
| +-----------------------------------------+ |
| | FilterSecurity Interceptor              | |
| +-----------------------------------------+ |
+---------------------------------------------+
                    |       ^
                    v       |
                    REST API
                    |       ^  
                    v       |
                       响应
```

>默认有16个过滤器

## 1.2 DelegatingFilterProxy

是spring security中的一个关键过滤器,用于将过滤器的实际处理委托给spring应用上下文的一个指定的bean。它主要用于将servlet过滤器与spring管理的bean集成起来,从而利用spring框架的强大功能来管理过滤器的生命周期和依赖注入

![alt text](<images/spring security/image.png>)

## 2. 配置

### 2.1 引入依赖

```xml
<!-- spring security-->
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-security</artifactId>
</dependency>
```

### 2.2 基于内存的用户认证

可以自定义`UserdetailsService`实现类来替换默认的用户认证

```java
@Bean
public class UserDetailsService userDetailsService() {
    InMemoryUserDetailsManager manager = new InMemoryUserDetailsManager();
    manager.createUser(User.withUsername("user").password("{noop}123456").roles("USER").build());
    return manager;
}
```

### 2.3 基于数据库的用户认证

可以自定义`UserdetailsService`实现类来替换默认的用户认证

### 2.4 crfs

跨站请求伪造（CSRF）是一种恶意利用网站用户浏览器的漏洞。
默认情况下，Spring Security会自动启用CSRF保护，防止跨站请求伪造攻击。

但后端接口将无法正常访问,所以可以禁用CSRF保护

```java
.csrf(AbstractHttpConfigurer::disable)
```

### 2.5 密码加密

- 明文密码: 数据库泄漏会暴露密码
- 哈希加密: 通过hash算法,单向加密,只能加密,不能解密
  - MD5
  - SHA-256
  - SHA-512
  - 但如今有彩虹表,安全性大大降低
- 加盐加密: 加盐加密,可以防止彩虹表攻击,但安全性仍然有缺陷,因为算力剧增,仍能破解
- 自适应单项函数:使用自适应单向函数验证密码时,故意占用资源.自适应单向函数允许设置一个工作因子,随着硬件的改进而增加.建议将工作因子调整到系统中验证密码需要的约一秒的时间,可以让攻击者难以破解
  - BCrypt: springboot默认使用BCrypt加密算法
  - PBKDF2: 基于密码散列函数的密钥派生函数
  - scrypt: 基于Scrypt的密码散列函数
  - argon2: 基于Argon2的密码散列函数

```java
    @Bean
    public PasswordEncoder passwordEncoder() {
        return new BCryptPasswordEncoder(4);//可传入工作因子,4～31,默认10
    }
```

如果不指定加密器，那么在进行认证时会根据密码的前面标识{}来选择密码加密器进行对比，如果没有标识则会在认证时报错

## 3.OAuth2

OAuth2是一种授权协议,用于第三方应用获取用户数据

- 授权码模式: 客户端向第三方应用申请授权,第三方应用向用户申请授权,用户同意授权,第三方应用向客户端申请令牌,客户端向第三方应用申请资源

- 简化模式: 客户端向第三方应用申请授权,第三方应用向用户申请授权,用户同意授权,第三方应用向客户端颁发令牌,客户端向第三方应用申请资源

## 4. 自定义provider

如果你继承了`DaoAuthenticationProvider`并重写了其中的一个方法，然后希望Spring Security执行你自定义的Provider而不是默认的`DaoAuthenticationProvider`，你需要将你的自定义Provider注入到Spring Security配置中。以下是具体步骤：

1. **创建自定义的DaoAuthenticationProvider**：

    ```java
    import org.springframework.security.authentication.dao.DaoAuthenticationProvider;

    public class MyCustomDaoAuthenticationProvider extends DaoAuthenticationProvider {
        @Override
        protected void additionalAuthenticationChecks(UserDetails userDetails, UsernamePasswordAuthenticationToken authentication) throws AuthenticationException {
            // 自定义你的认证逻辑
            super.additionalAuthenticationChecks(userDetails, authentication);
        }
    }
    ```

2. **配置自定义的AuthenticationProvider**：

    你需要在Spring Security的配置类中将自定义的`DaoAuthenticationProvider`注册为Spring的bean，并配置`AuthenticationManagerBuilder`使用你的自定义Provider。

    ```java
    import org.springframework.beans.factory.annotation.Autowired;
    import org.springframework.context.annotation.Bean;
    import org.springframework.context.annotation.Configuration;
    import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
    import org.springframework.security.config.annotation.web.builders.HttpSecurity;
    import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
    import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
    import org.springframework.security.core.userdetails.UserDetailsService;

    @Configuration
    @EnableWebSecurity
    public class SecurityConfig extends WebSecurityConfigurerAdapter {

        @Autowired
        private UserDetailsService userDetailsService;

        @Bean
        public MyCustomDaoAuthenticationProvider myCustomDaoAuthenticationProvider() {
            MyCustomDaoAuthenticationProvider provider = new MyCustomDaoAuthenticationProvider();
            provider.setUserDetailsService(userDetailsService);
            // 其他必要的设置，例如密码编码器
            // provider.setPasswordEncoder(passwordEncoder());
            return provider;
        }

        @Override
        protected void configure(AuthenticationManagerBuilder auth) throws Exception {
            auth.authenticationProvider(myCustomDaoAuthenticationProvider());
        }

        @Override
        protected void configure(HttpSecurity http) throws Exception {
            http
                .authorizeRequests()
                .anyRequest().authenticated()
                .and()
                .formLogin()
                .and()
                .httpBasic();
        }
    }
    ```

在这个配置中：

- `myCustomDaoAuthenticationProvider`方法将自定义的`MyCustomDaoAuthenticationProvider`注册为一个Spring bean，并配置其依赖项（例如`UserDetailsService`和密码编码器）。
- 在`configure(AuthenticationManagerBuilder auth)`方法中，将自定义的`AuthenticationProvider`添加到`AuthenticationManagerBuilder`中。
- 通过这种方式，Spring Security将使用你的自定义`DaoAuthenticationProvider`来处理认证请求，而不是默认的`DaoAuthenticationProvider`。

这样配置后，当Spring Security处理认证请求时，它会使用你自定义的`MyCustomDaoAuthenticationProvider`，从而执行你重写的方法中的逻辑。

其中UserDetailsService必须配置
![alt text](<images/spring security/image-1.png>)
