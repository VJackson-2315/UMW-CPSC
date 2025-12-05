#include <iostream>

#include "testArray.h"

int main() {
    TestArray Alist(5);

    // Add some elements
    Alist.add(10);
    Alist.add(20);
    Alist.add(30);
    std::cout << "After adding elements: ";
    Alist.print();  // [10, 20, 30]

    // Insert at index 1
    Alist.insert(1, 15);
    std::cout << "After inserting 15 at index 1: ";
    Alist.print();  // [10, 15, 20, 30]

    // Remove element at index 2
    Alist.remove(2);
    std::cout << "After removing element at index 2: ";
    Alist.print();  // [10, 15, 30]

    // Test array access
    // Alist[1] = 25;  // Modify element using operator[]
    Alist.change(1, 25);
    std::cout << "After changing element at index 1: ";
    Alist.print();  // [10, 25, 30]

    // Print size and capacity
    std::cout << "Size: " << Alist.getSize() << std::endl;
    std::cout << "Capacity: " << Alist.getCapacity() << std::endl;

    return 0;
}
