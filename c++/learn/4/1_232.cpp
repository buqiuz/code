#include<bits/stdc++.h>
using namespace std;

// 用栈实现队列
class MyQueue {
public:
    MyQueue() {
        _size=0;
    }
    
    void push(int x) {
        _s1.push(x);
        _size++; 
    }
    
    int pop() {
        if(_s2.empty()){
            while(!_s1.empty()){
                _s2.push(_s1.top());
                _s1.pop();
            }
        }

        int temp =_s2.top();
        _s2.pop();
        _size--;
        return temp;
    }
    
    int peek() {
        int ret = this->pop();
        _s2.push(ret);
        _size++;
        return ret;
    }
    
    bool empty() {
        return _size==0;
    }
private:
    stack<int> _s1,_s2;
    int _size;
};