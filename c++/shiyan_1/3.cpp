#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
string s;
        cin >> s;
        stack<char> st;

        bool valid = true;  // 添加一个标志用于表示匹配状态
        for (int j = 0; j < s.size(); j++) {
             if (s[j] == '(' ) {
                st.push(s[j]);

            } else if (s[j] == '[' ) {
                st.push(s[j]);

             
            } else if (s[j] == ')' && !st.empty() && st.top() == '(') {
                st.pop();

            } else if (s[j] == ']' && !st.empty() && st.top() == '[') {
                st.pop();

            }   else {
                valid = false;  // 如果出现非法字符，将 valid 标志设置为 false
                break;  // 提前跳出循环
            }
        }

        if (valid && st.empty()) {
            cout << "OK" << endl;
        } else {
            cout << "Wrong" << endl;
        }

    return 0;
}
