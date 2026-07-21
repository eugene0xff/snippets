# std::jthread's stop_request behavior
**[1]**
if the parent thread is terminated ealier than it's child std::jthreads then it implicitly calls the 'stop_request' methods on it's child std::jthreads

Example:
```cpp
#include <thread>
#include <cassert>

int main() {
	std::jthread _([](std::stop_token stopToken) { assert(stopToken.stop_requested()); });
}
```

or more elaborated example:
```cpp
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <thread>

#include <cassert>

using namespace ::std::literals;


std::mutex g_mutex;
std::condition_variable g_condVar;
bool g_isReady{ false };


int main() {
	std::jthread _([](std::stop_token stopToken) {
		std::unique_lock<std::mutex> lock(g_mutex);
		g_condVar.wait(lock, [] { return g_isReady; });

		assert(stopToken.stop_requested());
	});

	std::this_thread::sleep_for(2s);
	{
		std::lock_guard<std::mutex> _(g_mutex);
		g_isReady = true;
	}
	g_condVar.notify_one();
}
```

**[2]**
If the parent thread is terminated after than it's child std::jthreads then it doesn't call the 'stop_request' methods on it's child std::jthreads
Example:
```cpp
#include <chrono>
#include <thread>

#include <cassert>

using namespace ::std::literals;

int main() {
	std::jthread _([](std::stop_token stopToken) { assert(not stopToken.stop_requested()); });
	std::this_thread::sleep_for(2s);
}
```

or something more elaborating
```cpp
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <thread>

#include <cassert>

using namespace ::std::literals;


std::mutex g_mutex;
std::condition_variable g_condVar;
bool g_isReady{ false };


int main() {
	std::jthread _([](std::stop_token stopToken) {
		assert(not stopToken.stop_requested());

		std::this_thread::sleep_for(2s);
		{
			std::lock_guard<std::mutex> _(g_mutex);
			g_isReady = true;
		}
		g_condVar.notify_one();
	});

	std::unique_lock<std::mutex> lock(g_mutex);
	g_condVar.wait(lock, [] { return g_isReady; });
}
```