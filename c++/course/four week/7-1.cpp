#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        stack<char> st;
        stack<int> book;
        book.push(4);
        bool valid = true;  // 添加一个标志用于表示匹配状态
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '<' && book.top() >= 1) {
                st.push(s[j]);
                book.push(1);
            } else if (s[j] == '(' && book.top() >= 2) {
                st.push(s[j]);
                book.push(2);
            } else if (s[j] == '[' && book.top() >= 3) {
                st.push(s[j]);
                book.push(3);
            } else if (s[j] == '{' && book.top() >= 4) {
                st.push(s[j]);
                book.push(4);
            } else if (s[j] == ')' && !st.empty() && st.top() == '(') {
                st.pop();
                book.pop();
            } else if (s[j] == ']' && !st.empty() && st.top() == '[') {
                st.pop();
                book.pop();
            } else if (s[j] == '>' && !st.empty() && st.top() == '<') {
                st.pop();
                book.pop();
            } else if (s[j] == '}' && !st.empty() && st.top() == '{') {
                st.pop();
                book.pop();
            } else {
                valid = false;  // 如果出现非法字符，将 valid 标志设置为 false
                break;  // 提前跳出循环
            }
        }

        if (valid && st.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
