#include <functional>
#include <future>
#include <iostream>
#include <utility>
#include <vector>


void calcProducts(
	std::packaged_task<int(int, int)>& task,
	std::vector<std::pair<int, int>>& pairs)
{
	for (auto const& p : pairs) {
		auto fut = task.get_future();
		task(p.first, p.second);
		std::cout << p.first << " * " << p.second << " = " << fut.get() << '\n';
		task.reset();
	}
}
	

int main() {
	std::cout << '\n';

	std::vector<std::pair<int, int>> allPairs;
	allPairs.push_back(std::make_pair(1, 2));
	allPairs.push_back(std::make_pair(2, 3));
	allPairs.push_back(std::make_pair(3, 4));
	allPairs.push_back(std::make_pair(4, 5));

	std::packaged_task<int(int, int)> task{ [](int first, int second) { return first * second; } };

	calcProducts(task, allPairs);

	std::cout << '\n';

	std::thread t(calcProducts, std::ref(task), std::ref(allPairs));
	t.join();

	std::cout << '\n';
}