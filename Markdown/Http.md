# Http

| 特性            | HTTP/1.1        | HTTP/2         | HTTP/3          |
|---------------|--------------|--------------|--------------|
| 传输协议        | TCP          | TCP          | QUIC (基于 UDP) |
| 连接方式        | 长连接         | 多路复用       | 多路复用 + 独立流  |
| 数据格式        | 文本          | 二进制制       | 二进制制       |
| Header 压缩    | 无           | HPACK       | QPACK       |
| 队头阻塞        | 存在 (应用层)  | 存在 (TCP 层)  | 无           |
| 握手延迟        | 高 (TCP + TLS) | 高 (TCP + TLS) | 低 (QUIC 0-RTT) |
| 安全性         | 需额外启用 HTTPS | 强制 HTTPS    | 内置 TLS 1.3    |
| 典型应用场景    | 传统 Web 服务  | 高并发、低延迟网站 | 移动网络、实时通信 |

## URL

![alt text](https://raw.githubusercontent.com/buqiuz/Images/main/image.png)

## sync & Async

- sync:同步顺序执行,遇到耗时操作会阻塞后续代码,可能造成程序假死或者页面卡顿
- Async:异步非顺序执行,遇到耗时操作不会阻塞后续代码,通过回调函数(回调地狱)或者promise的方式通知结果

### 原理

>JavaScript 的单线程模型

JavaScript 是单线程语言，意味着它只有一个主线程（Main Thread）负责执行代码。这种设计的初衷是为了简化 DOM 操作，避免多线程带来的竞态条件问题。但这也带来一个挑战：如何高效处理耗时操作（如网络请求、文件读写）而不阻塞主线程？

答案：通过 异步非阻塞 + 事件循环 机制。

JS的主线程是单线程的，但浏览器或Node.js环境提供了其他线程来处理耗时任务，比如Web Workers、I/O操作、定时器等。主线程负责执行同步代码和调度异步任务，而耗时操作由底层API或其他线程处理，完成后通过事件循环将回调放入任务队列，主线程在空闲时执行这些回调。

避免同步耗时操作：
将密集计算交给 Web Worker（浏览器）或 Worker Threads（Node.js），实现真正的多线程。
>核心组件

(1) 调用栈（Call Stack）

- 作用：存储函数调用的栈结构，按顺序执行同步代码。

(2) Web APIs（浏览器环境）/ C++ APIs（Node.js）

- 作用：处理异步操作（如 setTimeout、fetch、DOM 事件）。
- 规则：当调用栈遇到异步代码时，将其交给这些 API 处理，主线程继续执行后续代码。

(3) 任务队列（Task Queue）

- 作用：存储异步操作完成后的回调函数。
- 类型：分为 宏任务队列（Macrotask Queue） 和 微任务队列（Microtask Queue）。
- 宏任务：setTimeout、setInterval、I/O 操作、UI 渲染。
- 微任务：Promise.then()、MutationObserver、queueMicrotask()。

(4) 事件循环（Event Loop）

- 作用：持续检查调用栈是否为空，若为空则将任务队列中的回调推入调用栈执行。

- 流程：
  - 执行同步代码，填充调用栈。
  - 遇到异步代码，交给 Web APIs 处理。
  - 异步操作完成后，回调函数被推入任务队列。
  - 当调用栈为空时，事件循环按优先级处理队列：
  - 先清空所有微任务队列。
  - 再取出一个宏任务执行。
  - 重复此过程。

### promise

**Promise 有三种状态：**

- Pending（待定）：初始状态，既不是成功也不是失败。
- Fulfilled（已完成）：操作成功完成。
- Rejected（已拒绝）：操作失败。

**Promise 的基本用法**
创建一个 Promise 可以使用 new Promise() 构造函数，传入一个执行函数，这个函数有两个参数：resolve 和 reject。

```js
let myPromise = new Promise((resolve, reject) => {
    // 执行一些异步操作
    let success = true; // 假设这是操作的结果

    if (success) {
        resolve("操作成功!"); // 成功时调用 resolve
    } else {
        reject("操作失败!"); // 失败时调用 reject
    }
});
```

**Promise 的链式调用**
Promise 提供了 .then() 和 .catch() 方法来处理结果：
`.then()` 用于处理成功的结果。
`.catch()` 用于处理失败的结果。

```js
myPromise
    .then(result => {
        console.log(result); // "操作成功!"
    })
    .catch(error => {
        console.error(error); // 如果失败，打印错误信息
    });
```

---

```js
const response = await fetch('https://example.com/api'); // 第一步
const data = await response.json(); // 第二步
console.log(data); // 这里是最终解析出来的 JavaScript 对象
```

- `fetch('https://example.com/api')`:返回一个`Promise<Response>`
- `await fetch(url)` 解析 `Promise`，得到 `Response` 对象。
- `response.json()` 返回一个 `Promise`，因为解析 JSON 也是异步的。因为response可能会很大,这样会阻塞主进程
- `await response.json()` 解析 JSON，得到最终的 JavaScript 对象。

---

Response

| 属性 / 方法         | 说明                           | 示例 |
|--------------------|------------------------------|------|
| `resp.ok`         | 是否成功（`status` 在 200-299 之间） | `true` / `false` |
| `resp.status`     | HTTP 状态码                     | `200`、`404`、`500` |
| `resp.statusText` | 状态文本                        | `"OK"`、`"Not Found"` |
| `resp.headers`    | 响应头对象                      | `resp.headers.get('Content-Type')` |
| `resp.url`        | 最终获取数据的 URL              | `"https://example.com/api"` |
| `resp.body`       | 读取流的 `ReadableStream`       | 用于手动读取数据 |
| `resp.json()`     | 解析 JSON 数据（**异步方法**）  | `await resp.json()` |
| `resp.text()`     | 解析为文本（**异步方法**）      | `await resp.text()` |
| `resp.blob()`     | 解析为 `Blob`（**异步方法**）  | `await resp.blob()` |

---

then语法

```js
fetch('https://example.com/api') // 第一步
  .then(response => response.json()) // 第二步
  .then(data => { 
    console.log(data); // 这里是最终解析出来的 JavaScript 对象
  })
  .catch(error => {
    console.error('发生错误:', error);
  });
```
