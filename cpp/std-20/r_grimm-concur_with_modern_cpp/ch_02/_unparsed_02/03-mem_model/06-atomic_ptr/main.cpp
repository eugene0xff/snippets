#include <atomic>
#include <cassert>

int main() {
    int intArray[5];
    std::atomic<int*> p{intArray};

    p++;
    assert(&intArray[1] == p.load());

    p += 1;
    assert(&intArray[2] == p.load());

    --p;
    assert(&intArray[1] == p.load());
    
    return 0;
}
