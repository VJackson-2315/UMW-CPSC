//
// Created by Evan Coleman on 1/16/25.
//

#ifndef TESTARRAY_H
#define TESTARRAY_H
#include <iostream>

class TestArray {
    public:
        //Constructor (default)
        TestArray();

        //Constructor (with size)
        TestArray(int size);

        //Destructor
        ~TestArray();

        void add(int value);

        void insert(int index, int value);

        void remove(int index);

        void print();

        int& operator[](size_t index);
        //backup for project
        void change(int index, int value);

        int get(int index);

        int add(int index, int value);

        int subtract(int index, int value);
        //backup end

        void swap(int index1, int index2);

        int getSize();

        int getCapacity();

    private:
        void resize(size_t newCapacity);
        int size; //array
        int capacity; //heapArraySize
        int* heapArray;
    //protected:
};


#endif //TESTARRAY_H
