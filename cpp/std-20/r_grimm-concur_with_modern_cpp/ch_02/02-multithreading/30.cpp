#include <iostream>

#include <chrono>
#include <functional>
#include <list>
#include <stop_token>
#include <thread>


using namespace std::literals;

using handler_t = std::function<void()>;
using callback_t = std::stop_callback<handler_t>;

void func(std::stop_token stopToken) {
	std::list<callback_t> callbacks;

	std::cout << "start registration" << '\n';
	for (int i = 0; i <= 9; ++i)
		callbacks.emplace_back(stopToken, [i] { std::cout << i; });

	std::this_thread::sleep_for(100ms);

	std::cout << "start working" << '\n';
	std::cout << '\n';
}


int main() {
	std::cout << '\n';

	std::jthread t1 = std::jthread(func);
	std::jthread t2 = std::jthread(func);

	std::this_thread::sleep_for(50ms);

	std::cout << '\n' << "before a stop request" << '\n';
	t1.request_stop();
	t2.request_stop();
	std::cout << '\n' << "after a stop request" << '\n';

	std::cout << '\n';
}