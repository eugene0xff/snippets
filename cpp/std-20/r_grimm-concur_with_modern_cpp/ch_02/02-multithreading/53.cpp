#include <chrono>
#include <iostream>
#include <syncstream>
#include <thread>


class Worker {
public:
	Worker(std::string const& name) : name_(name) {};

	void operator()() {
		for (int i = 1; i <= 3; i++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			std::osyncstream(std::cout) << name_ << ": " << "Work " << i << " done !!!" << '\n';
		}
	}

private:
	std::string const name_;
};


int main() {
	std::cout << '\n';

	std::cout << "Bos:: Let's start working.\n\n";

	std::thread herb = std::thread(Worker("Herb"));
	std::thread andrei = std::thread(Worker("  Andrei"));
	std::thread scott = std::thread(Worker("    Scott"));
	std::thread bjarne = std::thread(Worker("      Bjarne"));
	std::thread bart = std::thread(Worker("        Bart"));
	std::thread jenne = std::thread(Worker("          Jenne"));

	herb.join();
	andrei.join();
	scott.join();
	bjarne.join();
	bart.join();
	jenne.join();

	std::cout << '\n' << "Boss: Let's go home." << '\n';
	

	std::cout << '\n';
}