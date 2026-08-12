#include <exception>
#include <future>
#include <iostream>
#include <string>
#include <thread>
#include <utility>


struct Div {
	void operator()(std::promise<int>&& intPromise, int const a, int const b) {
		try {
			if (b == 0) {
				std::string const& errMsg = std::string("Illegal divison by zero: ") +
					std::to_string(a) + "/" + std::to_string(b);

				throw std::runtime_error(errMsg);
			}
			intPromise.set_value(a / b);
		}
		catch(...) {
			intPromise.set_exception(std::current_exception());
		}
	}
};


void executeDivision(int const nom, int const denom) {
	std::promise<int> divPromise;
	std::future<int> divResult = divPromise.get_future();

	Div div;
	std::thread divThread(div, std::move(divPromise), nom, denom);

	try {
		std::cout << nom << "/" << denom << " = " << divResult.get() << '\n';
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << '\n';
	}

	divThread.join();
}

int main() {
	std::cout << '\n';

	executeDivision(20, 0);
	executeDivision(20, 10);

	std::cout << '\n';
}