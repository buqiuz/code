#include<bits/stdc++.h>
using namespace std;

//初版
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0;
        int right=s.size()-1;
        while(left<=right){
            swap(s[left++],s[right--]);
        }
    }
};

//版本一
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }
};