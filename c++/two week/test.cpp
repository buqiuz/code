#include <iostream>

int hailstone(int n) {
    int count = 0;
    while (n != 1) {
        std::cout << n << " ";
        count++;
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
    }
    std::cout << 1 << std::endl;
    count++;
    return count;
}

int main() {
    int n;
    std::cout << "请输入一个大于1的整数n: ";
    std::cin >> n;

    if (n <= 1) {
        std::cout << "请输入大于1的整数。" << std::endl;
    } else {
        int count = hailstone(n);
        std::cout << "count = " << count << std::endl;
    }

    return 0;
}
