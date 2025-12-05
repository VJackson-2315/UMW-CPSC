/**
* ExoNav: Alien Planet Rover Navigation System
* Code.cpp - Implementations for all classes except PathFinder
*/
#include "Code.h"
#include "PathFinder.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <limits>
#include <cmath>
#include <ctime>
#include <functional>
#include <iomanip>
#include <sstream>

#ifdef _WIN32
#include <windows.h>
#endif
// =============================================================================
// Constants Initialization
// =============================================================================
// Colors for console output
namespace Color {
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN = "\033[36m";
    const std::string BOLD = "\033[1m";

    #ifdef _WIN32
    // Helper function to enable ANSI escape sequences for Windows 10/11
    bool EnableWindowsANSI() {
        // Set output mode to handle virtual terminal sequences
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut == INVALID_HANDLE_VALUE) {
            return false;
        }
        DWORD dwMode = 0;
        if (!GetConsoleMode(hOut, &dwMode)) {
            return false;
        }
        dwMode |= 0x0004; // ENABLE_VIRTUAL_TERMINAL_PROCESSING
        return SetConsoleMode(hOut, dwMode);
    }
    // Force the function to run at static initialization time
    static const bool _ignored = EnableWindowsANSI();
#endif
}

// =============================================================================
// Landmark Class Implementation
// =============================================================================

Landmark::Landmark(const std::string& n, const Point& pos, const std::string& desc)
: name(n), position(pos), description(desc) {}
const std::string& Landmark::getName() const { return name; }
const Point& Landmark::getPosition() const { return position; }
const std::string& Landmark::getDescription() const { return description; }

// =============================================================================
// ElevationMap Class Implementation
// =============================================================================

ElevationMap::ElevationMap(int w, int h) : width(w), height(h) {
    elevationData.resize(height, std::vector<int>(width, 0));
}

void ElevationMap::generateElevation(std::mt19937& rng) {
    // Simple implementation - in a real project, use proper Perlin noise
    std::uniform_int_distribution<int> baseElevDist(0, 10);
    // Create some random "peaks"
    std::uniform_int_distribution<int> numPeaksDist(3, 8);
    int numPeaks = numPeaksDist(rng);
    std::vector<Point> peaks;
    std::vector<int> peakHeights;
    std::uniform_int_distribution<int> xDist(0, width - 1);
    std::uniform_int_distribution<int> yDist(0, height - 1);
    std::uniform_int_distribution<int> heightDist(5, 20);
    for (int i = 0; i < numPeaks; i++) {
        peaks.push_back({xDist(rng), yDist(rng)});
        peakHeights.push_back(heightDist(rng));
    }
    // Generate elevation based on distance from peaks
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int elevation = baseElevDist(rng);
            // Add influence from each peak
            for (size_t i = 0; i < peaks.size(); i++) {
                int dx = x - peaks[i].x;
                int dy = y - peaks[i].y;
                int distSquared = dx*dx + dy*dy;
                // Inverse square influence from each peak
                if (distSquared > 0) {
                    elevation += peakHeights[i] / (1 + std::sqrt(distSquared));
                } else {
                    elevation += peakHeights[i];
                }
            }
            elevationData[y][x] = elevation;
        }
    }
}

int ElevationMap::getElevation(const Point& p) const {
    if (p.x >= 0 && p.x < width && p.y >= 0 && p.y < height) {
        return elevationData[p.y][p.x];
    }
    return 0; // Default for out of bounds
}

// =============================================================================
// AlienPlanet Class Implementation
// =============================================================================

AlienPlanet::AlienPlanet(int w, int h) : width(w), height(h), elevationMap(w, h) {
    terrain.resize(height, std::vector<TerrainType>(width));
}

std::string AlienPlanet::generateLandmarkName(std::mt19937& rng) {
    std::vector<std::string> prefixes = {
        "Mount", "Crater", "Valley", "Ridge", "Plains of", "Sea of", "Canyon",
        "Basin", "Mons", "Olympus", "Tharsis", "Valles", "Planitia", "Chasma"
    };

    std::vector<std::string> suffixes = {
        "Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Zeta", "Eta", "Theta",
        "Aristarchus", "Copernicus", "Kepler", "Tycho", "Gassendi", "Archimedes",
        "Huygens", "Cassini", "Flamsteed", "Grimaldi", "Langrenus", "Plato"
    };

    std::uniform_int_distribution<size_t> prefixDist(0, prefixes.size() - 1);
    std::uniform_int_distribution<size_t> suffixDist(0, suffixes.size() - 1);
    return prefixes[prefixDist(rng)] + " " + suffixes[suffixDist(rng)];
}

