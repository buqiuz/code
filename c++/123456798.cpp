#include<bits/stdc++.h>
using namespace std;

void show(string str){
    cout << "NO" << endl;

    if (str == "/*"||str == "("||str == "["||str == "{")
    {
        cout<<str<<"-?"<<endl;
    }
    if (str == "*/"||str == ")"||str == "]"||str == "}")
    {
        cout<<"?-"<<str<<endl;
    }
}
int main() {
    stack<string> s;
    char ch1, ch2;
    // 使用 cin.get() 来读取字符，包括回车符
    cin.get(ch1);
    cin.get(ch2);
    // 只读入直到检测到输入的某一行仅为".\n"
    while (!(ch1 == '.' && ch2 == '\n')) {
        // 处理入栈
        if (ch1 == '(' || ch1 == '[' || ch1 == '{') {
            s.push(string(1, ch1));
            ch1 = ch2;
            cin.get(ch2);  // 继续读取下一个字符
            continue;
        }

        if (ch1 == '/' && ch2 == '*') {
            s.push("/*");

            cin.get(ch1);
            cin.get(ch2);
            continue;
        }
        // 处理出栈
        if (ch1 == ')' || ch1 == ']' || ch1 == '}') {
            if (s.empty()) {
                show(string(1,ch1));
                return 0;  // 立即终止程序
            }
            if ((ch1 == ')' && s.top() == "(") ||
                (ch1 == ']' && s.top() == "[") ||
                (ch1 == '}' && s.top() == "{")) {
                s.pop();
  
                ch1 = ch2;
                cin.get(ch2);  // 继续读取下一个字符
                continue;
            }
            if (!s.empty())
                show(s.top());
            return 0;  // 立即终止程序
        }
        if (ch1 == '*' && ch2 == '/') {
            if (s.empty())
            {
                show("*/");
                return 0;
            }
            if (s.top() == "/*") {
                s.pop();
                cin.get(ch1);
                cin.get(ch2);
                continue;
            }

            show(s.top());
            return 0; 
        }
        // 继续读取下一个字符
        ch1 = ch2;
        cin.get(ch2);
    }
    // 最后检查栈是否为空
    if (s.empty()) {
        cout << "YES" << endl;
    } else {
        show(s.top());
    }
    return 0;
}
