#include <iostream>


class MySingleton {
public:
    static MySingleton& getInstance() {
        static MySingleton instance;
        return instance;
    }

private:
    MySingleton();
    ~MySingleton();
    MySingleton(MySingleton const&) = delete;
    MySingleton& operator=(MySingleton const&) = delete;
};

MySingleton::MySingleton() = default;
MySingleton::~MySingleton() = default;


int main() {
    std::cout << '\n';

    MySingleton::getInstance();
    
    std::cout << '\n';
}
