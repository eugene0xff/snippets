#include <iostream>
#include <atomic>
#include <chrono>
#include <thread>
#include <vector>


using namespace std::literals;

auto g_func = [](std::stop_token stopToken) {
	int counter{ 0 };
	auto threadId = std::this_thread::get_id();
	std::stop_callback callback(stopToken, [&counter, threadId] {
		std::cout << "Thread id: " << threadId
			<< "; counter: " << counter << '\n';
	});
	
	while (counter < 10) {
		std::this_thread::sleep_for(0.2s);
		++counter;
	}
};

int main() {
	std::cout << '\n';

	std::vector<std::jthread> threads(10);
	for (auto& t : threads)
		t = std::jthread(g_func);

	std::this_thread::sleep_for(1s);

	for (auto& t : threads)
		t.request_stop();

	std::cout << '\n';
}
