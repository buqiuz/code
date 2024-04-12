#include <iostream>
#include <algorithm>
#include <vector>
#include<stack>
using namespace std;

int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        stack<char> s;
        stack<int> priority;
        string str;
        cin>>str;
        priority.push(4);   //1,2,3,4表示可以容纳的度，比如入栈<,则可容纳度就变为1；每次入栈前要考虑前一个符号的容纳度是否大于当前符号的度。
        int valid=1;
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j]=='<'&&priority.top()>=1)
            {
                s.push(str[j]);
                priority.push(1);
            }
            else if (str[j]=='('&&priority.top()>=2)
            {
                s.push(str[j]);
                priority.push(2);
            }
                        else if (str[j]=='['&&priority.top()>=3)
            {
                s.push(str[j]);
                priority.push(3);
            }
                        else if (str[j]=='{'&&priority.top()>=4)
            {
                s.push(str[j]);
                priority.push(4);
            }else if (str[j]=='>'&&!s.empty()&&s.top()=='<')
            {
                s.pop();
                priority.pop();
            }else if (str[j]==')'&&!s.empty()&&s.top()=='(')
            {
                s.pop();
                priority.pop();
            }else if (str[j]==']'&&!s.empty()&&s.top()=='[')
            {
                s.pop();
                priority.pop();
            }else if (str[j]=='}'&&!s.empty()&&s.top()=='{')
            {
                s.pop();
                priority.pop();
            }else{
                valid=0;
                break;
            }
            
        }
        if (s.empty()&&valid)
        {
            cout<<"YES"<<endl;
        }else
        cout<<"NO"<<endl;
        
    }

    

    
    
    return 0;
}
