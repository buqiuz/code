# Redis

## 1 Redis基础

### 1.1 NoSql

NoSQL是面向数据而不是关系数据库的，NoSQL的数据库没有固定的数据结构，数据可以是任何格式，可以是文本，也可以是二进制，NoSQL的数据库可以存储任意类型的数据

>即非结构化

### 1.2 特性

- 键值型
- 单线程,每个命令具备原子性
- 低延迟,速度快(基于内存,IO多路复用,良好的编码)
- 支持数据持久化
- 支持主从集群,分片集群

## 2 Redis安装

[Redis安装](https://www.bilibili.com/video/BV1rV411M7eU?p=4&spm_id_from=pageDriver&vd_source=e2bd36731c71838c269342f8ba7755d3)

## 3 Spring Redis

### 3.1 简介

- 其中提供了RedisTemplate工具类,其中封装了对Redis的各种操作。并且将不同数据类型的操作API封装到了不同类型中:

| API                           | 返回值类型         | 说明                         |
|-------------------------------|-------------------|------------------------------|
| redisTemplate.opsForValue()   | ValueOperations   | 操作String类型数据           |
| redisTemplate.opsForHash()    | HashOperations    | 操作Hash类型数据             |
| redisTemplate.opsForList()    | ListOperations    | 操作List类型数据             |
| redisTemplate.opsForSet()     | SetOperations     | 操作Set类型数据              |
| redisTemplate.opsForZSet()    | ZSetOperations    | 操作SortedSet类型数据        |
| redisTemplate                 |                   | 通用的命令                   |

### 3.2 配置

引入依赖

```xml
<!-- redis -->
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-data-redis</artifactId>
</dependency>
<!-- redis连接池依赖-->
<dependency>
    <groupId>org.apache.commons</groupId>
    <artifactId>commons-pool2</artifactId>
</dependency>
```

配置文件

>因为它默认是用jdk的序列化方式,可读性差且内存占用大

```java
@Bean
public RedisTemplate<String, Object> redisTemplate(RedisConnectionFactory redisConnectionFactory){
    //创建RedisTemplate对象
    RedisTemplate<String, Object> redisTemplate = new RedisTemplate<>();

    //设置连接工厂
    redisTemplate.setConnectionFactory(redisConnectionFactory);

    //创建Json序列化工具,基于Jackson,专为Redis设计,且jackson依赖由spring mvc 提供,即web依赖
    GenericJackson2JsonRedisSerializer jsonRedisSerializer = new GenericJackson2JsonRedisSerializer();

    //设置key序列化
    redisTemplate.setKeySerializer(RedisSerializer.string());
    redisTemplate.setHashKeySerializer(RedisSerializer.string());

    //设置value序列化
    redisTemplate.setValueSerializer(jsonRedisSerializer);
    redisTemplate.setHashValueSerializer(jsonRedisSerializer);

    return redisTemplate;
}
```
