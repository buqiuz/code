#include <bits/stdc++.h>
using namespace std;

//初版
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> char_count;
        for(auto x:magazine){
            char_count[x]++;
        }

        for(auto x:ransomNote){
            if(char_count[x]--<1) return false;
        }
        return true;
    }
};

 
//版本二,
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        //add
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.length(); i++) {
            // 通过record数据记录 magazine里各个字符出现次数
            record[magazine[i]-'a'] ++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            // 遍历ransomNote，在record里对应的字符个数做--操作
            record[ransomNote[j]-'a']--;
            // 如果小于零说明ransomNote里出现的字符，magazine没有
            if(record[ransomNote[j]-'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};