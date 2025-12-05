//
// Created by Victoria Jackson on 9/23/2025.
//

#ifndef LAB5_ARRAYQUEUE_H
#define LAB5_ARRAYQUEUE_H
#include <vector>
using std::vector;


class arrayQueue {
public:
    arrayQueue();
    void enqueue(int value);
    int dequeue();

private:
    vector<int> storage;
};


#endif //LAB5_ARRAYQUEUE_H