#include <bits/stdc++.h>
using namespace std;


//初版
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        for(auto x:s){
            m[x]++;
        }

        for(auto x:t){
            m[x]--;
        }

        for(auto x:m){
            if(x.second!=0) return false;
        }
        return true;
    }
};


//版本一
class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26]{0};
        for(auto x:s){
            arr[x-'a']++;
        }

        for(auto x:t){
            arr[x-'a']--;
        }

        for(auto x:arr){
            if(x!=0) return false;
        }
        return true;
    }
};
