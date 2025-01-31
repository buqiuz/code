#include<bits/stdc++.h>
using namespace std;
    
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int size=q.size();
        q.push(x);
        while(size--){
            int temp =q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
};
