#include <atomic>
#include <iostream>
#include <cassert>

template <typename T>
T fetch_mult(std::atomic<T>& shared, T mult) {
    T oldVal = shared.load();
    while (not shared.compare_exchange_strong(oldVal, oldVal * mult));
    return oldVal;
}

int main() {
    std::atomic<int> myInt{5};

    auto const& preVal = fetch_mult(myInt, 5);
    
    assert(5 == preVal and 25 == myInt);
    
    return 0;
}
