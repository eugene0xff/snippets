#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

using namespace ::std::literals;


void func(std::stop_token stoken) {
	std::atomic<int> counter{ 0 };

	auto threadId = std::this_thread::get_id();
	std::stop_callback callback(stoken, [&counter, threadId] {
		std::cout << "Thread id: " << threadId
			<< ": counter: " << counter << '\n';
	});

	while (counter < 10 && !stoken.stop_requested()) {
		std::this_thread::sleep_for(0.2s);
		++counter;
	}
}


int main() {
	std::cout << '\n';

	std::vector<std::jthread> vecThreads(10);
	for (auto& t : vecThreads)
		t = std::jthread(func);

	std::this_thread::sleep_for(1s);

	for (auto& t : vecThreads)
		t.request_stop();

	std::cout << '\n';
}