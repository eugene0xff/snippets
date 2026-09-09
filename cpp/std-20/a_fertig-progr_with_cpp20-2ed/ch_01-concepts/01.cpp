#include <type_traits>

#include <cstdio>

template <typename T, typename... Ts>
constexpr inline bool are_same_v =
	std::conjunction_v<std::is_same<T, Ts>...>;

template <typename T, typename...>
struct first_arg {
	using type = T;
};

template <typename... Args>
using first_arg_t = typename first_arg<Args...>::type;

template <typename... Args>
constexpr std::enable_if_t<are_same_v<Args...>, first_arg_t<Args...>>
Add(const Args&... args) noexcept
{
	return (... + args);
}


// #define WILL_NOT_COMPILE
#ifdef WILL_NOT_COMPILE
void WillNotCompile() {
	printf("%d\n", Add(2, 3, 4.0));
}
#endif

int main() {
	printf("%d\n", Add(2, 3, 4));
	printf("%d\n", Add(2));
}