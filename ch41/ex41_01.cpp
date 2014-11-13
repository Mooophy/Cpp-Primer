//!
//! @author Yue Wang
//! @date   13 11 2014
//!
//! @ex 41.01
//!     (a) share data between two threads.
//!     (b) use mutex to avoid data race.
//!
//  to compile (on linux)   :
//      g++ -std=c++11 -Wall ex41_01.cpp  -pthread
//!

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <memory>
#include <vector>
#include <string>

using SharedData = std::shared_ptr<std::vector<std::string>>;

void task1(SharedData data, std::mutex* mutex)
{
    std::this_thread::sleep_for(std::chrono::milliseconds{5});

    std::unique_lock<std::mutex> lock{*mutex};
    for(const auto& elem : *data)
        std::cout << "\nfrom task 1 " << elem << " ";
}

void task2(SharedData data, std::mutex* mutex)
{
    std::unique_lock<std::mutex> lock{*mutex};
    data->push_back("pezy--added by task2");
}

int main()
{
    //! data for sharing
    auto data = std::make_shared<std::vector<std::string> >();
    *data = {"alan","moophy","yue wang"};

    //! two threads
    static std::mutex mutex;
    std::thread t1(task1,data,&mutex), t2(task2,data,&mutex);

    t1.join();
    t2.join();
    std::cout << "\n\ndone\n";
}
//! output :

//from task 1 alan
//from task 1 moophy
//from task 1 yue wang
//from task 1 pezy--added by task2

//done
