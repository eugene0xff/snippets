#include <chrono>
#include <future>
#include <iostream>


int main() {
	std::cout << '\n';

	auto const begin = std::chrono::system_clock::now();

	auto asyncLazy = std::async(std::launch::deferred, [] {
		return std::chrono::system_clock::now();
	});

	auto asyncEager = std::async(std::launch::async, [] {
		return std::chrono::system_clock::now();
	});

	std::this_thread::sleep_for(std::chrono::seconds(1));

	auto const lazyStart = asyncLazy.get() - begin;
	auto const eagerStart = asyncEager.get() - begin;

	auto const lazyDuration = std::chrono::duration<double>(lazyStart).count();
	auto const eagerDuration = std::chrono::duration<double>(eagerStart).count();

	std::cout << "asyncLazy evaluated after: " << lazyDuration
		<< " seconds." << '\n';
	std::cout << "asyncEager evaluated after: " << eagerDuration
		<< " seconds." << '\n';

	std::cout << '\n';
}