//
// Created by Victoria Jackson on 9/23/2025.
//

#ifndef LAB5_LISTQUEUE_H
#define LAB5_LISTQUEUE_H
#include <list>
using std::list;

class listQueue {
public:
    listQueue();
    void enqueue(int value);
    int dequeue();

private:
    list<int> storage;
};


#endif //LAB5_LISTQUEUE_H