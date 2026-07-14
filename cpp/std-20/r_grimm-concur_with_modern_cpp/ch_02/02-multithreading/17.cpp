#include <iostream>
#include <mutex>


class MySingleton {
private:
    static std::once_flag initInstanceFlag_;
    static MySingleton* instance_;

    MySingleton() = default;
    ~MySingleton() = default;

    static void initSingleton() {
        instance_ = new MySingleton();
    }

public:
    MySingleton(MySingleton const&) = delete;
    MySingleton& operator=(MySingleton const&) = delete;

    static MySingleton* getInstance() {
        std::call_once(initInstanceFlag_, MySingleton::initSingleton);
        return instance_;
    }
};

MySingleton* MySingleton::instance_ = nullptr;
std::once_flag MySingleton::initInstanceFlag_;


int main() {
    std::cout << '\n';

    std::cout << "MySingleton::getInstance(): " << MySingleton::getInstance() << '\n';
    std::cout << "MySingleton::getInstance(): " << MySingleton::getInstance() << '\n';

    std::cout << '\n';
}
