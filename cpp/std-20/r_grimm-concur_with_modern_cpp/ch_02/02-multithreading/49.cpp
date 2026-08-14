#include <future>
#include <iostream>
#include <utility>


void doTheWork() {
	std::cout << "Processing shared data." << '\n';
}

void waitingForWork(std::future<void>&& aFuture) {
	std::cout << "Worker: Waiting for work." << '\n';
	aFuture.wait();
	doTheWork();
	std::cout << "Work done." << '\n';
}

void setDataReady(std::promise<void>&& aPromise) {
	std::cout << "Sender: Data is ready." << '\n';
	aPromise.set_value();
}


int main() {
	std::cout << '\n';

	std::promise<void> sendReady;
	auto aFuture = sendReady.get_future();

	std::thread t1(waitingForWork, std::move(aFuture));
	std::thread t2(setDataReady, std::move(sendReady));

	t1.join();
	t2.join();

	std::cout << '\n';
}