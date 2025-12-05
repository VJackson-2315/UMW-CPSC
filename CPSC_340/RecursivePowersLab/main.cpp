#include <iostream>
#include <chrono>

int powerOf(int x, int y) {
    //Base cases
    if (x == 0) {
        return 0;
    }
    if ((y == 0) || (x == 1)) {
        return 1;
    }
    if (y == 1) {
        return x;
    }

    // Recursions
    if (y % 2 == 0) { //Y is even
        return powerOf(x,y/2) * powerOf(x,y/2);
    }
    if ((y % 2 != 0) && (y > 1)) { //Y is odd and not 1
        return powerOf(x,(y-1)/2) * powerOf(x,(y-1)/2) * x;
    }
}

// int powerLoop(int x, int y) { // For testing only
//     int result = 1;
//     for (int i = 0; i < y; i++) {
//         result *= x;
//     }
//     return result;
// }

int main() {

    //Chrono used to test differences in time between the 2 functions
    // auto start = std::chrono::high_resolution_clock::now();
    std::cout << powerOf(2,15) << std::endl;
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // std::cout << "Time: " << duration.count() << " microseconds" << std::endl;

    // start = std::chrono::high_resolution_clock::now();
    // std::cout << powerLoop(2,15) << std::endl;
    // end = std::chrono::high_resolution_clock::now();
    // duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
    return 0;
}