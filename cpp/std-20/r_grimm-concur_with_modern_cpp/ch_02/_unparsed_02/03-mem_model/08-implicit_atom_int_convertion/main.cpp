#include <atomic>
#include <cassert>

int main() {
    std::atomic<long long> atomObj{2011};
    atomObj = 2014;
    long long const nonAtomObj = atomObj;

    assert(2014 == nonAtomObj);
    
    return 0;
}
