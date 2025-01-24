#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    std::vector<int> numbers = {5, 2, 9, 1, 5, 6, 0};
    
    // 部分排序向量，使得前三个元素按升序排列
    std::partial_sort(numbers.begin(), numbers.begin() + 3, numbers.end());
    
    // 打印向量以查看结果
    for (int num : numbers) {
        std::cout << num << " ";
    }

    // 使用 iter_swap 交换第一个元素和最后一个元素
    std::iter_swap(numbers.begin(), numbers.end() - 1);

    // 打印交换后的向量
    std::cout << "\nAfter iter_swap:\n";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    
    for (int num : numbers) {
        std::cout << num << " ";
    }
    return 0;
}
