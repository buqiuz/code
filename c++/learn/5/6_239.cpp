#include<bits/stdc++.h>
using namespace std;

//初版
class Solution {
public:
    class MyQueue{
    public:
        void push(int val){
            while(!_dq.empty() && _dq.back()<val) _dq.pop_back();
            _dq.push_back(val);
        }
        void pop(int val){
            if(_dq.front()==val) _dq.pop_front(); 
        }

        int front(){
            return _dq.front();
        }
    private:
        deque<int> _dq;
    };
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue q;
        vector<int> ret;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
            if(i>=k) q.pop(nums[i-k]);
            if(i>=k-1) ret.push_back(q.front());
        }
        return ret;
    }
};
