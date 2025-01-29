#include <bits/stdc++.h>
using namespace std;

//初版
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> is_appear;
        int total=n;
        while(total!=1){
            string s=to_string(total);
            total=0;
            for(auto x:s){
                total+=(x-'0')*(x-'0');
            }
            if(!is_appear.insert(total).second) return false;
        }

        return true;
    }
};

//版本一
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> is_appear;
        while(n!=1){
            if(!is_appear.insert(n).second) return false;

            int new_n=0;
            while(n>0){
                new_n+=(n%10)*(n%10);
                n/=10;
            }
            n=new_n;
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isHappy(19) << endl;  // 输出: 1 (true)
    cout << sol.isHappy(2) << endl;   // 输出: 0 (false)
    return 0;
}