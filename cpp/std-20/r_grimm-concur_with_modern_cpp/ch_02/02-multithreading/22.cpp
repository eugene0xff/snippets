#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>


std::mutex g_mutex;
std::condition_variable g_condVar;

bool g_dataReady{ false };

void doTheWork() {
	std::cout << "Processing shared data" << '\n';
}

void waitingForWork() {
	std::cout << "Worker: Waiting for work" << '\n';
	std::unique_lock<std::mutex> lock(g_mutex);
	while (not [] { return g_dataReady; }()) {
		g_condVar.wait(lock);
	}
	doTheWork();
	std::cout << "Work done." << '\n';
}

void setDataReady() {
	{
		std::lock_guard<std::mutex> lock(g_mutex);
		g_dataReady = true;
	}
	std::cout << "Sender: Data is ready" << '\n';
	g_condVar.notify_one();
}


int main() {
	std::cout << '\n';

	std::thread t1(waitingForWork);
	std::thread t2(setDataReady);

	t1.join();
	t2.join();

	std::cout << '\n';
}
