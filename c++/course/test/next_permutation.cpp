#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3};

    // 生成下一个排列并输出
    do {
        for (int num : nums) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    } while (std::next_permutation(nums.begin(), nums.end()));

    return 0;
}
