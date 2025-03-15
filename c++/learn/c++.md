# 学习笔记

## 问题

```c++
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v(3,0);
    int a=-1;
    if (a > v.size())
        cout<<a<<" is greater than v.size()"<<endl;
    else
        cout<<a<<" is not greater than v.size()"<<endl;
    return 0;
}
```

**假如a小于0,则会出现比较错误,因为编译器会进行隐式转换.size_t 是 无符号整数，-1 在转换为 size_t 时会变成一个非常大的正数（通常是 2^64 - 1 或 2^32 - 1，取决于系统的 size_t 宽度）。**

## 编码样式

- Format On Paste ：true
- Format On Save ：true
- C_Cpp: Clang_format_style ：file
- 在项目根目录下添加.clang-format文件，然后自定义配置

## 代码片段

- `Ctrl+Shift+P`
- `Preferences: Configure User Snippets`
- 新建代码片段文件

## c++11(智能指针)  :待学习

## c++20(ranges::view)  :待学习

## priority_queue

> `compare(a,b)==true`表示a的优先级比b低，也就是a离队顶更远。

```c++
auto cmp = [](const pair<int,int>& a,const pair<int,int>& b){
    return a.second<b.second;  //也就是为true时，a排在b后面;
};

priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(v.begin(),v.end(),cmp);
```

## tree

> 后续遍历的返回值自带回溯,也就是可以从一棵树自底向上进行操作

## 贪心法

>局部最优--->全局最优

- 只适用于能这样推导的问题
- 每一步只选择当前最优解,不回溯,不重新考虑已做出的选择
- 不保证能找到全局最优

## 动态规划

>一个问题可以分解为若干个子问题,通过保存子问题的结果避免重复计算

- 保证找到全局最优解
- 隐式回溯
- 每一个状态是由上一个状态推到而出

### 背包问题

>遍历顺序(都是指一维数组)

- 01背包,因为不存在重复使用,所以没有所谓的排列和组合问题
逆序更新容量时，当前物品的状态不会被后续容量重复利用，避免多次选择同一物品。

- 完全背包
正序遍历，会导致同一物品被多次选择。

- 先物品,后背包,是组合问题:
状态转移路径被限制为“按物品顺序逐步扩展”，类似“先使用物品1，再使用物品2”。
约束：不允许在物品2处理后，再回头用物品1生成新状态（避免重复组合）。

- 先背包,后物品,是排列问题:
状态转移路径允许“在任意容量下使用任何物品”，类似“先用物品1或物品2都可以”。
约束解除：允许不同顺序的路径生成不同状态（即排列）。

## 图论

### 构建图

> 如果是数字，则直接构建：如果是其他的节点，类似string，则先用vector存储下来，用vector的下标当节点，然后再双重循环构建图

- 广搜：找最短路径适合，只找一条就行
- 深搜：所有可能

>如果是稠密图，也就是节点从0-n，则可以用`vector<vector<int>>` 来构建,如果是稀疏图,也就是节点零散,则用`unordered_map<int,vector<int>>` 来构建
>其中int可以替换为自定义数据结构，比如不仅要存储下一个节点，还要存储这条边的权重，则用`pair<int,int>`

- 详细查看11——29_127__.cpp,了解内存分配

| 适用场景           | DFS | BFS           |
| ------------------ | --- | ------------- |
| 需要遍历所有可能解 | ✅   | ❌             |
| 需要找到最优解     | ❌   | ✅（最短路径） |
| 适合递归实现       | ✅   | ❌             |
| 适合队列结构       | ❌   | ✅             |
| 适合剪枝优化       | ✅   | ❌             |
| 适用于层次遍历     | ❌   | ✅             |

> dfs的两种写法
> 建议用第二种,因为bfs跟第二种相似,都是先标记再push

