#include <iostream>
#include <thread>

int main() {
    std::cout << '\n';

    std::thread t([] { std::cout << std::this_thread::get_id() << '\n'; });
    t.join();

    std::cout << '\n';
}
