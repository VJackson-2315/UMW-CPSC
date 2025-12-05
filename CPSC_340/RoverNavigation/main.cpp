/**
* ExoNav: Alien Planet Rover Navigation System
* main.cpp - Entry point for the application
*/
#include "Code.h"
#include "PathFinder.h"
#include <iostream>
#include <ctime>

int main() {
    std::cout << "ExoNav: Alien Planet Rover Navigation System\n";
    std::cout << "============================================\n\n";

    // Seed the random number generator
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    //For presentation
    seed = 152673;

    // Create the mission control with a planet
    MissionControl mission(GRID_WIDTH, GRID_HEIGHT);
    mission.generatePlanet(NUM_LANDMARKS, seed);

    // Menu loop
    bool quit = false;
    while (!quit) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Visit all landmarks using Dijkstra's Algorithm\n";
        std::cout << "2. Find path to specific landmark using Uniform Cost Search\n";
        std::cout << "3. List all landmarks on the planet\n";
        std::cout << "4. Show planet visualization\n";
        std::cout << "5. Generate new planet\n";
        std::cout << "6. Quit\n";
        std::cout << "Enter choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Consume newline
        switch (choice) {
            case 1:
                mission.runMission();
                break;
            case 2: {
                std::cout << "Enter landmark index (0-" << (NUM_LANDMARKS-1) << "):";
                int index;
                std::cin >> index;
                std::cin.ignore(); // Consume newline
                mission.findPathToLandmark(index);
                break;
            }
            case 3:
                mission.displayLandmarkList();
                break;
            case 4:
                mission.displayPlanet();
                break;
            case 5: {
                std::cout << "Enter number of landmarks: ";
                int numLandmarks;
                std::cin >> numLandmarks;
                std::cin.ignore(); // Consume newline
                // Use a new random seed
                unsigned int newSeed = static_cast<unsigned int>(time(nullptr));
                mission.generatePlanet(numLandmarks, newSeed);
                break;
            }
            case 6:
                quit = true;
                break;
            default:
                std::cout << "Invalid choice! Try again.\n";
        }
    }
    std::cout << "Thank you for using ExoNav!\n";
    return 0;
}