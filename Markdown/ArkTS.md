# ArkTS 学习

[ArkTS 官方文档](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/introduction-to-arkts-V5)

## 一些特性

- 由于ArkTS是一种静态类型语言，所有数据的类型都必须在编译时确定。

- 但是，如果一个变量或常量的声明包含了初始值，那么开发者就不需要显式指定其类型。ArkTS规范中列举了所有允许自动推断类型的场景。
- `===`为严格相等，`==`为非严格相等，`==`在比较数字时，会将数字转换为字符串再比较。
- `for-of`可用于遍历数组

## 函数

### 函数声明

```ts
function add(a: number, b: number): number {
  return a + b;
}
```

### 可选参数

```ts
function hello(name?: string) {
  if (name == undefined) {
    console.log('Hello!');
  } else {
    console.log(`Hello, ${name}!`);
  }
}
```

### 闭包

```ts
function f(): () => number {
  let count = 0;
  let g = (): number => { count++; return count; };
  return g;
}

let z = f();
z(); // 返回：1
z(); // 返回：2
```

- 其中`: () => number`为返回值类型,即匿名函数
- `let g = (): number => { count++; return count; };`为匿名函数，匿名函数的返回值类型为`number`
- 只要z函数存在，count就会一直存在，所以z函数的count值会累加
