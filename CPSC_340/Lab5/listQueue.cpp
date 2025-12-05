//
// Created by Victoria Jackson on 9/23/2025.
//

#include "listQueue.h"
#include <list>
using std::list;

listQueue::listQueue() = default;

void listQueue::enqueue(int value) {
    this->storage.push_front(value);
    //Adding value to the front of the list (add and update pointer)
}

int listQueue::dequeue() {
    int last = this->storage.back();
    this->storage.pop_back();
    return last;
}