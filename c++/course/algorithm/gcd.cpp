#include <iostream>

// 求最大公约数的函数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;   //b是余数，若a小于b，则开始时会交换一次位置，然后直到余数b=0，返回a
        b = a % b;
        a = temp;
    }
    return a;
}
// int gcd(int x, int y)
// {	
// 	int z = y;
// 	while(x%y!=0)
// 	{
// 		z = x%y;
// 		x = y;
// 		y = z;	
// 	}
// 	return z;
// }


// int gcd(int a,int b){
//     while (b!=0)
//     {
//         int temp=b;
//         b=a%b;
//         a=temp;
//     }
//     return a;
// }

int main() {
    int num1, num2;
    std::cout << "请输入两个非负整数：";
    std::cin >> num1 >> num2;

    if (num1 < 0 || num2 < 0) {
        std::cout << "输入的整数必须为非负整数。" << std::endl;
    } else {
        int result = gcd(num1, num2);
        std::cout << "它们的最大公约数是：" << result << std::endl;
    }

    return 0;
}
