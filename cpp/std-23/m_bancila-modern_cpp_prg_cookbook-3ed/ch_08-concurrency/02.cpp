#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
namespace example_01 {

std::mutex g_mutex;

void func() {
    using namespace std::chrono_literals;

    {
        std::lock_guard<std::mutex> lock(g_mutex);
        std::cout << "running thread "
            << std::this_thread::get_id() << '\n';
    }

    std::this_thread::yield();
    std::this_thread::sleep_for(2s);

    {
        std::lock_guard<std::mutex> lock(g_mutex);
        std::cout << "done in thread "
            << std::this_thread::get_id() << '\n';
    }
}

void run() {
    std::cout << "example 01 =>" << '\n';

    std::vector<std::thread> threads;
    for (std::vector<std::thread>::size_type i{ 0 }, in{ 5 }; i < in; ++i)
        threads.emplace_back(func);

    for (auto& thread : threads)
        thread.join();

    std::cout << '\n';
}

}


#include <functional>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
namespace example_02 {

template <typename T>
struct container {
    std::mutex mutex;
    std::vector<T> data;
};

template <typename T>
void move_between(container<T>& c1, container<T>& c2, T const value) {
    std::lock(c1.mutex, c2.mutex);

    std::lock_guard<std::mutex> l1(c1.mutex, std::adopt_lock);
    std::lock_guard<std::mutex> l2(c2.mutex, std::adopt_lock);

    c1.data.erase(
        std::remove(c1.data.begin(), c1.data.end(), value),
        c1.data.end());
    c2.data.push_back(value);
}

void run() {
    std::cout << "example 02 =>" << '\n';

    container<int> c1;
    c1.data.push_back(1);
    c1.data.push_back(2);
    c1.data.push_back(3);

    container<int> c2;
    c2.data.push_back(4);
    c2.data.push_back(5);
    c2.data.push_back(6);

    std::thread t1(move_between<int>, std::ref(c1), std::ref(c2), 3);
    std::thread t2(move_between<int>, std::ref(c2), std::ref(c1), 6);

    t1.join();
    t2.join();

    std::cout << "after:" << '\n';

    for (auto const& val : c1.data)
        std::cout << val << " ";
    std::cout << '\n';

    for (auto const& val : c2.data)
        std::cout << val << " ";
    std::cout << '\n';

    std::cout << '\n';
}

}


#include <functional>
#include <iostream>
#include <mutex>
#include <thread>
namespace example_03 {

template <typename T>
struct container {
    std::mutex mutex;
    std::vector<T> data;
};

template <typename T>
void move_between(container<T>& c1, container<T>& c2, T const value) {
    std::scoped_lock lock(c1.mutex, c2.mutex);

    c1.data.erase(
        std::remove(c1.data.begin(), c1.data.end(), value),
        c1.data.end());
    c2.data.push_back(value);
}

void run() {
    std::cout << "example 03 =>" << '\n';

    container<int> c1;
    c1.data.push_back(1);
    c1.data.push_back(2);
    c1.data.push_back(3);

    container<int> c2;
    c2.data.push_back(4);
    c2.data.push_back(5);
    c2.data.push_back(6);

    std::thread t1(move_between<int>, std::ref(c1), std::ref(c2), 3);
    std::thread t2(move_between<int>, std::ref(c2), std::ref(c1), 6);

    t1.join();
    t2.join();

    std::cout << "after:" << '\n';
    
    for (auto const& val : c1.data)
        std::cout << val << " ";
    std::cout << '\n';

    for (auto const& val : c2.data)
        std::cout << val << " ";
    std::cout << '\n';

    std::cout << '\n';
}

}

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
namespace example_04 {

std::mutex g_mutex;

void func() {
    g_mutex.lock();
    std::cout << "accessing a shared resource" << '\n';
    g_mutex.unlock();
}

void run() {
    std::cout << "example 04 =>" << '\n';

    std::vector<std::thread> threads;
    for (std::vector<std::thread>::size_type i{ 0 }, in{ 5 }; i < in; ++i)
        threads.emplace_back(func);

    for (auto& thread : threads)
        thread.join();

    std::cout << '\n';
}

}


#include <iostream>
#include <thread>
namespace example_05 {

template <class M>
class lock_guard {
public:
    typedef M mutex_type;

    explicit lock_guard(M& mutex) : mutex_(mutex) {
        mutex_.lock();
    }

    lock_guard(M& mutex, std::adopt_lock_t) : mutex_(mutex) {}

    ~lock_guard() noexcept { mutex_.unlock(); }

    lock_guard(lock_guard const&) = delete;
    lock_guard& operator=(lock_guard const&) = delete;

private:
    M& mutex_;
};

std::mutex g_mutex;

void func() {
    using namespace std::chrono_literals;

    lock_guard<std::mutex> lock(g_mutex);
    std::cout << "running thread " << std::this_thread::get_id() << '\n';
    std::this_thread::sleep_for(2s);
    std::cout << "done in thread " << std::this_thread::get_id() << '\n';
}

void run() {
    std::cout << "example 05 =>" << '\n';

    std::vector<std::thread> threads;
    for (std::vector<std::thread>::size_type i{ 0 }, in{ 5 }; i < in; ++i)
        threads.emplace_back(func);
    
    for (auto& thread : threads)
        thread.join();

    std::cout << '\n';
}

}


int main() {
    std::cout << '\n';

    example_01::run();
    example_02::run();
    example_03::run();
    example_04::run();
    example_05::run();

    std::cout << '\n';
}
