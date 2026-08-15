#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <thread>
namespace example_01 {

void func() {
    std::cout << "thread func without params" << '\n';
}

void run() {
    std::cout << "example 01 =>" << '\n';

    std::thread t1(func);
    std::thread t2([]() { std::cout << "thread func without params" << '\n'; });
    t1.join();
    t2.join();

    std::cout << '\n';
}

}


#include <iostream>
#include <string>
#include <thread>
namespace example_02 {

void func(int const i, double const d, std::string const& s) {
    std::cout << i << ", " << d << ", " << s << '\n';
}

void run() {
    std::cout << "example 02 =>" << '\n';

    std::thread t1(func, 42, 42.0, "42");
    std::thread t2(
        [](int const i, double const d, std::string const& s) {
            std::cout << i << ", " << d << ", " << s << '\n';
        },
        42, 42.0, "42");

    t1.join();
    t2.join();

    std::cout << '\n';
}

}


#include <functional>
#include <iostream>
#include <thread>
namespace example_03 {

void func(int& i) { i *= 2;  }

void run() {
    std::cout << "example 03 =>" << '\n';

    int n1 = 42;
    int n2 = 42;

    std::thread t1(func, std::ref(n1));
    std::thread t2([](int& i) { i *= 2; }, std::ref(n2));
    t1.join();
    t2.join();
    std::cout << n1 << '\n';
    std::cout << n2 << '\n';

    std::cout << '\n';
}

}


#include <chrono>
#include <iostream>
#include <thread>
namespace example_04 {

inline void print_time() {
    auto now = std::chrono::system_clock::now();
    auto stime = std::chrono::system_clock::to_time_t(now);
    auto ltime = std::localtime(&stime);

    std::cout << std::put_time(ltime, "%c") << '\n';
}

void func() {
    using namespace std::literals::chrono_literals;
    print_time();
    std::this_thread::sleep_for(2s);
    print_time();
}

void run() {
    std::cout << "example 04 =>" << '\n';

    std::thread t(func);
    t.join();
    
    std::cout << '\n';
}

}


#include <chrono>
#include <iostream>
#include <thread>
namespace example_05 {

inline void print_time() {
    auto now = std::chrono::system_clock::now();
    auto stime = std::chrono::system_clock::to_time_t(now);
    auto ltime = std::localtime(&stime);

    std::cout << std::put_time(ltime, "%c") << '\n';
}

void func() {
    using namespace std::literals::chrono_literals;
    print_time();
    std::this_thread::sleep_until(
        std::chrono::system_clock::now() + 2s);
    print_time();
}

void run() {
    std::cout << "example_05 =>" << '\n';

    std::thread t(func);
    t.join();

    std::cout << '\n';
}

}


#include <chrono>
#include <iostream>
#include <thread>
namespace example_06 {

inline void print_time() {
    auto const now = std::chrono::system_clock::now();
    auto const stime = std::chrono::system_clock::to_time_t(now);
    auto const ltime = std::localtime(&stime);

    std::cout << std::put_time(ltime, "%c") << '\n';
}

void func(std::chrono::seconds const timeout) {
    auto const now = std::chrono::system_clock::now();
    auto const then = now + timeout;

    do {
        std::this_thread::yield();
    } while (std::chrono::system_clock::now() < then);
}

void run() {
    std::cout << "example 06 =>" << '\n';

    print_time();
    std::thread t(func, std::chrono::seconds(2));
    t.join();
    print_time();

    std::cout << '\n';
}

}


int main() {
    std::cout << '\n';

    example_01::run();
    example_02::run();
    example_03::run();
    example_04::run();
    example_05::run();
    example_06::run();

    std::cout << '\n';
}
