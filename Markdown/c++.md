# c++学习

## nullptr关键字

>nullptr是一个空指针常量，用于替代传统的NULL或0。

### 优点

- 类型安全：nullptr有明确的类型std::nullptr_t，防止类型不匹配。
- 可读性：更清晰地表示空指针。

## lambda

```c++
[capture](parameters) -> return_type {
    // 函数体
};
```

1. [capture]（捕获列表）：
指定 Lambda 函数可以访问哪些外部变量。
2. (parameters)（参数列表）：
类似于普通函数的参数列表，指定 Lambda 函数接受哪些参数。
3. -> return_type（返回类型）（可选）：
指定 Lambda 函数的返回类型。通常可以省略，编译器会自动推导。
4. { // 函数体 }：
定义 Lambda 函数的具体实现。

### 捕获

#### 按值捕获或引用捕获

```c++
#include <iostream>

int main() {
    int a = 5;
    int b = 10;

    auto mixed1 = [a, &b]() {
        // a 是按值捕获，b 是按引用捕获
        std::cout << "a: " << a << ", b: " << b << std::endl;
    };

    auto mixed2 =[&](){};// Lambda 将捕获所有在 Lambda 内部使用的外部变量的引用。

    auto mixed3 = [=](){};//按值捕获,无法修改,默认会设为const,除非使用mutable

    a = 20;
    b = 30;

    mixed(); // 输出 a: 5, b: 30

    return 0;
}
```

#### 捕获this

```c++
#include <iostream>
#include <vector>
#include <algorithm>

class MyClass {
private:
    std::vector<int> data;
public:
    MyClass(std::vector<int> d) : data(d) {}

    void printAllGreaterThan(int threshold) const {
        std::for_each(data.begin(), data.end(), [this, threshold](int x) {
            if (x > threshold) {
                std::cout << x << " ";
            }
        });
        std::cout << std::endl;
    }
};

int main() {
    MyClass obj({1, 5, 10, 15, 20});
    obj.printAllGreaterThan(10); // 输出: 15 20

    return 0;
}
```

### 返回类型

>默认可以不显示声明,会进行自动推导,复杂返回类型可以声明

```c++
#include <iostream>
#include <vector>

int main() {
    auto createVector = []() -> std::vector<int> {
        return {1, 2, 3, 4, 5};
    };

    std::vector<int> vec = createVector();
    for(auto num : vec) {
        std::cout << num << " "; // 输出: 1 2 3 4 5
    }
    std::cout << std::endl;

    return 0;
}
```

## char和int

>在内存中char的存储是存储的1字节的ASCII值

```c++
#include<iostream>
using namespace std;
int main()
{
    char a='a';
    cout<<(int)(a-32)<<endl;
   return 0;
}
```

## class

### 使用初始化列表初始化

```c++
class MyClass {
public:
    MyClass() : b(2), a(1) {}
private:
    int a;
    int b;
};
```

>即使初始化列表中`b`在前，`a`在后，成员变量的初始化顺序仍然是先`a`后`b`。

### 多态

```c++
class Base {
public:
    virtual void display();
};

class Derived : public Base {
public:
    void display() override;
};
```

#### 纯虚函数

```c++
class Shape {
public:
    virtual double area() const = 0; // 纯虚函数
};
```

1. `= 0;`:包含纯虚函数的类成为抽象类，不能被实例化。
2. 基类不提供该函数的具体实现，强制要求所有派生类必须实现该函数。
3. 在类中，const 可以用于成员函数，表示该函数不会修改对象的成员变量。这在保证对象状态不被意外修改时非常有用。

## 正则表达式匹配

>在C++中使用正则表达式的注意事项

1. 字符串转义问题

    - 在C++中，反斜杠\是转义字符，需要进行双重转义。因此，正则表达式中的反斜杠需要写成\\。
    - 示例：正则表达式\d+在C++中应写为"\\d+"。

2. 使用原始字符串字面量

    - 为了避免频繁的转义，可以使用C++11引入的原始字符串字面量（Raw String Literals），通过R"()"语法包裹正则表达式。
    - 示例：正则表达式\d+使用原始字符串字面量写为R"(\d+)"。

### `std::regex`

>std::regex是正则表达式的核心类，用于存储和管理正则表达式模式。

```c++
#include <regex>
#include <string>

int main() {
    std::string pattern = "^\\w+@\\w+\\.com$";
    std::regex expr(pattern); // 使用字符串构造正则表达式
    return 0;
}
```

### `std::regex_match`

>用于判断整个字符串是否完全匹配正则表达式。

```c++
#include <regex>
#include <string>
#include <iostream>

int main() {
    std::string str = "user@example.com";
    std::regex expr("^\\w+@\\w+\\.com$");

    if (std::regex_match(str, expr)) {
        std::cout << "完全匹配！" << std::endl;
    } else {
        std::cout << "不匹配。" << std::endl;
    }

    return 0;
}
```

### `std::regex_search`

>用于在字符串中搜索是否存在匹配的子串。

```c++
#include <regex>
#include <string>
#include <iostream>

int main() {
    std::string str = "Contact us at support@example.com for more info.";
    std::regex expr("\\w+@\\w+\\.com");
    std::smatch matches;

    if (std::regex_search(str, matches, expr)) {
        std::cout << "找到匹配的邮箱: " << matches[0] << std::endl;
    } else {
        std::cout << "未找到匹配的邮箱。" << std::endl;
    }

    return 0;
}
```

### `std::regex_replace`

>用于在字符串中替换匹配的子串。

```c++
#include <regex>
#include <string>
#include <iostream>

int main() {
    std::string str = "Hello, user@example.com!";
    std::regex expr("(\\w+)@(\\w+)\\.com");
    std::string replacement = "$1@newdomain.com";

    std::string result = std::regex_replace(str, expr, replacement);
    std::cout << "替换后的字符串: " << result << std::endl;

    return 0;
}
```

### `std::sregex_iterator`

>用于遍历字符串中所有匹配的子串。

```c++
#include <regex>
#include <string>
#include <iostream>

int main() {
    std::string str = "Contact us at support@example.com for more info. buqiu@qq.com";
    std::regex expr("\\w+@\\w+\\.com");

    // 使用 sregex_iterator 遍历所有匹配项
    auto begin = std::sregex_iterator(str.begin(), str.end(), expr);
    auto end = std::sregex_iterator();

    if (begin == end) {
        std::cout << "未找到匹配的邮箱。" << std::endl;
    } else {
        for (auto it = begin; it != end; ++it) {
            std::cout << it->str() << std::endl;
        }
    }

    return 0;
}
```

## 获取输入的方法

### `std::cin`

>`std::cin` 是C++中最基本的输入流，用于从标准输入（通常是键盘）读取数据。提取运算符 (`>>`) 用于从输入流中提取数据并存储到变量中。

- std::cin 默认以空白字符（空格、换行等）作为分隔符。

### `std::cin.get()`

>std::cin.get() 可以逐个字符读取输入，包括空格和换行符。适用于需要逐字符处理输入的场景。

### `std::getline`

>std::getline 用于读取一整行的输入，包括空格，直到遇到换行符为止。适用于读取包含空格的字符串。

```c++
#include <iostream>
#include <string>

int main() {
    std::string fullName;
    int age;

    std::cout << "请输入您的全名：";
    std::getline(std::cin, fullName);

    std::cout << "请输入您的年龄：";
    std::cin >> age;

    std::cout << "姓名: " << fullName << "\n年龄: " << age << std::endl;
    return 0;
}
```

- 如果在使用 `std::cin >>` 之后立即使用 std::getline，可能会遇到跳过输入的问题，因为前一个输入操作可能会留下换行符在输入缓冲区。可以使用 `std::cin.ignore()` 来清除缓冲区。

### `std::cin.ignore()`

>cin.ignore() 函数用于从输入缓冲区中忽略（跳过）指定数量的字符，或直到遇到指定的分隔符为止。

- `cin.ignore();`:默认情况下，它会忽略下一个字符。
- `cin.ignore(numeric_limit<std::streamsize>::max(), '\n');`:这个版本允许你指定要忽略的最大字符数以及一个可选的终止字符。

## 格式化输出

>iomanip

### `setw`

>`setw` 可以设置输出的宽度。

```c++
#include <iostream>
#include <iomanip>  // 包含操作符的头文件

int main() {
    std::cout << std::setw(10) << 123 << std::endl;
    std::cout << std::setw(10) << 45 << std::endl;
    return 0;
}
```

### `setprecision`

>`setprecision` 用于控制浮点数的小数位数。

```c++
#include <iostream>
#include <iomanip>

int main() {
    double num = 3.1415926535;
    std::cout << std::setprecision(3) << num << std::endl;
    return 0;
}
```

### `fixed` 和 `scientific`

>fixed 以定点方式输出浮点数
>scientific 以科学计数法输出浮点数。

```c++
#include <iostream>
#include <iomanip>

int main() {
    double num = 12345.6789;
    std::cout << std::fixed << num << std::endl;      // 定点表示
    std::cout << std::scientific << num << std::endl; // 科学计数法
    return 0;
}
```

### `left` 和 `right`

>left：左对齐
>right：右对齐

```c++
#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::left << std::setw(10) << 123 << std::endl;
    std::cout << std::right << std::setw(10) << 123 << std::endl;
    return 0;
}
```

### `setfill`

>可以使用 setfill 来指定宽度不足时填充的字符。

```c++
#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::setfill('*') << std::setw(10) << 123 << std::endl;
    return 0;
}
```

### 进制转换

#### `dec`和`oct`和`hex`

>十进制(默认),8进制,16进制

```c++
#include <iostream>
using namespace std;
int main() {
    int num = 255;

    cout << "十进制：" << dec << num << endl;  // 十进制
    cout << "八进制：" << oct << num << endl;  // 八进制
    cout << "十六进制：" << hex << num << endl; // 十六进制

    return 0;
}
```

#### 手动转换

```c++
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
```

## STL

### `std::transform`

#### 单输入范围的 `std::transform` 示例

```c++
#include <iostream>
#include <vector>
#include <algorithm>  // std::transform
#include <iterator>   // std::back_inserter

using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    vector<int> squares;

    // 使用 std::transform 对 numbers 的每个元素求平方并存入 squares
    transform(numbers.begin(), numbers.end(), back_inserter(squares),
              [](int x) { return x * x; });

    // 输出结果
    cout << "Squared values: ";
    for (int x : squares) {
        cout << x << " ";
    }

    return 0;
}
```

#### 双输入范围的 `std::transform` 示例

```c++
#include <iostream>
#include <vector>
#include <algorithm>  // std::transform
#include <iterator>   // std::back_inserter

using namespace std;

int main() {
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> vec2 = {10, 20, 30, 40, 50};
    vector<int> result;

    // 使用 std::transform 将 vec1 和 vec2 的元素相加
    transform(vec1.begin(), vec1.end(), vec2.begin(), back_inserter(result),
              [](int x, int y) { return x + y; });

    // 输出结果
    cout << "Summed values: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
```

#### 示例

```c++
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// 自定义结构体存储字母及其出现次数
struct CharCount {
    char ch;
    int count;
};

int main() {
    string str;
    cout << "请输入一个字符串: ";
    cin >> str;

    // 使用 unordered_map 统计每个字母出现的次数
    unordered_map<char, int> countMap;
    for (char ch : str) {
        if (isalpha(ch)) {
            ch = tolower(ch);  // 统一转换为小写字母
            countMap[ch]++;
        }
    }

    // 使用 std::transform 将 unordered_map 中的统计结果转换为 vector<CharCount>
    vector<CharCount> countVec;
    countVec.reserve(countMap.size());  // 提前为 vector 分配足够的空间
    transform(countMap.begin(), countMap.end(), back_inserter(countVec),
              [](const pair<char, int>& p) {
                  return CharCount{p.first, p.second};  // 转换为 CharCount 结构体
              });

    // 输出结果
    cout << "字母及出现次数:\n";
    for (const auto& item : countVec) {
        cout << item.ch << ": " << item.count << endl;
    }

    return 0;
}
```

>其中`return CharCount{p.first, p.second};`  // 转换为 CharCount 结构体
struct可以通过列表初始化即聚合初始化,会按照声明的顺序进行赋值

### std::accumulate

```c++
#include <iostream>
#include <vector>
#include <numeric>  // std::accumulate
#include <string>

int main() {
    std::vector<std::string> words = {"Hello", "World", "from", "C++"};

    // 使用 accumulate 进行字符串连接
    std::string sentence = std::accumulate(words.begin(), words.end(), std::string(""), 
                                           [](const std::string& a, const std::string& b) {
                                               return a.empty() ? b : a + " " + b;
                                           });

    std::cout << "Sentence: " << sentence << std::endl;
    return 0;
}
```

>其中std::string("")是初始值,const std::string& a是前一次操作的值,const std::string& b是遍历出来的新值

### 类似流操作

>c++可以使用 STL 算法（`std::transform`, `std::copy_if` 等）

#### 1. `std::transform`：对每个元素进行转换

>`std::transform` 算法用于对容器中的每个元素执行某种操作，并将结果存储到另一个容器中。可以看作是 Java 中的 map 操作。

```c++
#include <iostream>
#include <vector>
#include <algorithm>  // std::transform

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> squares;

    // 使用 transform 对每个元素进行平方操作，并存入 squares 容器
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(squares), [](int x) {
        return x * x;
    });

    // 输出结果
    std::cout << "Squares: ";
    for (int n : squares) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

#### 2. `std::copy_if`：条件拷贝

>std::copy_if 用于根据条件将输入范围中的元素复制到另一个容器中。可以看作是 Java 中的 filter 操作。

```c++
#include <iostream>
#include <vector>
#include <algorithm>  // std::copy_if

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
    std::vector<int> evenNumbers;

    // 使用 copy_if 过滤偶数并存入 evenNumbers 容器
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evenNumbers), [](int x) {
        return x % 2 == 0;
    });

    // 输出结果
    std::cout << "Even numbers: ";
    for (int n : evenNumbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

#### 3. `std::accumulate`：累积操作（常用于求和、积等）

>std::accumulate 用于累积一个范围内的所有元素，通常用于求和或进行其他二元操作。

```c++
#include <iostream>
#include <vector>
#include <numeric>  // std::accumulate

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 使用 accumulate 求和
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    // 输出结果
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
```
