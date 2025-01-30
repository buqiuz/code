#include<bits/stdc++.h>
using namespace std;
//初版
class Solution {
public:
    string reverseWords(string s) {
        string ret;
        int n=s.size();
        int right=n-1;

        while(right>=0){
            //去掉多余空格
            if(s[right]==' ') {
                right--;
                continue;
            }

            //找到下一个单词
            int left=right;
            while(left>=0&&s[left]!=' ') left--;

            //添加找到的单词
            if(!ret.empty()) ret+=' ';
            ret+=s.substr(left+1,right-left);

            //right前移
            right=left;
        }
        return ret;
    }
};