# 在 Spring Security 中，通过密码登录后颁发 JWT，并将 JWT 存入 Redis 缓存，可以按照以下步骤实现

1. **添加依赖**：确保在 `pom.xml` 文件中包含必要的依赖项。

    ```xml
    <!-- Spring Security -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-security</artifactId>
    </dependency>
    <!-- JWT -->
    <dependency>
        <groupId>io.jsonwebtoken</groupId>
        <artifactId>jjwt</artifactId>
        <version>0.9.1</version>
    </dependency>
    <!-- Redis -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-data-redis</artifactId>
    </dependency>
    ```

2. **配置 Redis**：在 `application.properties` 或 `application.yml` 中配置 Redis。

    ```properties
    spring.redis.host=localhost
    spring.redis.port=6379
    ```

3. **配置 Spring Security**：

    创建一个 `SecurityConfig` 类，配置 Spring Security。

    ```java
    import org.springframework.context.annotation.Bean;
    import org.springframework.context.annotation.Configuration;
    import org.springframework.security.config.annotation.web.builders.HttpSecurity;
    import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
    import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
    import org.springframework.security.core.userdetails.UserDetailsService;
    import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
    import org.springframework.security.crypto.password.PasswordEncoder;

    @Configuration
    @EnableWebSecurity
    public class SecurityConfig extends WebSecurityConfigurerAdapter {

        private final UserDetailsService userDetailsService;

        public SecurityConfig(UserDetailsService userDetailsService) {
            this.userDetailsService = userDetailsService;
        }

        @Override
        protected void configure(HttpSecurity http) throws Exception {
            http.csrf().disable()
                .authorizeRequests()
                .antMatchers("/login").permitAll()
                .anyRequest().authenticated()
                .and()
                .formLogin()
                .loginProcessingUrl("/login")
                .successHandler(jwtAuthenticationSuccessHandler());
        }

        @Bean
        public PasswordEncoder passwordEncoder() {
            return new BCryptPasswordEncoder();
        }

        @Bean
        public JwtAuthenticationSuccessHandler jwtAuthenticationSuccessHandler() {
            return new JwtAuthenticationSuccessHandler();
        }
    }
    ```

4. **创建 JWT 工具类**：

    ```java
    import io.jsonwebtoken.Jwts;
    import io.jsonwebtoken.SignatureAlgorithm;

    import java.util.Date;

    public class JwtUtil {

        private static final String SECRET_KEY = "your_secret_key";

        public static String generateToken(String username) {
            return Jwts.builder()
                    .setSubject(username)
                    .setIssuedAt(new Date())
                    .setExpiration(new Date(System.currentTimeMillis() + 3600000)) // 1 hour expiration
                    .signWith(SignatureAlgorithm.HS256, SECRET_KEY)
                    .compact();
        }
    }
    ```

5. **创建登录成功处理器**：

    ```java
    import org.springframework.data.redis.core.RedisTemplate;
    import org.springframework.security.core.Authentication;
    import org.springframework.security.web.authentication.AuthenticationSuccessHandler;
    import org.springframework.stereotype.Component;

    import javax.servlet.http.HttpServletRequest;
    import javax.servlet.http.HttpServletResponse;
    import java.io.IOException;

    @Component
    public class JwtAuthenticationSuccessHandler implements AuthenticationSuccessHandler {

        private final RedisTemplate<String, String> redisTemplate;

        public JwtAuthenticationSuccessHandler(RedisTemplate<String, String> redisTemplate) {
            this.redisTemplate = redisTemplate;
        }

        @Override
        public void onAuthenticationSuccess(HttpServletRequest request, HttpServletResponse response, Authentication authentication) throws IOException {
            String username = authentication.getName();
            String token = JwtUtil.generateToken(username);

            // 将 token 存入 Redis
            redisTemplate.opsForValue().set(username, token);

            // 返回 token 给客户端
            response.setContentType("application/json;charset=UTF-8");
            response.getWriter().write("{\"token\": \"" + token + "\"}");
        }
    }
    ```

6. **配置 RedisTemplate**：

    ```java
    import org.springframework.context.annotation.Bean;
    import org.springframework.context.annotation.Configuration;
    import org.springframework.data.redis.connection.RedisConnectionFactory;
    import org.springframework.data.redis.core.RedisTemplate;
    import org.springframework.data.redis.serializer.StringRedisSerializer;

    @Configuration
    public class RedisConfig {

        @Bean
        public RedisTemplate<String, String> redisTemplate(RedisConnectionFactory redisConnectionFactory) {
            RedisTemplate<String, String> template = new RedisTemplate<>();
            template.setConnectionFactory(redisConnectionFactory);
            template.setKeySerializer(new StringRedisSerializer());
            template.setValueSerializer(new StringRedisSerializer());
            return template;
        }
    }
    ```

通过以上步骤，就可以实现用户通过密码登录后颁发 JWT 并将 JWT 存入 Redis 缓存的功能。
