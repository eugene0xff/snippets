#include <iostream>
#include <barrier>
#include <mutex>
#include <string>
#include <thread>


std::barrier workDone(6);
std::mutex coutMutex;

void synchronizedOut(std::string const& s) noexcept {
	std::lock_guard<std::mutex> _(coutMutex);
	std::cout << s;
}

class FullTimeWorker {
public:
	FullTimeWorker(std::string const& name) : name_(name) {};

	void operator()() {
		synchronizedOut(name_ + ": " + "Morning work done!\n");
		workDone.arrive_and_wait();
		synchronizedOut(name_ + ": " + "Afternoon work done!\n");
		workDone.arrive_and_wait();
	}

private:
	std::string const name_;
};

class PartTimeWorker {
public:
	PartTimeWorker(std::string const& name) : name_(name) {};

	void operator()() {
		synchronizedOut(name_ + ": " + "Morning work done!\n");
		workDone.arrive_and_drop();
	}

private:
	std::string const name_;
};


int main() {
	std::cout << '\n';

	FullTimeWorker herb("  Herb");
	std::thread herbWork(herb);

	FullTimeWorker scott("    Scott");
	std::thread scottWork(scott);

	FullTimeWorker bjarne("      Bjarne");
	std::thread bjarneWork(bjarne);

	PartTimeWorker andrei("        Andrei");
	std::thread andreiWork(andrei);

	PartTimeWorker andrew("          Andrew");
	std::thread andrewWork(andrew);

	PartTimeWorker david("            David");
	std::thread davidWork(david);

	herbWork.join();
	scottWork.join();
	andreiWork.join();
	bjarneWork.join();
	andrewWork.join();
	davidWork.join();

	std::cout << '\n';
}