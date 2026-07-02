#include <functional>
#include <iostream>
#include <thread>


class Account {
public:
    int value;
};

void transferMoney(int amount, Account& from, Account& to) {
    from.value -= amount;
    to.value += amount;
}


int main() {
    std::cout << '\n';

    Account acc1{ 100 };
    Account acc2{ 50 };
    std::cout << "before: acc1: " << acc1.value << ", acc2: " << acc2.value << '\n';

    std::thread t(transferMoney, 50, std::ref(acc1), std::ref(acc2));
    t.join();
    std::cout << "before: acc1: " << acc1.value << ", acc2: " << acc2.value << '\n';

    std::cout << '\n';
}
