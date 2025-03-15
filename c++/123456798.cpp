#include <iostream>
#include <thread>

class Base {
public:
    static void run(int x) {
        std::cout << x << std::endl;
    }
};

int main() {
    std::thread t(&Base::run, 10);
    t.join();
    return 0;
}