```c++
// 写法一：dfs 处理当前访问的节点
#include <iostream>
#include <vector>
#include <list>
using namespace std;

void dfs(const vector<list<int>>& graph, int key, vector<bool>& visited) {
    if (visited[key]) {
        return;
    }
    visited[key] = true;
    list<int> keys = graph[key];
    for (int key : keys) {
        // 深度优先搜索遍历
        dfs(graph, key, visited);
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m;

    // 节点编号从1到n，所以申请 n+1 这么大的数组
    vector<list<int>> graph(n + 1); // 邻接表
    while (m--) {
        cin >> s >> t;
        // 使用邻接表 ，表示 s -> t 是相连的
        graph[s].push_back(t);
    }
    vector<bool> visited(n + 1, false);
    dfs(graph, 1, visited);
    //检查是否都访问到了
    for (int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}
```

```c++
写法二：dfs处理下一个要访问的节点
#include <iostream>
#include <vector>
#include <list>
using namespace std;

void dfs(const vector<list<int>>& graph, int key, vector<bool>& visited) {
    list<int> keys = graph[key];
    for (int key : keys) {
        if (visited[key] == false) { // 确认下一个是没访问过的节点
            visited[key] = true;
            dfs(graph, key, visited);
        }
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m;

    vector<list<int>> graph(n + 1);
    while (m--) {
        cin >> s >> t;
        graph[s].push_back(t);

    }
    vector<bool> visited(n + 1, false);

    visited[1] = true; // 节点1 预先处理
    dfs(graph, 1, visited);

    for (int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}
```

```c++
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

int main() {
    int n, m, s, t;
    cin >> n >> m;

    vector<list<int>> graph(n + 1);
    while (m--) {
        cin >> s >> t;
        graph[s].push_back(t);

    }
    vector<bool> visited(n + 1, false);
    visited[1] = true; //  1 号房间开始
    queue<int> que;
    que.push(1); //  1 号房间开始

    // 广度优先搜索的过程
    while (!que.empty()) {
        int key = que.front(); que.pop();
         list<int> keys = graph[key];
         for (int key : keys) {
             if (!visited[key]) {
                visited[key] = true;
                que.push(key);
             }
         }
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}
```

### 最短路径

- `dijkstra`: 基于贪心，当访问了一个节点后，就确定该节点为最短路径，不再更新，所以要用`visited`数组，时间复杂度低   优先级队列来支持贪心，若不用visited，则退化为`SPFA`
  - `11_23_47_.cpp`
- `bellman-ford`： `SPFA`:访问节点时，若是当前节点被更新过，就尝试更新它所连接的所有节点，一旦某节点被更新，就加入队列，直到队列为空，这种可以回头更新的算法，支持负权值。但是出现环时，会死循环，所以要进行检测，检测当前节点的更新次数小于节点数量，一旦大于，则有环。或者直接使用`bellman-ford`算法，进行v-1次更新（若是某一次循环中未进行更新，则可以提前终止），然后进行第v次（若提前终止，则无环，不必进行这一次更新）更新，假如还有dist小于当前的dist，则有环。
  - `11_24_94_.cpp`:非`SPFA`，但提前退出,然后可以判断负环路，且可以可用作单源有限最短路径的求解
  - `11_25_94_.cpp`:`SPAF`+判断负环+提前退出
- `astar`:f=g+h

## roadmap

### Data Types

**c++是static type的语言，类型在编译时就确定,类型错误会导致编译失败**。

但他也支持一定的动态类型能力

- RTTI(运行时类型识别):允许在 运行时 获取对象的真实类型，用于多态对象的类型检查和转换。
  - RTTI 依赖虚表（vtable）:所以需要虚函数
- dynamic_cast 进行向下转换:即将基类指针或引用转换为派生类指针或引用。
  - 需要使用RTTI，以确保向下转换是安全的
- typeid 识别对象类型:允许在运行时获取对象的类型信息
- std::any:（C++17）支持存储任意类型:提供了一种类型安全的方式存储任意类型的值，类似于 Python 或 JavaScript 的动态变量。
- std::variant（C++17）支持类型安全的变体:是一种类型安全的联合体，可存储 多个类型中的一种，比 std::any 更高效。

### Scope

- `Global scope`:全局变量
- `Local scope`:函数内变量
- `Namespace scope`：用`::`
- `Class scope`:for static,using `::`,for non-static,using `->`

### Forward Declaration

>拥有分离的declaration和definition，所以可以先声明，后定义

- `Class Forward Declaration`
- `Function Forward Declaration`

