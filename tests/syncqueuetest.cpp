#include <yage.h>

#include <atomic>
#include <thread>

using namespace yage;

SyncQueue<int> queue;
std::atomic_int j;

void push_to_queue1(int elements)
{
    for (int i = 0; i < elements; i++) {
        queue.push(1);
        j.fetch_add(1, std::memory_order_relaxed);
    }
    std::cout << "Done 1\n";
}

void push_to_queue2(int elements)
{
    for (int i = 0; i < elements; i++) {
        queue.push(2);
        j.fetch_add(1, std::memory_order_relaxed);
    }
    std::cout << "Done 2\n";
}

int main()
{
    j.store(0);
    std::thread first(push_to_queue1, 100000);
    std::thread second(push_to_queue2, 100000);

    std::cout << "created threads, now adding in main\n";
    for (int i = 0; i < 1000000; ++i) {
        queue.push(i);
        j.fetch_add(1, std::memory_order_relaxed);
    }

    std::cout << "now joining the threads\n";
    first.join();
    second.join();
    std::cout << "done\n"
              << "iterations: " << j << "\n";
}
