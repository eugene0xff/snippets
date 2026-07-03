#include <chrono>
#include <iostream>
#include <thread>


class Sleeper {
public:
    Sleeper(int& i) : i_{ i } {}

    void operator() (int const k) {
        for (unsigned int j = 0; j < 6; ++j) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            i_ += k;
        }
        std::cout << std::this_thread::get_id() << '\n';
    }

private:
    int& i_;
};


int main() {
    std::cout << '\n';

    int valSleeper = 1'000;
    std::thread t(Sleeper(valSleeper), 5);
    t.join();    
    std::cout << "valSleeper = " << valSleeper << '\n';

    std::cout << '\n';
}