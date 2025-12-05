//
// Created by Victoria Jackson on 9/23/2025.
//

#include "arrayQueue.h"
#include <vector>
using std::vector;

arrayQueue::arrayQueue() = default;

void arrayQueue::enqueue(int value) {
    this->storage.insert(this->storage.begin(), value);
    // Inserts new value at the beginning of storage vector

}

int arrayQueue::dequeue() {
    int last = this->storage.back(); // Copies last item in vector
    this->storage.pop_back(); // Removes last item
    return last; // Returns last item
}