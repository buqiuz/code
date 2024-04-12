#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

//当n出栈后，未出栈且小于n的所有元素必须按递减排列，因为进栈顺序是递增且有序的。

void show(const vector<int>& v){
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void func(stack<int> &s, vector<int> v){
    int i = 0;
    int j = 0;
    while (true)
    {
        if (!s.empty() && j < v.size() && s.top() == v[j]){
            s.pop();
            j++;
        }
        else {
            if (i >= v.size() || j >= v.size()) {
                break;
            }

            s.push(++i);
        }
    }
}

int main() {
    vector<int> v{4,3,2,1};
    show(v);
    stack<int> s;
    func(s, v);
    if (s.empty() ) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}