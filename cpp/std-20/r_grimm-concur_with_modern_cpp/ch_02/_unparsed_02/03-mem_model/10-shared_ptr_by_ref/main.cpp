#include <atomic>
#include <memory>
#include <thread>
#include <cassert>


int main() {
    std::shared_ptr<int> ptr{ std::make_shared<int>(2011) };

    for (std::size_t i{0}; i < 10; ++i)
        std::thread([&ptr] {            
            auto localPtr = std::make_shared<int>(2014);
            std::atomic_store(&ptr, localPtr);
            assert(2014 == *localPtr);
            assert(2014 == *ptr);
        }).detach();

    assert(2014 == *ptr);
    
    return 0;
}
