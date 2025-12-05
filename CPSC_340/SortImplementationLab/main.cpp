#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <string>
#include <fstream>

// Type alias for a sorting function
using SortFunction = std::function<void(std::vector<int>&)>;

// Using older function pointer syntax
// using SortFunction = void (*)(std::vector<int>&);

// Or even older function pointer syntax
// typedef void (*SortFunction)(std::vector<int>&);

// Function to generate an array of random integers
std::vector<int> generateRandomArray(int size, int minVal = 0, int maxVal = 10000) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minVal, maxVal);

    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }

    return arr;
}

// Function to generate an almost sorted array (useful for testing adaptive algorithms)
std::vector<int> generateAlmostSortedArray(int size, double disorderFactor = 0.05) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    // Calculate number of swaps based on array size and disorder factor
    int swapsToPerform = static_cast<int>(size * disorderFactor);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, size - 1);

    for (int i = 0; i < swapsToPerform; i++) {
        int pos1 = dis(gen);
        int pos2 = dis(gen);
        std::swap(arr[pos1], arr[pos2]);
    }

    return arr;
}

// Function to generate a reverse sorted array (worst case for some algorithms)
std::vector<int> generateReverseSortedArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }
    return arr;
}

// Function to time a sorting algorithm
double timeSort(SortFunction sortFunc, std::vector<int>& arr) {
    // Make a copy of the array, so the original doesn't get modified
    std::vector<int> arrCopy = arr;

    // Record starting time
    auto start = std::chrono::high_resolution_clock::now();

    // Execute the sorting function
    sortFunc(arrCopy);

    // Record ending time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;

    // Verify the array is sorted correctly
    for (int i = 1; i < arrCopy.size(); i++) {
        if (arrCopy[i] < arrCopy[i - 1]) {
            std::cerr << "Error: Array not sorted correctly!" << std::endl;
            break;
        }
    }

    return duration.count();
}

// Function to run benchmarks for a given sorting algorithm
void benchmark(SortFunction sortFunc, const std::string& algName,
               const std::vector<int>& sizes, int repetitions = 3,
               std::ostream& output = std::cout) {

    output << "Benchmarking " << algName << ":\n";
    output << std::setw(10) << "Size" << std::setw(15) << "Random (ms)"
           << std::setw(15) << "Almost (ms)" << std::setw(15) << "Reverse (ms)" << "\n";
    output << std::string(55, '-') << "\n";

    for (int size : sizes) {
        double randomTime = 0, almostTime = 0, reverseTime = 0;

        for (int rep = 0; rep < repetitions; rep++) {
            // Test with random array
            std::vector<int> randomArr = generateRandomArray(size);
            randomTime += timeSort(sortFunc, randomArr);

            // Test with almost sorted array
            std::vector<int> almostArr = generateAlmostSortedArray(size);
            almostTime += timeSort(sortFunc, almostArr);

            // Test with reverse sorted array
            std::vector<int> reverseArr = generateReverseSortedArray(size);
            reverseTime += timeSort(sortFunc, reverseArr);
        }

        // Calculate averages
        randomTime /= repetitions;
        almostTime /= repetitions;
        reverseTime /= repetitions;

        // Output results
        output << std::setw(10) << size
               << std::setw(15) << std::fixed << std::setprecision(2) << randomTime
               << std::setw(15) << std::fixed << std::setprecision(2) << almostTime
               << std::setw(15) << std::fixed << std::setprecision(2) << reverseTime << "\n";
    }

    output << "\n";
}

// STUDENT TASK: Implement selection sort
void selectionSort(std::vector<int>& arr) {
    // TODO: Implement selection sort algorithm
    for (int i = arr.size()-1; i >= 0; i--) {
        int maxIndex = i;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j; //Set the new maxNumber
            }
        }
        std::swap(arr[i], arr[maxIndex]); //Swap places
    }
}

// STUDENT TASK: Implement insertion sort
void insertionSort(std::vector<int>& arr) {
    // TODO: Implement selection sort algorithm
    for (int i = 1; i < arr.size(); i++) {
        while (i > 0 && arr[i] < arr[i - 1]) { // Doesn't check if index is 0 and previous is less than the value
            // Swap indexes
            std::swap(arr[i - 1], arr[i]);
            i--; // Update the index
        }
    }
}

// STUDENT TASK: Implement bubble sort
void bubbleSort(std::vector<int>& arr) {
    // TODO: Implement bubble sort algorithm with early termination optimization
    for (int i = 1; i < arr.size(); i++) {
        for (int j = 0; j < arr.size()-i; j++) {
            if (arr[j] > arr[j+1])
                std::swap(arr[j], arr[j+1]);
        }
    }
}

// STUDENT TASK: Implement merge sort
void mergeSort(std::vector<int>& arr) {
    // TODO: Implement merge sort algorithm
    if (arr.size() < 2) { //If the array is empty or has 1 element
        return;
    }
    // Divide
    int halfSize = arr.size() / 2; // Get the halfway point of the array
    std::vector left(arr.begin(), arr.begin() + halfSize);
    std::vector right(arr.begin() + halfSize, arr.end());
    mergeSort(left);
    mergeSort(right);

    // Merge
    arr = {}; // Clear the array
    while (!left.empty() || !right.empty()) { // Stops if left and right are both empty
        if (left.empty()) { // Add all of right if left is empty
            arr.push_back(right.front());
            right.erase(right.begin());
        } else if (right.empty()) { // Add all of left if right is empty
            arr.push_back(left.front());
            left.erase(left.begin());
        } else if (left.front() <= right.front()) { // Adds the lowest of the 2 arrays
            arr.push_back(left.front());
            left.erase(left.begin());
        } else if (right.front() <= left.front()) {
            arr.push_back(right.front());
            right.erase(right.begin());
        }
    }
}

// A template for STL sort for comparison
void stlSort(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
}

int main() {
    // Array sizes to test with
    std::vector<int> sizes = {10, 20, 100, 1000, 10000};

    // For very small arrays, you can include 10, 20, etc.
    // For larger arrays, be careful with the O(n²) algorithms

    // Create output file for results
    std::ofstream resultsFile("sorting_results.txt");
    if (!resultsFile.is_open()) {
        std::cerr << "Failed to open results file!" << std::endl;
        return 1;
    }

    // Print header
    std::cout << "Running sorting algorithm benchmarks...\n\n";
    resultsFile << "SORTING ALGORITHM BENCHMARKS\n";
    resultsFile << "===========================\n\n";

    // Register and benchmark all sorting algorithms
    // Comment out algorithms you haven't implemented yet

    // Uncomment each sorting algorithm as you implement it
    benchmark(selectionSort, "Selection Sort", sizes, 3, resultsFile);
    benchmark(insertionSort, "Insertion Sort", sizes, 3, resultsFile);
    benchmark(bubbleSort, "Bubble Sort", sizes, 3, resultsFile);
    benchmark(mergeSort, "Merge Sort", sizes, 3, resultsFile);

    // Always include STL sort for comparison
    benchmark(stlSort, "STL Sort", sizes, 3, resultsFile);

    std::cout << "Benchmarks complete. Results written to sorting_results.txt\n";

    return 0;
}