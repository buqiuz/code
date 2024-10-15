#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Test
{
    int a;
    int b;
};

// 将整数转换为指定进制的字符串表示
string toBase(int num, int base) {
    string result;
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // 用于表示不同进制的字符
    if (base < 2 || base > 36) return "Invalid Base";  // 支持的进制范围为 2 到 36

    // 处理数字
    while (num > 0) {
        result = digits[num % base] + result;
        num /= base;
    }

    return result.empty() ? "0" : result;  // 若结果为空，返回 "0"
}


int main() {
    Test t{1, 2};
    // 设置随机数生成器和分布
    // random_device rd;   // 非确定性随机数生成器
    // mt19937 gen(rd());  // 使用Mersenne Twister算法的随机数引擎


    // mt19937 gen(static_cast<unsigned int>(time(0)));  // 使用当前时间作为种子
    // uniform_int_distribution<> dis(1, 100); // 生成范围在[1, 100]的随机整数

    // int n = 1000; // 需要生成的随机数数量

    // unordered_map<int,int> m;
    // for (int i = 0; i < n; i++)
    // {
    //     m[dis(gen)]++;
    // }
    
    // vector<pair<int,int>> v(m.begin(),m.end());

    // sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){
    //     return a.second > b.second;
    // });

    // for_each(v.begin(),v.end(),[](pair<int,int> p){
    //     cout << p.first << " " << p.second << endl;
    // });


    // double num = 43.1415926535;
    // // cout <<setprecision(4) << num << endl;
    // cout.precision(3);
    // cout.fixed;
    // cout.width(10);
    // cout.right;
    // cout << fixed<<num << endl;

    int a =255;
    cout << toBase(a,8) << endl;



    // vector<int> v,ret;
    // vector<Test> ret;

    // 生成随机数并存入vector
    // for (int i = 0; i < n; ++i) {
    //     v.push_back(dis(gen));
    // }

    // 输出生成的随机数
    // cout << "生成的随机数: ";
    // for (const auto& num : v) {
    //     cout << num << " ";
    // }
    // cout << endl;

    // copy_if(v.begin(),v.end(),back_inserter(ret),[](int i){
    //     return i<50;
    // });

    // string str = accumulate(v.begin(),v.end(),string(""),[](string a,int b){
    //     return a+to_string(b);
    // });

    // long sum = accumulate(v.begin(),v.end(),0);

    // transform(v.begin(), v.end(), back_inserter(ret), [](int i)  { return Test{i,i*2}; });
    
    // cout << "转换后的随机数: ";
    // cout << sum << endl;
    // for_each(ret.begin(), ret.end(), [](int i) { cout << i << " "; });
    return 0;
}


