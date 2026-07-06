#include <chrono>
#include <iostream>
#include <thread>

using namespace ::std::literals;

int main() {
    std::cout << '\n';

    std::jthread nonInterruptible([] {
        int counter{ 0 };
        while (counter < 10) {
            std::this_thread::sleep_for(0.2s);
            std::cout << "nonInterruptible: " << counter << '\n';
            ++counter;
        }
    });

    std::jthread interruptible([](std::stop_token stopToken) {
        int counter{ 0 };
        while (counter < 10) {
            std::this_thread::sleep_for(0.2s);
            if (stopToken.stop_requested())
                return;
            std::cout << "interruptible: " << counter << '\n';
            ++counter;
        }
    });

    std::this_thread::sleep_for(1s);

    std::cout << '\n';
    std::cout << "Main thread interrupts both jthreads" << '\n';
    nonInterruptible.request_stop();
    interruptible.request_stop();

    std::cout << '\n';
}
