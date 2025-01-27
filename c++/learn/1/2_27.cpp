#include<bits/stdc++.h>
using namespace std;

//初版  一坨，不用研究
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j= nums.size()-1;
        int count = 0;
        while(i<=j){
            while(nums[i]!=val&&i<j) i++;
            while(nums[j]==val&&j>i) {
                j--;
                count++;
            }
            swap(nums[i],nums[j]);
            count++;
        }
        return nums.size()-count;
    }
};

//初版改进版   前后指针，性能最高，写操作最少，但边界条件要格外小心，很容易出错，不太推荐
class Solution {
public:
int removeElement(vector<int>& nums, int val) {
    int i = 0;
    int j = nums.size() - 1;

    while (i <= j) { // 注意：i <= j，防止漏处理中间的元素
        while (i <= j && nums[i] != val) {
            i++; // 找到左边需要移除的元素
        }
        while (i <= j && nums[j] == val) {
            j--; // 跳过右边已是目标值的元素
        }
        if (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    return i; // i 指向第一个不需要移除的位置，新数组长度为 i
}
};

// 版本一   两指针，慢指针记录有效元素，性能较好，写操作较少，推荐，（每次交换只能确保尾部全是val，
// 不能确保交换到前面的元素不是val，所以交换后i不++，因为还要判断i，而n要--，因为n已无需判断）
class Solution {
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
};

// 版本二  快慢指针，保留数组相对顺序，有较多无效的写操作
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow=0;
        for (int fast=0;fast<nums.size();fast++){
            if(nums[fast]!=val){
                nums[slow++]=nums[fast];
            }
        }
        return slow;
    }
};
