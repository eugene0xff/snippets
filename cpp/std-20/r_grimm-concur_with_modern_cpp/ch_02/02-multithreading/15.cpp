#include <iostream>

class MyDouble {
private:
    double const myVal1_;
    double const myVal2_;

public:
    constexpr MyDouble(double const myVal1, double const myVal2) : myVal1_(myVal1), myVal2_(myVal2) {}
    constexpr double getSum() const { return myVal1_ + myVal2_; }
};

int main() {
    std::cout << '\n';

    constexpr double myStatVal = 2.0;
    constexpr MyDouble myStatic(10.5, myStatVal);
    constexpr double sumStat = myStatic.getSum();

    std::cout << '\n';
}
