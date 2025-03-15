# java反射

## 1.简介

![alt text](https://raw.githubusercontent.com/buqiuz/Images/main/image.png)

## 2.获取class

1. `Class.forNmae("全类名")`：也是在运行时才能确定类型，通过这种方式获取的Class对象时，会立即触发类的初始化。
2. `类名.class`：在编译时就确定了具体的类，属于静态引用，使用这种方式获取类的class对象，不会触发类的初始化。只有你在访问类的静态实例或者创建该类的示例时才会触发。
3. `对象.getClass()`：在运行时从User实例获取，若要接收这个方法的返回值，则需要使用通配符`Class<?>`，因为在编译时无法确定对象的类型，会报错，这种方法通常用于类名在编译时不可知的场景中，如泛型函数

## 3.获取构造方法

1. `Class.getConstructor(参数类型)`:获取公共的构造方法
2. `Class.getConstructors()`获取所有公共的构造方法
3. `Class.getDeclaredConstructor(参数类型)`:获取构造方法
4. `Class.getDeclaredConstructors()`:获取所有的构造方法

>参数类型可以为String.class等等

### 3.1.获取修饰符

- `构造方法.getModifiers()`:获取修饰符

![alt text](https://raw.githubusercontent.com/buqiuz/Images/main/image-1.png)

### 3.2.获取参数

- `构造方法.getParameterTypes()`:获取参数
- `构造方法.getParameterCount()`:获取参数个数
- `构造方法.getParameters()`:获取所有参数

### 3.2.创建实例

- 若构造方法为私有的,则需要使用`构造方法.setAccessible(true)`
- `构造方法.newInstance(参数)`:创建实例,可以创建无参构造方法的实例

## 4.获取成员变量

- `getField(String name)`:获取单个公共的成员变量
- `getFields()`:获取所有公共的成员变量
- `getDeclaredField(String name)`:获取单个成员变量
- `getDeclaredFields()`:获取所有成员变量

### 4.1.设置可访问

- `成员变量.setAccessible(true)`:设置可访问

### 4.2.获取修饰符

- `成员变量.getModifiers()`:获取修饰符

### 4.3.获取类型

- `成员变量.getType()`:获取类型

### 4.4.获取名称

- `成员变量.getName()`:获取名称

### 4.4.获取值

- `成员变量.get(对象)`:获取值

### 4.5.设置值

- `成员变量.set(对象,值)`:设置值

## 5.获取成员方法

- `getMethod(String name,参数类型)`:获取单个公共的成员方法
- `getMethods()`:获取所有公共的成员方法,包含父类的方法
- `getDeclaredMethod(String name,参数类型)`:获取单个成员方法
  - `name`为方法名称,参数类型为`int.class`等等
- `getDeclaredMethods()`:获取所有成员方法,不包含父类的方法

### 5.1.设置可访问

- `成员方法.setAccessible(true)`:设置可访问

### 5.2.获取修饰符

- `成员方法.getModifiers()`:获取修饰符

### 5.3.获取返回类型

- `成员方法.getReturnType()`:获取返回类型

### 5.4.获取参数

- `成员方法.getParameterTypes()`:获取参数类型
- `成员方法.getParameterCount()`:获取参数个数
- `成员方法.getParameters()`:获取所有参数

### 5.5.获取名称

- `成员方法.getName()`:获取名称

### 5.6.方法运行

- `成员方法.invoke(对象,参数)`:方法运行
