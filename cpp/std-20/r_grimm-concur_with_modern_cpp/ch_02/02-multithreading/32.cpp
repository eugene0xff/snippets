#include <condition_variable>
#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

using namespace ::std::literals;


std::mutex g_mutex;
std::condition_variable_any g_condVar;

bool g_dataReady;

void receiver(std::stop_token stopToken) {
	std::cout << "Waiting" << '\n';

	std::unique_lock<std::mutex> lock(g_mutex);
	bool ret = g_condVar.wait(lock, stopToken, [] { return g_dataReady; });
	if (ret) {
		std::cout << "Notification received: " << '\n';
	}
	else {
		std::cout << "Stop request received" << '\n';
	}
}

void sender() {
	std::this_thread::sleep_for(5ms);
	{
		std::lock_guard<std::mutex> lock(g_mutex);
		g_dataReady = true;
		std::cout << "Send notification" << '\n';
	}
	g_condVar.notify_one();
}


int main() {
	std::cout << '\n';

	std::jthread t1(receiver);
	std::jthread t2(sender);

	t1.request_stop();

	t1.join();
	t2.join();

	std::cout << '\n';
}