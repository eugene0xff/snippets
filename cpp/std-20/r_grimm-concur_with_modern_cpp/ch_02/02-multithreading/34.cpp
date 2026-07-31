#include <iostream>
#include <mutex>
#include <latch>
#include <thread>


std::latch workDone(6);
std::latch goHome(1);

std::mutex coutMutex;

void synchronizedOut(std::string const& s) {
	std::lock_guard<std::mutex> _(coutMutex);
	std::cout << s;
}

class Worker {
public:
	Worker(std::string const& name) : name_(name) {};

	void operator()() {
		synchronizedOut(name_ + ": " + "Work done!\n");
		workDone.count_down();
		
		goHome.wait();
		synchronizedOut(name_ + ": " + "Good bye!\n");
	}

private:
	std::string const name_;
};


int main() {
	std::cout << '\n';

	std::cout << "BOSS: START WORKING! " << '\n';

	Worker herb("  Herb");
	std::thread herbWork(herb);

	Worker scott("    Scott");
	std::thread scottWork(scott);

	Worker bjarne("      Bjarne");
	std::thread bjarneWork(bjarne);

	Worker andrei("        Andrei");
	std::thread andreiWork(andrei);

	Worker andrew("          Andrew");
	std::thread andrewWork(andrew);

	Worker david("             David");
	std::thread davidWork(david);

	workDone.wait();

	synchronizedOut("\n");

	goHome.count_down();

	synchronizedOut("BOSS:: GO HOME!\n");

	herbWork.join();
	scottWork.join();
	bjarneWork.join();
	andreiWork.join();
	andrewWork.join();
	davidWork.join();

	std::cout << '\n';
}