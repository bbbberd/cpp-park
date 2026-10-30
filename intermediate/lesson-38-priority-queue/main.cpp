#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Job {
    std::string name;
    int priority;
};

struct HigherPriority {
    bool operator()(const Job &a, const Job &b) const { return a.priority < b.priority; }
};

int main() {

    // 1. Max-heap: nilai terbesar diproses lebih dahulu.
    std::priority_queue<int> maxHeap;

    maxHeap.push(2);
    maxHeap.push(8);
    maxHeap.push(5);

    std::cout << "MAX HEAP\n";

    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << '\n';
        maxHeap.pop();
    }

    // 2. Min-heap: nilai terkecil diproses lebih dahulu.
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    minHeap.push(8);
    minHeap.push(2);
    minHeap.push(5);

    std::cout << "\nMIN HEAP\n";

    while (!minHeap.empty()) {
        std::cout << minHeap.top() << '\n';
        minHeap.pop();
    }

    // 3. Prioritas pekerjaan
    std::priority_queue<Job, std::vector<Job>, HigherPriority> jobs;

    jobs.push({"Generate report", 2});
    jobs.push({"Process payment", 10});
    jobs.push({"Send notification", 5});

    std::cout << "\nJOB PRIORITY\n";

    while (!jobs.empty()) {
        const Job &job = jobs.top();

        std::cout << job.name << " (priority " << job.priority << ")\n";
        jobs.pop();
    }

    return 0;
}
