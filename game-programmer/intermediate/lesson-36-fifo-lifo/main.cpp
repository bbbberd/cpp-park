#include <iostream>
#include <queue>
#include <stack>

int main() {

    // FIFO, pertama masuk pertama keluar (kentang pringles bolong bawahnya)
    std::queue<int> jobs;
    jobs.push(101);
    jobs.push(102);
    jobs.push(103);

    std::cout << "QUEUE: FIFO\n";
    while (!jobs.empty()) {
        const int job = jobs.front();
        jobs.pop();

        std::cout << "Processing job: " << job << '\n';
    }

    std::stack<int> history;

    history.push(10);
    history.push(20);
    history.push(30);

    // LIFO, masuk pertama keluar terakhit (kentang pringles normal)
    std::cout << "\nSTACK: LIFO\n";
    while (!history.empty()) {
        const int operation = history.top();
        history.pop();
        std::cout << "Undo operation: " << operation << '\n';
    }

    return 0;
}
