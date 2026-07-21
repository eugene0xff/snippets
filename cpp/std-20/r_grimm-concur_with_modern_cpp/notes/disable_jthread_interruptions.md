To disable implicit and explicit std::jthread interruption

```cpp
#include <chrono>
#include <thread>

#include <cassert>

using namespace ::std::literals;


int main() {
	std::jthread _([](std::stop_token stopToken) {
		assert(stopToken.stop_requested());

		std::stop_token interruptDisabled;
		std::swap(stopToken, interruptDisabled);
		assert(not stopToken.stop_requested());

		std::this_thread::sleep_for(2s);
		assert(not stopToken.stop_requested());

		std::swap(stopToken, interruptDisabled);
		assert(stopToken.stop_requested());
	});
}
```

more elaborate example:
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

		std::stop_token interruptDisabled;
		std::swap(stopToken, interruptDisabled);
		assert(not stopToken.stop_requested());

		std::this_thread::sleep_for(2s);
		assert(not stopToken.stop_requested());

		std::swap(stopToken, interruptDisabled);
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