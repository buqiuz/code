#include <iostream>
#include <vector>
#include <numeric>  // 包含 accumulate 函数所需的头文件


// 自定义的二元函数，用于累积元素的平方和
struct SquareSum {
    int operator()(int x, int y) const {
        return x + y * y;
    }
};

int func(int x,int y){
    return x+y*y;
}


int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 使用 accumulate 计算向量中元素的累积和
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    std::cout << "Sum of elements: " << sum << std::endl;





    std::vector<int> num = {1, 2, 3, 4, 5};
    // 使用 accumulate 计算向量中元素的平方和
    int sumOfSquares = std::accumulate(num.begin(), num.end(), 0, func);

    std::cout << "Sum of squares: " << sumOfSquares << std::endl;

    return 0;
}