std::string AlienPlanet::generateLandmarkDescription(std::mt19937& rng) {
    std::vector<std::string> descriptions = {
        "Ancient ruins of unknown origin",
        "Unusual rock formation with trace elements",
        "Site of geological anomaly",
        "Location of water ice deposits",
        "Area with high mineral concentration",
        "Magnetic anomaly region",
        "Bio-signature detection zone",
        "Unusual atmospheric conditions",
        "Solar radiation hot spot",
        "Subterranean cave network entrance"
    };
    std::uniform_int_distribution<size_t> descDist(0, descriptions.size() - 1);
    return descriptions[descDist(rng)];
}

void AlienPlanet::generate(int numLandmarks, unsigned int seed) {
    // Set up random number generator
    std::mt19937 rng;
    if (seed == 0) {
        rng.seed(static_cast<unsigned int>(std::time(nullptr)));
    } else {
        rng.seed(seed);
    }

    // Generate elevation data
    elevationMap.generateElevation(rng);
    // Generate terrain based on elevation
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Point p = {x, y};
            int elevation = elevationMap.getElevation(p);
            // Assign terrain based on elevation
            if (elevation < 3) {
                terrain[y][x] = TerrainType::PLAINS;
            } else if (elevation < 6) {
                terrain[y][x] = TerrainType::ROCKY;
            } else if (elevation < 10) {
                terrain[y][x] = TerrainType::SANDY;
            } else if (elevation < 15) {
                terrain[y][x] = TerrainType::MOUNTAINS;
            } else {
                terrain[y][x] = TerrainType::CRATER_RIM;
            }
            // Randomly place some impassable terrain
            std::uniform_real_distribution<double> impassableDist(0.0, 1.0);
            if (impassableDist(rng) < 0.08) { // 8% chance of impassable
                terrain[y][x] = TerrainType::IMPASSABLE;
            }
        }
    }
    // Place landmarks
    placeLandmarks(numLandmarks, rng);
    // Place rover at a random valid position
    placeRover(rng);
}

void AlienPlanet::placeLandmarks(int numLandmarks, std::mt19937& rng) {
    std::uniform_int_distribution<int> xDist(0, width - 1);
    std::uniform_int_distribution<int> yDist(0, height - 1);
    landmarks.clear();
    for (int i = 0; i < numLandmarks; i++) {
        Point pos;
        // Find a valid position (not impassable)
        do {
            pos = {xDist(rng), yDist(rng)};
        } while (terrain[pos.y][pos.x] == TerrainType::IMPASSABLE);
            // Create landmark with random name and description
            std::string name = generateLandmarkName(rng);
            std::string description = generateLandmarkDescription(rng);
            landmarks.emplace_back(name, pos, description);
    }
}

void AlienPlanet::placeRover(std::mt19937& rng) {
    std::uniform_int_distribution<int> xDist(0, width - 1);
    std::uniform_int_distribution<int> yDist(0, height - 1);
    // Find a valid position (not impassable, not on a landmark)
    do {
        roverPosition = {xDist(rng), yDist(rng)};
    } while (terrain[roverPosition.y][roverPosition.x] == TerrainType::IMPASSABLE || isLandmarkAt(roverPosition));
}

int AlienPlanet::getWidth() const { return width; }

int AlienPlanet::getHeight() const { return height; }

TerrainType AlienPlanet::getTerrain(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return terrain[y][x];
    }
    return TerrainType::IMPASSABLE; // Out of bounds is impassable
}

TerrainType AlienPlanet::getTerrain(const Point& p) const {
    return getTerrain(p.x, p.y);
}

const std::vector<Landmark>& AlienPlanet::getLandmarks() const {
    return landmarks;
}

const Point& AlienPlanet::getRoverPosition() const {
    return roverPosition;
}

void AlienPlanet::setRoverPosition(const Point& newPos) {
    if (newPos.x >= 0 && newPos.x < width &&
    newPos.y >= 0 && newPos.y < height &&
    terrain[newPos.y][newPos.x] != TerrainType::IMPASSABLE) {
        roverPosition = newPos;
    }
}

int AlienPlanet::getElevation(const Point& p) const {
    return elevationMap.getElevation(p);
}

