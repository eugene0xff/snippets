#include <iostream>
#include <chrono>
#include <thread>


using namespace std::literals;

void func(std::stop_token stopToken) {
	std::this_thread::sleep_for(100ms);

	std::cout << "start registration" << '\n';
	for (int i = 0; i <= 9; ++i) {
		std::stop_callback callback(stopToken, [i] { std::cout << i; });
	}

	std::cout << "start working" << '\n';
	std::cout << '\n';
}


int main() {
	std::cout << '\n';

	std::jthread t1 = std::jthread(func);
	std::jthread t2 = std::jthread(func);

	std::cout << '\n' << "before a stop request" << '\n';
	t1.request_stop();
	t2.request_stop();
	std::cout << '\n' << "after a stop request" << '\n';

	std::cout << '\n';
}
