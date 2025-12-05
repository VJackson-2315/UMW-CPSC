#include "testArray.h"
#include <iostream>

TestArray::TestArray() {
    std::cout << "TestArray constructor" << std::endl;
    std::cout << "Allocating some memory on the heap" << std::endl;
    heapArray = new int[10];
    size = 0;
    capacity = 10;

    for (int i = 0; i < capacity; i++) {
        heapArray[i] = 0;
    }
}

TestArray::TestArray(int size) {
    std::cout << "TestArray constructor #2" << std::endl;

    for (int i = 0; i < size; i++) {
        heapArray[i] = 0;
    }

    std::cout << "Allocating some memory on the heap" << std::endl;
    heapArray = new int[size];
    capacity = size;

    for (int i = 0; i < capacity; i++) {
        heapArray[i] = 0;
    }
}

TestArray::~TestArray() {
    std::cout << "TestArray destructor" << std::endl;
    delete[] heapArray;
}

void TestArray::print() {
    std::cout << "TestArray::printArray" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << heapArray[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < capacity; i++) {
        std::cout << heapArray[i] << " ";
    }
    std::cout << std::endl;
}

void TestArray::add(int value) {
    std::cout << "TestArray::add " << value << std::endl;
    if (size < capacity) {
        heapArray[size] = value;
        size++;
    }
}

void TestArray::insert(int index, int value) {
    std::cout << "TestArray::insert " << value << " at index " << index << std::endl;
    if (size < capacity) {
        size++;
        int *tempArray = new int[size];
        tempArray;
        int x = 0;
        for (int i = 0; i < size; i++) {
            if (i != index) {
                tempArray[i] = heapArray[x];
                x++;
            } else {
               tempArray[i] = value;
                index = 0;
            }
        }
        heapArray = tempArray;
    }
}

void TestArray::remove(int index) {
    std::cout << "TestArray::remove " << index << std::endl;

    size--;
    int *tempArray = new int[size];
    tempArray = heapArray;
    int x = 0;

    for (int i = 0; i <= size; i++) {
        if (i != index) {
            tempArray[i] = heapArray[x];
        } else {
            x++;
            tempArray[i] = heapArray[x];
        }
        x++;
    }

    heapArray = tempArray;
}

// int& TestArray::operator[](size_t index) {
//     return heapArray[index];
// }
//backup for project:
void TestArray::change(int index, int value) {
    std::cout << "TestArray::change index " << index << " to " << value << std::endl;
    heapArray[index] = value;
}

int TestArray::get(int index) {
    std::cout << "TestArray::get value at index " << index << std::endl;
    return heapArray[index];
}

int TestArray::add(int index, int value) {
    std::cout << "TestArray::add " << value << " to index " << index << std::endl;
    heapArray[index] += value;
}

int TestArray::subtract(int index, int value) {
    std::cout << "TestArray::subtract " << value << " to index " << index << std::endl;
    heapArray[index] -= value;
}

//backup end

void TestArray::swap(int index1, int index2) {
    std::cout << "TestArray::swap indexes " << index1 << " and " << index2 << std::endl;
    int holder = heapArray[index1];
    heapArray[index1] = heapArray[index2];
    heapArray[index2] = holder;
}

int TestArray::getSize() {
    return size;
}

int TestArray::getCapacity() {
    return capacity;
}

void TestArray::resize(size_t newCapacity) {
    // Make a new array
    int* newArray = new int[newCapacity];

    // Copy the array
    for (size_t i = 0; i < size; i++) {
        newArray[i] = heapArray[i];
    }

    // Clean up the old array
    delete[] heapArray;

    // Update pointer
    heapArray = newArray;
}