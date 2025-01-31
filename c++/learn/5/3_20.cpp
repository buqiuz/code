#include<bits/stdc++.h>
using namespace std;

//初版
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto x:s){
            switch(x){
                case '(': 
                case '[': 
                case '{': 
                    stk.push(x);
                    break;
                case ')': 
                    if(!stk.empty()&&stk.top()=='(') stk.pop();
                    else return false;
                    break;
                case ']':
                    if(!stk.empty()&&stk.top()=='[') stk.pop();
                    else return false;
                    break;
                case '}': 
                    if(!stk.empty()&&stk.top()=='{') stk.pop();
                    else return false;
                    break;
                default:
                    return false;
            }
        }

        return stk.empty();
    }
};

//版本一  //会略慢(哈希冲突下会退化为O(n))，但是代码简洁
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> matching = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char ch : s) {
            // 如果是右括号，检查栈顶是否匹配
            if (matching.find(ch) != matching.end()) {
                if (stk.empty() || stk.top() != matching[ch]) {
                    return false;
                }
                stk.pop();  // 匹配成功，弹出栈顶
            }
            // 如果是左括号，压入栈中
            else {
                stk.push(ch);
            }
        }

        // 最后栈应该为空，如果不为空则说明有未匹配的左括号
        return stk.empty();
    }
};