bool AlienPlanet::isLandmarkAt(const Point& p) const {
    for (const auto& landmark : landmarks) {
        if (landmark.getPosition() == p) {
            return true;
        }
    }
    return false;
}

const Landmark* AlienPlanet::getLandmarkAt(const Point& p) const {
    for (const auto& landmark : landmarks) {
        if (landmark.getPosition() == p) {
            return &landmark;
        }
    }
    return nullptr;
}

// =============================================================================
// PlanetGraph Class Implementation
// =============================================================================

PlanetGraph::~PlanetGraph() {
    for (Node* node : nodes) {
        delete node;
    }
}

int PlanetGraph::calculateMovementCost(const Point& from, const Point& to, TerrainType terrainType, int fromElev, int  toElev) {
    // Base cost from terrain
    int baseCost = static_cast<int>(terrainType);
    // Add additional costs based on elevation changes
    int elevationChange = std::abs(toElev - fromElev);
    // Diagonal movement costs more than cardinal directions
    bool isDiagonal = (from.x != to.x && from.y != to.y);
    double diagMultiplier = isDiagonal ? 1.4 : 1.0;
    // Combine all factors - terrain cost, elevation factor, and diagonal factor
    return static_cast<int>(baseCost * (1.0 + elevationChange * 0.2) *
    diagMultiplier);
}

void PlanetGraph::buildGraph(const AlienPlanet& planet) {
    // Clear existing data
    for (Node* node : nodes) {
        delete node;
    }

    nodes.clear();
    pointToNode.clear();
    // Create nodes for each traversable position
    for (int y = 0; y < planet.getHeight(); y++) {
        for (int x = 0; x < planet.getWidth(); x++) {
            Point pos = {x, y};
            TerrainType terrain = planet.getTerrain(pos);
            // Skip impassable terrain
            if (terrain == TerrainType::IMPASSABLE) {
                continue;
            }
            // Create node
            Node* node = new Node();
            node->position = pos;
            node->terrain = terrain;
            node->elevation = planet.getElevation(pos);
            nodes.push_back(node);
            pointToNode[pos] = node;
        }
    }

    // Connect nodes with edges
    for (Node* node : nodes) {
        // Check all 8 directions (cardinal + diagonals)
        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                if (dx == 0 && dy == 0) continue; // Skip self
                Point neighborPos = {node->position.x + dx, node->position.y + dy};
                // Find the neighboring node
                auto neighborIt = pointToNode.find(neighborPos);
                if (neighborIt != pointToNode.end()) {
                    Node* neighbor = neighborIt->second;
                    // Calculate the cost of moving to this neighbor
                    int cost = calculateMovementCost(
                    node->position, neighborPos,
                    neighbor->terrain,
                    node->elevation, neighbor->elevation);
                    // Add edge to this neighbor
                    node->edges.push_back({neighbor, cost});
                }
            }
        }
    }
}

Node* PlanetGraph::findNodeAtPosition(const Point& position) {
    auto it = pointToNode.find(position);
    if (it != pointToNode.end()) {
        return it->second;
    }
    return nullptr;
}

const std::vector<Node*>& PlanetGraph::getNodes() const {
    return nodes;
}

int PlanetGraph::calculatePathCost(const std::vector<Node*>& path) const {
    int totalCost = 0;
    for (size_t i = 1; i < path.size(); i++) {
        Node* current = path[i-1];
        Node* next = path[i];
        // Find the edge connecting these nodes
        for (const Edge& edge : current->edges) {
            if (edge.destination == next) {
                totalCost += edge.cost;
                break;
            }
        }
    }
    return totalCost;
}

// =============================================================================
// PlanetVisualizer Class Implementation
// =============================================================================

char PlanetVisualizer::getTerrainSymbol(TerrainType terrain) {
    switch (terrain) {
        case TerrainType::PLAINS: return '.';
        case TerrainType::ROCKY: return ':';
        case TerrainType::SANDY: return '~';
        case TerrainType::MOUNTAINS: return '^';
        case TerrainType::CRATER_RIM: return 'o';
        case TerrainType::IMPASSABLE: return '#';
        default: return '?';
    }
}

