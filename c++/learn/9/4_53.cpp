#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int ret = INT32_MIN;
        int sum = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            sum += nums[fast];
            if (sum > ret)
                ret = sum;
            if (sum < 0) {
                sum = 0;
            }
        }
        return ret;
    }
};