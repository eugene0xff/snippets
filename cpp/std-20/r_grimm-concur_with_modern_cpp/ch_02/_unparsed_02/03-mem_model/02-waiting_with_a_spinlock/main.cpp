#include <atomic>
#include <chrono>
#include <thread>

class SpinLock {
    public:
        void lock() { while (flag_.test_and_set()); }
        void unlock() { flag_.clear(); }
    
    private:
        std::atomic_flag flag_ = ATOMIC_FLAG_INIT;
};


SpinLock spin{};
void work_on_res() {
    spin.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    spin.unlock();
}


int main() {
    std::thread t1{work_on_res}, t2{work_on_res};
    t1.join(), t2.join();
    
    return 0;
}