std::string PlanetVisualizer::getTerrainColor(TerrainType terrain) {
    switch (terrain) {
        case TerrainType::PLAINS: return Color::GREEN;
        case TerrainType::ROCKY: return Color::YELLOW;
        case TerrainType::SANDY: return Color::YELLOW + Color::BOLD;
        case TerrainType::MOUNTAINS: return Color::RED;
        case TerrainType::CRATER_RIM: return Color::MAGENTA;
        case TerrainType::IMPASSABLE: return Color::BOLD;
        default: return Color::RESET;
    }
}

void PlanetVisualizer::visualize(const AlienPlanet& planet,const std::vector<std::vector<Node*>>& allPaths,
bool showLegend)
{
    // Create a 2D array for display
    int width = planet.getWidth();
    int height = planet.getHeight();
    // Display dimension info
    std::cout << "Planet dimensions: " << width << "x" << height << "\n";
    // Build a set of all points on paths for quick lookup
    std::unordered_map<Point, int> pathPoints; // Maps position to path index
    for (size_t i = 0; i < allPaths.size(); i++) {
        for (Node* node : allPaths[i]) {
            pathPoints[node->position] = i;
        }
    }

    // Display the map
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Point p = {x, y};
            TerrainType terrain = planet.getTerrain(p);
            // Check for rover
            if (planet.getRoverPosition() == p) {
                std::cout << Color::BLUE << "R" << Color::RESET;
                continue;
            }

            // Check for landmark
            bool isLandmark = false;
            int landmarkIndex = -1;
            const std::vector<Landmark>& landmarks = planet.getLandmarks();
            for (size_t i = 0; i < landmarks.size(); i++) {
                if (landmarks[i].getPosition() == p) {
                    isLandmark = true;
                    landmarkIndex = i;
                    break;
                }
            }
            if (isLandmark) {
                std::cout << Color::CYAN << static_cast<char>('A' + landmarkIndex)
                << Color::RESET;
                continue;
            }
            // Check if on path
            auto pathIt = pathPoints.find(p);
            if (pathIt != pathPoints.end()) {
                // On a path - use different colors for different paths
                int pathIndex = pathIt->second;
                const char* pathColors[] = {
                    "\033[97m", // White
                    "\033[93m", // Yellow
                    "\033[92m", // Green
                    "\033[96m", // Cyan
                    "\033[95m" // Magenta
                };
                std::string color = pathColors[pathIndex % 5];
                std::cout << color << "*" << Color::RESET;
            } else {
                // Regular terrain
                std::cout << getTerrainColor(terrain)
                << getTerrainSymbol(terrain)
                << Color::RESET;
            }
        }
        std::cout << "\n";
    }

    // Display legend if requested
    if (showLegend) {
        std::cout << "\nLegend:\n";
        std::cout << Color::BLUE << "R" << Color::RESET << " = Rover\n";
        // Landmark legend
        const std::vector<Landmark>& landmarks = planet.getLandmarks();
        for (size_t i = 0; i < landmarks.size(); i++) {
            std::cout << Color::CYAN << static_cast<char>('A' + i) << Color::RESET
            << " = " << landmarks[i].getName() << "\n";
        }

        // Terrain legend
        std::cout << getTerrainColor(TerrainType::PLAINS)
        << getTerrainSymbol(TerrainType::PLAINS)
        << Color::RESET << " = Plains (Cost: 1)\n";
        std::cout << getTerrainColor(TerrainType::ROCKY)
        << getTerrainSymbol(TerrainType::ROCKY)
        << Color::RESET << " = Rocky (Cost: 3)\n";
        std::cout << getTerrainColor(TerrainType::SANDY)
        << getTerrainSymbol(TerrainType::SANDY)
        << Color::RESET << " = Sandy (Cost: 5)\n";
        std::cout << getTerrainColor(TerrainType::MOUNTAINS)
        << getTerrainSymbol(TerrainType::MOUNTAINS)
        << Color::RESET << " = Mountains (Cost: 10)\n";
        std::cout << getTerrainColor(TerrainType::CRATER_RIM)
        << getTerrainSymbol(TerrainType::CRATER_RIM)
        << Color::RESET << " = Crater Rim (Cost: 15)\n";
        std::cout << getTerrainColor(TerrainType::IMPASSABLE)
        << getTerrainSymbol(TerrainType::IMPASSABLE)
        << Color::RESET << " = Impassable\n";
        // Path legend
        if (!allPaths.empty()) {
            std::cout << "\033[97m*\033[0m = Path\n";
        }
    }
}

