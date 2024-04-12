#include <iostream>
#include <vector>

std::vector<int> prime_factors(int n) {
    std::vector<int> factors;
    int i = 2;

    while (i * i <= n) {
        if (n % i == 0) {
            factors.push_back(i);
            n /= i;
        } else {
            i++;
        }
    }

    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}

int main() {
    // 读取输入
    int a;
    std::cin >> a;

    // 获取质因数列表
    std::vector<int> result = prime_factors(a);

    // 输出结果
    for (int i : result) {
        std::cout << i << " ";
    }

    return 0;
}
