# 学习笔记

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
