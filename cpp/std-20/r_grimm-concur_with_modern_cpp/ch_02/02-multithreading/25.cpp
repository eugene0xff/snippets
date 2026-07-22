#include <iostream>
#include <chrono>
#include <thread>

int main() {
	std::cout << '\n';

	std::jthread t([](std::stop_token stopToken) {
		std::stop_token interruptDisabled;
		std::swap(stopToken, interruptDisabled);
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
		std::swap(stopToken, interruptDisabled);
	});

	std::cout << '\n';
}