### using

在c++中，用using代替typedef.

- `using namespace`: `using namespace std;`
- `using std::endl;`
- `using Int = int;`

### extern

>extern 关键字用于声明一个全局变量或对象，但不在当前文件分配存储空间。

- 在多个文件中共享变量或对象（避免重复定义）。
- 告诉编译器变量的定义在别的地方（通常是某个库或另一个源文件）。

比如在`iostream`中,就定义了

```c++
  extern istream cin;/// Linked to standard input
  extern ostream cout;/// Linked to standard output
  extern ostream cerr;/// Linked to standard error (unbuffered)
  extern ostream clog;/// Linked to standard error (buffered)
```

避免多个cpp文件引用iostream时出现cin,cout的重复定义,真正的定义在其标准库实现中

```c++
// ✅ 头文件 iostream
namespace std {
    extern ostream cout;  // 这里只是声明
}

// ✅ 标准库的实现文件
namespace std {
    ostream cout;  // 这里只定义一次
}
```

**所以extern实现了跨文件共享同一个全局变量**。

### Include Guard

- #ifndef / #define / #endif:防止头文件被多次包含，避免重复定义错误。
- #ifdef / #ifndef:判断一个宏是否被定义，然后决定是否编译

```c++
// File: myheader.h
#ifndef MYHEADER_H  // 如果 MYHEADER_H 没有定义
#define MYHEADER_H  // 定义 MYHEADER_H，防止重复包含

int globalVar = 10;

#endif  // 结束 ifndef

//File: main.cpp
#include "myheader.h"
#include "myheader.h"  // ✅ 这次不会重复包含

int main() {
    return globalVar;
}
```

因为 MYHEADER_H 在第一次包含时已经定义，第二次 #include 时 #ifndef 失败，头文件不会重复解析。避免了`globalVar`的重复定义

```c++
#ifdef _GLIBCXX_USE_WCHAR_T
  extern wistream wcin;    /// 宽字符标准输入
  extern wostream wcout;   /// 宽字符标准输出
  extern wostream wcerr;   /// 宽字符标准错误（非缓冲）
  extern wostream wclog;   /// 宽字符标准错误（缓冲）
#endif
```

_GLIBCXX_USE_WCHAR_T 是一个 宏，用于判断是否支持 wchar_t（宽字符类型）。

### Rule of Zero, Five, Three

>管理object resources

- Rule of Zero:假如一个类没有管理资源，那么就不必实现

  ```c++
  struct MyResource {
      std::string name;
      int value;
  };
  ```

- Rule of Three:假如一个类管理了资源，那么就必须要实现构造函数，拷贝构造函数，=运算符

  ```c++
  class MyResource {
  public:
      // Constructor and destructor
      MyResource() : data(new int[100]) {} 
      ~MyResource() { delete[] data; } 

      // Copy constructor
      MyResource(const MyResource& other) : data(new int[100]) {
          std::copy(other.data, other.data + 100, data);
      }

      // Copy assignment operator
      MyResource& operator=(const MyResource& other) {
          if (&other == this) { return *this; }
          std::copy(other.data, other.data + 100, data);
          return *this;
      }

  private:
      int* data;
  };
  ```

- Rule of Five:现代c++推荐要实现move构造函数和move =运算符

  ```c++
  class MyResource {
  public:
      // Constructors and destructor
      MyResource() : data(new int[100]) {}
      ~MyResource() { delete[] data; }

      // Copy constructor
      MyResource(const MyResource& other) : data(new int[100]) {
          std::copy(other.data, other.data + 100, data);
      }

      // Copy assignment operator
      MyResource& operator=(const MyResource& other) {
          if (&other == this) { return *this; }
          std::copy(other.data, other.data + 100, data);
          return *this;
      }

      // Move constructor
      MyResource(MyResource&& other) noexcept : data(other.data) {
          other.data = nullptr;
      }

      // Move assignment operator
      MyResource& operator=(MyResource&& other) noexcept {
          if (&other == this) { return *this; }
          delete[] data;
          data = other.data;
          other.data = nullptr;
          return *this;
      }

  private:
      int* data;
  };
  ```
