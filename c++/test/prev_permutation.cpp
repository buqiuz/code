#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> nums = {3, 2, 1};

    // 生成前一个排列并输出
    do {
        for (int num : nums) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    } while (std::prev_permutation(nums.begin(), nums.end()));

    return 0;
}
