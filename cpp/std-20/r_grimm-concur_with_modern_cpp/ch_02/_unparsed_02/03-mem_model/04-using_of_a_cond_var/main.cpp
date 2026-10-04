#include <condition_variable>
#include <iostream>
#include <thread>
#include <vector>

std::vector<int> mySharedWork{};
std::mutex mut{};
std::condition_variable condVar{};

bool dataReady{ false };

void waitingForWork() {
    std::cout << "waiting" << std::endl;
    std::unique_lock<std::mutex> lock{mut};
    condVar.wait(lock, []{ return dataReady; });
    mySharedWork[1] = 2;
    std::cout << "work done" << std::endl;
}

void setDataReady() {
    mySharedWork = { 1, 0, 3 };
    {
        std::lock_guard<std::mutex> lock{mut};
        dataReady = true;
    }
    std::cout << "data prepared" << std::endl;
    condVar.notify_one();
}

int main() {
    std::cout << std::endl;

    std::thread t1{waitingForWork}, t2{setDataReady};
    t1.join(), t2.join();

    for (auto const& val : mySharedWork)
        std::cout << val << " ";

    return 0;
}
