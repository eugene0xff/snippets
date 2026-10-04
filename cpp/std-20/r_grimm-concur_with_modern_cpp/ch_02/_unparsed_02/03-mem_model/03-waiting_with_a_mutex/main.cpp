#include <chrono>
#include <mutex>
#include <thread>


std::mutex mut{};
void work_on_res() {
    mut.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    mut.unlock();
}


int main() {
    std::thread t1{work_on_res}, t2{work_on_res};
    t1.join(), t2.join();
    
    return 0;
}
