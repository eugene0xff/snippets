#include <iostream>
#include <thread>

int main() {
    std::cout << '\n';

    std::string s{ "C++11" };

    std::thread t1([=] { std::cout << s << '\n'; });
    t1.join();

    std::thread t2([&] { std::cout << s << '\n'; });
    t2.join();

    std::cout << '\n';
}
