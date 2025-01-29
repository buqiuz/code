#include <bits/stdc++.h>
using namespace std;

//初版
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minFreq(26,INT32_MAX);
        for(auto &x: words){
            vector<int> freq(26,0);
            for(auto &w: x){
                freq[w-'a']++;
            }
            for (int i = 0; i < 26; i++) {
                minFreq[i] = min(minFreq[i], freq[i]);
            }
        }
        vector<string>  ret;
        for(int i=0;i<26;i++){
            for(int j=0;j<minFreq[i];j++){
                ret.push_back(string(1,i+'a'));
            }
        }
        return ret;
    }
};