void PlanetVisualizer::listLandmarks(const AlienPlanet& planet) {
    const std::vector<Landmark>& landmarks = planet.getLandmarks();
    std::cout << "\n" << Color::BOLD << "Landmarks on the Planet:" << Color::RESET
    << "\n";
    std::cout << "=====================\n";
    for (size_t i = 0; i < landmarks.size(); i++) {
        const Landmark& landmark = landmarks[i];
        const Point& pos = landmark.getPosition();
        std::cout << Color::CYAN << static_cast<char>('A' + i) << Color::RESET
        << ": " << Color::BOLD << landmark.getName() << Color::RESET <<
        "\n";
        std::cout << " Position: (" << pos.x << ", " << pos.y << ")\n";
        std::cout << " Description: " << landmark.getDescription() << "\n";
        // Get terrain at the landmark
        TerrainType terrain = planet.getTerrain(pos);
        std::cout << " Terrain: " << getTerrainColor(terrain)
        << getTerrainSymbol(terrain)
        << Color::RESET;
        switch (terrain) {
            case TerrainType::PLAINS: std::cout << " Plains"; break;
            case TerrainType::ROCKY: std::cout << " Rocky terrain"; break;
            case TerrainType::SANDY: std::cout << " Sandy terrain"; break;
            case TerrainType::MOUNTAINS: std::cout << " Mountains"; break;
            case TerrainType::CRATER_RIM: std::cout << " Crater Rim"; break;
            default: std::cout << " Unknown terrain"; break;
        }
        std::cout << "\n\n";
    }
}

void PlanetVisualizer::simulateRoverMovement(AlienPlanet& planet,
const std::vector<std::vector<Node*>>& allPaths, int delayMs) {
    // Track original rover position for restoration later
    Point originalPosition = planet.getRoverPosition();
    // For each path segment
    for (size_t pathIndex = 0; pathIndex < allPaths.size(); pathIndex++) {
        const std::vector<Node*>& path = allPaths[pathIndex];

        // Skip empty paths
        if (path.empty()) continue;

        // Extract the start landmark if available
        const Landmark* startLandmark = nullptr;
        if (pathIndex > 0 && !allPaths[pathIndex-1].empty()) {
            Node* prevTarget = allPaths[pathIndex-1].back();
            startLandmark = planet.getLandmarkAt(prevTarget->position);
        }

        // Extract the target landmark
        Node* targetNode = path.back();
        const Landmark* targetLandmark = planet.getLandmarkAt(targetNode->position);

        // Journey segment message
        std::cout << "\n" << Color::BOLD;
        if (pathIndex == 0) {
            std::cout << "Starting journey from rover position";
        } else if (startLandmark) {
            std::cout << "Continuing from " << startLandmark->getName();
        }
        if (targetLandmark) {
            std::cout << " to " << targetLandmark->getName();
        }
        std::cout << Color::RESET << "\n";

        // Move along the path
        for (Node* node : path) {
            // Update rover position
            planet.setRoverPosition(node->position);
            // Refresh display
            std::cout << "\033[2J\033[H"; // Clear screen and move cursor to top-left
            visualize(planet, allPaths, false); // Don't show legend during simulation

            // Show current position info
            TerrainType currentTerrain = planet.getTerrain(node->position);
            std::cout << "\nCurrent position: (" << node->position.x << ", " <<
            node->position.y << ") ";
            std::cout << "Terrain: " << getTerrainColor(currentTerrain)
            << getTerrainSymbol(currentTerrain) << Color::RESET;

            // If at landmark, show info
            const Landmark* currentLandmark = planet.getLandmarkAt(node->position);
            if (currentLandmark) {
                std::cout << "\nLandmark: " << Color::CYAN << currentLandmark->getName() << Color::RESET;
                std::cout << "\nDescription: " << currentLandmark->getDescription();
            }

            // Delay for animation
            std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
        }

        // Pause slightly longer at landmarks
        if (targetLandmark) {
            std::this_thread::sleep_for(std::chrono::milliseconds(delayMs * 2));
        }
    }
    // Restore original position
    planet.setRoverPosition(originalPosition);
}

