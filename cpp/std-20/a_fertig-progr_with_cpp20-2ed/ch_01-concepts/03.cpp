#include <cstdio>
#include <type_traits>

template<typename T, typename... Ts>
constexpr bool are_same_v =
	std::conjunction_v<std::is_same<T, Ts>...>;

template <typename... Args>
requires are_same_v<Args...>
auto Add(Args&&... args) noexcept
{
	return (... + args);
}

int main() {
	printf("%d\n", Add(2, 3, 4));
	printf("%d\n", Add(2));
}