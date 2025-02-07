#include<bits/stdc++.h>
using namespace std;

//遍历饼干
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.empty()) return 0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int index =0;
        for(int i=0;i<s.size();i++){
            if(index<g.size() && s[i]>=g[index]) index++;
        }
        return index;
    }
};