void PlanetVisualizer::showPathInfo(const PlanetGraph& graph, const std::vector<std::vector<Node*>>& allPaths,
    const AlienPlanet& planet) {
    int totalCost = 0;
    int totalSteps = 0;
    std::cout << "\nPath Information:\n";
    std::cout << "=================\n";
    for (size_t i = 0; i < allPaths.size(); i++) {
        const std::vector<Node*>& path = allPaths[i];
        if (path.empty()) {
            std::cout << "Path " << (i+1) << ": No valid path found!\n";
            continue;
        }

        // Start and end points
        Point start = path.front()->position;
        Point end = path.back()->position;

        // Find landmark names if available
        std::string startName = "Rover Position";
        std::string endName = "Unknown";
        if (i > 0 && !allPaths[i-1].empty()) {
            const Landmark* startLandmark = planet.getLandmarkAt(start);
            if (startLandmark) {
                startName = startLandmark->getName();
            }
        }

        const Landmark* endLandmark = planet.getLandmarkAt(end);
        if (endLandmark) {
            endName = endLandmark->getName();
        }
        int pathCost = graph.calculatePathCost(path);
        int pathLength = path.size();
        totalCost += pathCost;
        totalSteps += pathLength;
        std::cout << "Path " << (i+1) << ": " << startName << " to " << endName <<
        "\n";
        std::cout << " Length: " << pathLength << " steps\n";
        std::cout << " Cost: " << pathCost << " units\n";
    }
    std::cout << "\nTotal Journey:\n";
    std::cout << " Total Steps: " << totalSteps << "\n";
    std::cout << " Total Cost: " << totalCost << " units\n";
}

// =============================================================================
// MissionControl Class Implementation
// =============================================================================

MissionControl::MissionControl(int width, int height) : planet(width, height) {
// Initialize with default size
}

void MissionControl::generatePlanet(int numLandmarks, unsigned int seed) {
    planet.generate(numLandmarks, seed);
    graph.buildGraph(planet);
}

void MissionControl::runMission(bool animate) {
    // Show initial planet state
    std::cout << "Initial Planet State:\n";
    std::vector<std::vector<Node*>> emptyPaths;
    PlanetVisualizer::visualize(planet, emptyPaths);
    std::cout << "\nPlanning mission to visit all landmarks...\n";
    // Find paths to all landmarks using Dijkstra's algorithm
    std::vector<std::vector<Node*>> allPaths = PathFinder::findPathsToAllLandmarks(graph, planet);
    // Show paths
    std::cout << "\nPlanned Paths:\n";
    PlanetVisualizer::visualize(planet, allPaths);
    // Show path information
    PlanetVisualizer::showPathInfo(graph, allPaths, planet);
    // Simulate movement if requested
    if (animate) {
        std::cout << "\nPress Enter to start rover simulation...";
        std::cin.get();
        PlanetVisualizer::simulateRoverMovement(planet, allPaths);
    }
}

void MissionControl::findPathToLandmark(int landmarkIndex, bool animate) {
    // Validate landmark index
    const std::vector<Landmark>& landmarks = planet.getLandmarks();
    if (landmarkIndex < 0 || landmarkIndex >= static_cast<int>(landmarks.size())) {
        std::cout << "Invalid landmark index!\n";
        return;
    }

    // Get start and target nodes
    Node* startNode = graph.findNodeAtPosition(planet.getRoverPosition());
    Node* targetNode =
    graph.findNodeAtPosition(landmarks[landmarkIndex].getPosition());
    if (!startNode || !targetNode) {
        std::cout << "Invalid start or target position!\n";
        return;
    }

    // Find path using Uniform Cost Search
    std::cout << "Finding path to " << landmarks[landmarkIndex].getName() << " using Uniform Cost Search...\n";
    std::vector<Node*> path = PathFinder::uniformCostSearch(startNode, targetNode);
    if (path.empty()) {
        std::cout << "No path found!\n";
        return;
    }
    // Package as a single-path vector for visualization
    std::vector<std::vector<Node*>> allPaths = {path};
    // Show the path
    std::cout << "Path found:\n";
    PlanetVisualizer::visualize(planet, allPaths);
    // Show path information
    PlanetVisualizer::showPathInfo(graph, allPaths, planet);
    // Simulate movement if requested
    if (animate) {
        std::cout << "\nPress Enter to start rover simulation...";
        std::cin.get();
        PlanetVisualizer::simulateRoverMovement(planet, allPaths);
    }
}

void MissionControl::displayLandmarkList() {
    PlanetVisualizer::listLandmarks(planet);
}

void MissionControl::displayPlanet() {
    std::cout << "Planet Visualization:\n";
    // Display the planet without any paths
    std::vector<std::vector<Node*>> emptyPaths;
    PlanetVisualizer::visualize(planet, emptyPaths);
}