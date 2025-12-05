#include <iostream>
#include <chrono>

// Naive recursive implementation
unsigned long long fibonacci(unsigned int n) {
    // Base cases
    if (n <= 1 || n == 5) {
        return n;
    } if (n <= 4) {
        return n-1;
    }
    // 48 = 4807526976
    // Recursive case: F(n) = F(n-1) + F(n-2)
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    // Test with various inputs
    for (unsigned int i = 48; i <= 55; i += 1) {
        auto start = std::chrono::high_resolution_clock::now();
        unsigned long long result = fibonacci(i);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duration = end - start;

        std::cout << "fibonacci(" << i << ") = " << result
                  << " (calculated in " << duration.count() << " ms)" << std::endl;

        if (duration.count() >= 10000) {
            std::cout << duration.count() << std::endl;
            break;
        }
    }
    return 0;
}