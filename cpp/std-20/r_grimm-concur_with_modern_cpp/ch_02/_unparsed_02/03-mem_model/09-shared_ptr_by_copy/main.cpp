#include <atomic>
#include <memory>
#include <thread>
#include <cassert>


int main() {
    std::shared_ptr<int> ptr{ std::make_shared<int>(2011) };

    for (std::size_t i{0}; i < 10; ++i)
        std::thread([ptr] {
            std::shared_ptr<int> localPtr{ptr};
            localPtr = std::make_shared<int>(2014);
            assert(2014 == *localPtr);
        }).detach();

    assert(2011 == *ptr);
    
    return 0;
}
