# std::stop_callback

The registrated std::stop_callback is invoked when 'request_stop' is called.

std::stop_callback's constructor registers a callable for a stop token and it's destructor unregisters it.

<hr />

**If the request to stop happens prior to the registration of the 'std::stop_callback'
the callback is invoked in the thread constructing the 'std::stopcallback'.**
(thus the child thread has to execute each handler during registration)

```cpp
#include <chrono>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

#include <cassert>

using namespace ::std::literals;


auto const func = [](std::stop_token stopToken, std::thread::id const& mainThreadId) {
	std::this_thread::sleep_for(2s);

	std::stop_callback callback(stopToken, [&mainThreadId] {
		assert(std::this_thread::get_id() != mainThreadId);
	});

	for (int i{ 0 }; i < 10; ++i) {
		std::this_thread::sleep_for(0.2s);
	}
};


int main() {
	std::thread::id const mainThreadId = std::this_thread::get_id();

	std::vector<std::jthread> threads(10);
	for (auto& t : threads) {
		t = std::jthread(func, std::cref(mainThreadId));
	}

	for (auto& t : threads) {
		t.request_stop();
	}
}

```


**If the request to stop happens after the registration of the 'std::stop_callback',
the callback in invoked in the thread invoking 'request_stop'.**

```cpp
#include <chrono>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

#include <cassert>

using namespace ::std::literals;


auto const func = [](std::stop_token stopToken, std::thread::id const& mainThreadId) {
	std::stop_callback callback(stopToken, [&mainThreadId] {
		assert(std::this_thread::get_id() == mainThreadId);
	});

	for (int i{ 0 }; i < 10; ++i) {
		std::this_thread::sleep_for(0.2s);
	}
};


int main() {
	std::thread::id const mainThreadId = std::this_thread::get_id();

	std::vector<std::jthread> threads(10);
	for (auto& t : threads) {
		t = std::jthread(func, std::cref(mainThreadId));
	}

	std::this_thread::sleep_for(2s);

	for (auto& t : threads) {
		t.request_stop();
	}
}
```



**If the request to stop happens after the child jthread is executed,
then no callback is called**
Example:
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include <cassert>

using namespace ::std::literals;


auto const func = [](std::stop_token stopToken) {
	std::stop_callback callback(stopToken, [] { assert(false); });
};


int main() {
	std::vector<std::jthread> threads(10);
	for (auto& t : threads) {
		t = std::jthread(func);
	}

	std::this_thread::sleep_for(2s);

	for (auto& t : threads) {
		t.request_stop();
	}
}
```

**If the request to stop happens on non exetuced std::jthread
then no callback is called**
Example:
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include <cassert>

using namespace ::std::literals;


auto const func = [](std::stop_token stopToken) {
	std::stop_callback callback(stopToken, [] { assert(false); });
};


int main() {
	std::vector<std::jthread> threads(10);

	for (auto& t : threads) {
		t.request_stop();
	}

	std::this_thread::sleep_for(2s);
}
```