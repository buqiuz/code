#include<bits/stdc++.h>
using namespace std;

//初版
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int> ret;
        for(auto x: nums){
            freq[x]++;
        }

        auto cmp = [](const pair<int,int>& a,const pair<int,int>& b){
            return a.second<b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(freq.begin(),freq.end(),cmp);

        for(int i=0;i<k;i++){
            ret.push_back(pq.top().first);
            pq.pop();
        }
        return ret;
    }
};

//利用双map(如果会pq的话，不如直接用pq)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {    
        map<int,int> m;
        multimap<int,int>n;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            n.insert(pair{it->second,it->first});
        }
        for(auto it=n.rbegin();k>0&&it!=n.rend();++it,k--)
        {
            res.push_back(it->second);
        }
        return res;
    }
};