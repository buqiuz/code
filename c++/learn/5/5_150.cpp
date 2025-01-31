#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto &x : tokens) {
            if (x == "+" || x == "-" || x == "*" || x == "/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                if (x == "+") st.push(b + a);
                else if (x == "-") st.push(b - a);
                else if (x == "*") st.push(b * a);
                else st.push(b / a);
            } else {
                st.push(stoi(x));  // 直接转换，支持负数
            }
        }
        return st.top();
    }
};
