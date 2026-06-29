#include <iostream>
#include <thread>


void helloFunc() {
    std::cout << "hello from a func" << '\n';
}

class HelloFuncObj {
public:
    void operator()() const {
        std::cout << "hello from a func obj" << '\n';
    }
};


int main() {
    std::cout << '\n';

    std::thread t1(helloFunc);

    HelloFuncObj helloFuncObj;
    std::thread t2(helloFuncObj);

    std::thread t3([] { std::cout << "hello from a lambda" << '\n'; });

    t1.join();
    t2.join();
    t3.join();

    std::cout << '\n';
}
