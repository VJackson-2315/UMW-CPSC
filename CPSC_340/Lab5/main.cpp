#include <iostream>
#include <stack>
#include <queue>
#include <chrono>

#include "arrayQueue.h"
#include "listQueue.h"

using std::stack, std::queue;
using std::cout, std::endl;

void processStack(int n) {
    stack<int> myStack;
    for (int i = 1; i <= n; i++) {
        myStack.push(i);
    }
    for (int i = 1; i <= n; i++) {
        myStack.pop();
    }
}

void processQueue(int n) {
    queue<int> myQueue;
    for (int i = 1; i <= n; i++) {
        myQueue.push(i);
    }
    for (int i = 1; i <= n; i++) {
        myQueue.pop();
    }
}

void processArrayQueue(int n) {
    arrayQueue myArray;
    for (int i = 1; i <= n; i++) {
        myArray.enqueue(i);
    }
    for (int i = 1; i <= n; i++) {
        myArray.dequeue();
    }
}

void processListQueue(int n) {
    listQueue myArray;
    for (int i = 1; i <= n; i++) {
        myArray.enqueue(i);
    }
    for (int i = 1; i <= n; i++) {
        myArray.dequeue();
    }
}

int main() {
    int average = 0;
    for (int i = 1; i <= 5; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        processArrayQueue(1'000'000);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout << "Time: " << duration.count() << " microseconds" << endl;
        average += duration.count();
    }
    average /= 5;
    cout << "Average: " << average << endl;
    return 0;
}