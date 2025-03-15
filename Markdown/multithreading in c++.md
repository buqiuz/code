# multithreading

## create threads

- function pointer

  - ```c++
    void fun(int x) {
        std::cout << x << std::endl;
    }
    
    int main() {
        std::thread t(fun, 10);
        t.join();
        return 0;
    }
    ```

- lambda expression

  - ```c++
    int main() {
        std::thread t([](int x) {
            std::cout << x << std::endl;
        }, 10);
        t.join();
        return 0;
    }
    
    ```

- functor (function object)

  - ```c++
    class Base {
    public:
        void operator()(int x) {
            std::cout << x << std::endl;
        }
    };
    
    int main() {
        std::thread t((Base()), 10);
        t.join();
        return 0;
    }
    
    ```

- non-static member function

  - ```c++
    class Base {
    public:
        void run(int x) {
            std::cout << x << std::endl;
        }
    };
    
    int main() {
        Base b;
        std::thread t(&Base::run, &b, 10);
        t.join();
        return 0;
    }
    
    ```

- static member function

  - ```c++
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
    
    ```
