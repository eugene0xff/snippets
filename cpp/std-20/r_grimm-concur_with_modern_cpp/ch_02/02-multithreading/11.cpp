#include <iostream>
#include <map>
#include <shared_mutex>
#include <string>
#include <thread>


std::map<std::string, int> g_teleBook{ {"Dijkstra", 1972}, {"Scott", 1976}, { "Ritchie", 1983 } };

std::shared_timed_mutex g_teleBookMut;

void addToTeleBook(std::string const& name, int const tele) {
    std::lock_guard<std::shared_timed_mutex> writeLock(g_teleBookMut);
    std::cout << "\nSTARTING UPDATE " << name;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    g_teleBook[name] = tele;
    std::cout << " ... ENDING UPDATE " << name << '\n';
}

void printNumber(std::string const& name) {
    std::shared_lock<std::shared_timed_mutex> readerLock(g_teleBookMut);
    auto searchEntry = g_teleBook.find(name);
    if (searchEntry != g_teleBook.end()) {
        std::cout << searchEntry->first << ": " << searchEntry->second << '\n';
    }
    else {
        std::cout << name << " not found!" << '\n';
    }
}


int main() {
    std::cout << '\n';

    std::thread reader1([] { printNumber("Scott"); });
    std::thread reader2([] { printNumber("Ritchie"); });
    std::thread w1([] { addToTeleBook("Scott", 1968); });
    std::thread reader3([] { printNumber("Dijkstra");  });
    std::thread reader4([] { printNumber("Scott"); });
    std::thread w2([] { addToTeleBook("Bjarne", 1965); });
    std::thread reader5([] { printNumber("Scott"); });
    std::thread reader6([] { printNumber("Ritchie"); });
    std::thread reader7([] { printNumber("Scott"); });
    std::thread reader8([] { printNumber("Bjarne"); });
    
    reader1.join();
    reader2.join();
    reader3.join();
    reader4.join();
    reader5.join();
    reader6.join();
    reader7.join();
    reader8.join();
    w1.join();
    w2.join();

    std::cout << '\n';

    std::cout << "\nThe new telephone book" << '\n';
    for (auto teleIt : g_teleBook) {
        std::cout << teleIt.first << ": " << teleIt.second << '\n';
    }

    std::cout << '\n';
}
