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

