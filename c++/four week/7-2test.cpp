#include<iostream>
using namespace std;
#include<stack>

int main() {
    stack<long long int> st;
    string s;
    long long int a, b;
    while (cin >> s) {
        if (s == "#") {
            break;
        } else if (s == "+") {
            if (st.size() < 2) {
                cout<<"Expression Error: "<<st.top()<<endl;
                return 0;
            }
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(a + b);
        } else if (s == "-") {
            if (st.size() < 2) {
                cout<<"Expression Error: "<<st.top()<<endl;
                return 0;
            }
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b - a);
        } else if (s == "*") {
            if (st.size() < 2) {
                cout<<"Expression Error: "<<st.top()<<endl;
                return 0;
            }
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(a * b);
        } else if (s == "/") {
            if (st.size() < 2) {
                cout<<"Expression Error: "<<st.top()<<endl;
                return 0;
            }
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            if (a == 0) {
                cout<<"Error: "<<b<<"/"<<a<<endl;
                return 0;
            }
            st.push(b / a);
        } else {
            st.push(stoll(s));
        }
    }
    if (st.size()==1) {
        cout << st.top() << endl;
    }else if(st.size()>1){
        cout<<"Expression Error: "<<st.top()<<endl;
        return 0;
    }

    return 0;
}
