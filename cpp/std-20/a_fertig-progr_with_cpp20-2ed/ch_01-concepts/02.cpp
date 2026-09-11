#include <type_traits>
#include <cstdio>

#include <iostream>

template <typename T>
constexpr T pi(3.14);

template <typename T, typename U>
constexpr bool is_same_v = std::is_same<T, U>::value;

int main() {
	printf("%f\n", pi<double>);
	printf("%d\n", is_same_v<int, int>);
	printf("%d\n", is_same_v<int, double>);
}