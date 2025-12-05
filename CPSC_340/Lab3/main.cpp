#include <iostream>
#include <vector> //ArrayList
#include <list>
#include <chrono>

using std::cout, std::cin, std::endl, std::list, std::vector;

// Speed in adding an element to the beginning
// Speed in adding an element to the middle
// Speed in deleting an element to the beginning
// Speed in deleting an element to the middle
// Speed in deleting an element to the end

int main() {
    list<int> myList;
    vector<int> myVector;
    int trials = 5;

    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    for (int i = 0; i < 10000; i++) {
        myVector.push_back(i); // adds elements
        myList.push_back(i);
    }

    int result = 0;

    // Adding at the front
    // for (int i = 0; i < trials; i++) {
    //     start = std::chrono::high_resolution_clock::now();
    //     myList.push_front(1);
    //     end = std::chrono::high_resolution_clock::now();
    //     duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //     cout << "Linked List time: " << duration.count() << " microseconds" << endl;
    //     result += duration.count();
    // }
    //
    // for (int i = 0; i < trials; i++) {
    //     start = std::chrono::high_resolution_clock::now();
    //     myVector.insert(myVector.begin(), 10);
    //     end = std::chrono::high_resolution_clock::now();
    //     duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //     cout << "Array List time: " << duration.count() << " microseconds" << endl;
    //     result += duration.count();
    // }

    // Adding at the middle
    // for (int i = 0; i < trials; i++) {
    //     start = std::chrono::high_resolution_clock::now();
    //     auto myIterator = myList.begin();
    //     std::advance(myIterator, myList.size() / 2);
    //     myList.insert(myIterator, 10);
    //     end = std::chrono::high_resolution_clock::now();
    //     duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //     cout << "Linked List time: " << duration.count() << " microseconds" << endl;
    //     result += duration.count();
    // }

    // for (int i = 0; i < trials; i++) {
    //     auto size = myVector.size();
    //     int middle = (static_cast<int>(size)) / 2;
    //     start = std::chrono::high_resolution_clock::now();
    //     myVector.insert(myVector.begin()+middle, 10);
    //     end = std::chrono::high_resolution_clock::now();
    //     duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //     cout << "Array List time: " << duration.count() << " microseconds" << endl;
    //     result += duration.count();
    // }

    // Adding at the end
    // for (int i = 0; i < trials; i++) {
    //     start = std::chrono::high_resolution_clock::now();
    //     myList.push_back(1);
    //     end = std::chrono::high_resolution_clock::now();
    //     duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //     cout << "Linked List time: " << duration.count() << " microseconds" << endl;
    //     result += duration.count();
    // }

    // for (int i = 0; i < trials; i++) {
    //     start = std::chrono::high_resolution_clock::now();
    //     myVector.push_back(1);
    //     end = std::chrono::high_resolution_clock::now();
    //     duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //     cout << "Array List time: " << duration.count() << " microseconds" << endl;
    //     result += duration.count();
    // }

    // Removing at the front
    // for (int i = 0; i < trials; i++) {
    //     start = std::chrono::high_resolution_clock::now();
    //     auto myIterator = myList.begin();
    //     myList.remove(*myIterator);
    //     end = std::chrono::high_resolution_clock::now();
    //     duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //     cout << "Linked List time: " << duration.count() << " microseconds" << endl;
    //     result += duration.count();
    // }

    // for (int i = 0; i < trials; i++) {
    //     start = std::chrono::high_resolution_clock::now();
    //     myVector.erase(myVector.begin());
    //     end = std::chrono::high_resolution_clock::now();
    //     duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //     cout << "Array List time: " << duration.count() << " microseconds" << endl;
    //     result += duration.count();
    // }

    // Removing at the middle
    // for (int i = 0; i < trials; i++) {
    //     start = std::chrono::high_resolution_clock::now();
    //     auto myIterator = myList.begin();
    //     std::advance(myIterator, myList.size() / 2);
    //     myList.remove(*myIterator);
    //     end = std::chrono::high_resolution_clock::now();
    //     duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //     cout << "Linked List time: " << duration.count() << " microseconds" << endl;
    //     result += duration.count();
    // }

    // for (int i = 0; i < trials; i++) {
    //     auto size = myVector.size();
    //     int middle = (static_cast<int>(size)) / 2;
    //     start = std::chrono::high_resolution_clock::now();
    //     myVector.erase(myVector.begin()+middle);
    //     end = std::chrono::high_resolution_clock::now();
    //     duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //     cout << "Array List time: " << duration.count() << " microseconds" << endl;
    //     result += duration.count();
    // }

    // Removing at the end
    // for (int i = 0; i < trials; i++) {
    //     start = std::chrono::high_resolution_clock::now();
    //     auto myIterator = myList.end();
    //     myList.remove(*myIterator);
    //     end = std::chrono::high_resolution_clock::now();
    //     duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //     cout << "Linked List time: " << duration.count() << " microseconds" << endl;
    //     result += duration.count();
    // }

    for (int i = 0; i < trials; i++) {
        start = std::chrono::high_resolution_clock::now();
        myVector.erase(myVector.end());
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout << "Array List time: " << duration.count() << " microseconds" << endl;
        result = duration.count();
    }

    result /= trials;
    cout << result << endl;

    return 0;
}