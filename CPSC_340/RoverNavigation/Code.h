/**
* ExoNav: Alien Planet Rover Navigation System
* Code.h - Declarations for all classes except PathFinder
*/
#ifndef CODE_H
#define CODE_H
#include <vector>
#include <string>
#include <unordered_map>
#include <random>
// =============================================================================
// Constants and Basic Data Structures
// =============================================================================
// Constants for terrain and simulation settings
constexpr int GRID_WIDTH = 30;
constexpr int GRID_HEIGHT = 20;
constexpr int NUM_LANDMARKS = 5;
constexpr int SIMULATION_DELAY_MS = 100; // milliseconds between steps for visualization
// Terrain types with associated movement costs
enum class TerrainType {
    PLAINS = 1, // Easy to traverse
    ROCKY = 3, // Moderate difficulty
    SANDY = 5, // Difficult terrain
    MOUNTAINS = 10, // Very difficult
    CRATER_RIM = 15, // Extremely difficult
    IMPASSABLE = -1 // Cannot traverse
};
// 2D Point structure
struct Point {
    int x, y;
    // Equality operator for use in containers
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    // Less than operator for use in ordered containers
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
            return y < other.y;
    }
};
// Hash function for Point to use in unordered containers
namespace std {
    template<>
    struct hash<Point> {
        std::size_t operator()(const Point& p) const {
            return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
    }
};
}
// Colors for console output
namespace Color {
    extern const std::string RESET;
    extern const std::string RED;
    extern const std::string GREEN;
    extern const std::string YELLOW;
    extern const std::string BLUE;
    extern const std::string MAGENTA;
    extern const std::string CYAN;
    extern const std::string BOLD;
}
// =============================================================================
// Forward Declarations
// =============================================================================
// These are needed for circular references
class AlienPlanet;
class PlanetGraph;
struct Node;
// =============================================================================
// Landmark and Elevation Classes
// =============================================================================
// Represents a landmark on the planet
class Landmark {
    private:
        std::string name;
        Point position;
        std::string description;
    public:
        Landmark(const std::string& n, const Point& pos, const std::string& desc);
        const std::string& getName() const;
        const Point& getPosition() const;
        const std::string& getDescription() const;
};
// Handles elevation data for the planet
class ElevationMap {
    private:
        std::vector<std::vector<int>> elevationData;
        int width, height;
    public:
        ElevationMap(int w, int h);
        void generateElevation(std::mt19937& rng);
        int getElevation(const Point& p) const;
};
// =============================================================================
// Alien Planet Class
// =============================================================================
class AlienPlanet {
    private:
    int width, height;
        std::vector<std::vector<TerrainType>> terrain;
        std::vector<Landmark> landmarks;
        Point roverPosition;
        ElevationMap elevationMap;
        // Helper methods
        std::string generateLandmarkName(std::mt19937& rng);
        std::string generateLandmarkDescription(std::mt19937& rng);
        void placeLandmarks(int numLandmarks, std::mt19937& rng);
        void placeRover(std::mt19937& rng);
    public:
        AlienPlanet(int w, int h);
        void generate(int numLandmarks, unsigned int seed = 0);
        // Getters and setters
        int getWidth() const;
        int getHeight() const;
        TerrainType getTerrain(int x, int y) const;
        TerrainType getTerrain(const Point& p) const;
        const std::vector<Landmark>& getLandmarks() const;
        const Point& getRoverPosition() const;
        void setRoverPosition(const Point& newPos);
        int getElevation(const Point& p) const;
        // Landmark methods
        bool isLandmarkAt(const Point& p) const;
        const Landmark* getLandmarkAt(const Point& p) const;
};
// =============================================================================
// Graph Representation for Pathfinding
// =============================================================================
// Edge between nodes with a cost
struct Edge {
    Node* destination;
    int cost;
};
// Node in the graph (represents a position on the planet)
struct Node {
    Point position;
    TerrainType terrain;
    int elevation;
    std::vector<Edge> edges; // Connections to neighboring nodes
};
// Graph representation of the planet for pathfinding
class PlanetGraph {
    private:
        std::vector<Node*> nodes;
        std::unordered_map<Point, Node*> pointToNode; // For quick lookup
        // Helper method
        int calculateMovementCost(const Point& from, const Point& to,
        TerrainType terrainType, int fromElev, int toElev);
    public:
        ~PlanetGraph();
        void buildGraph(const AlienPlanet& planet);
        Node* findNodeAtPosition(const Point& position);
        const std::vector<Node*>& getNodes() const;
        int calculatePathCost(const std::vector<Node*>& path) const;
};
// =============================================================================
// Visualization
// =============================================================================
class PlanetVisualizer {
    private:
        // Helper methods
        static char getTerrainSymbol(TerrainType terrain);
        static std::string getTerrainColor(TerrainType terrain);
    public:
        static void visualize(
        const AlienPlanet& planet,
        const std::vector<std::vector<Node*>>& allPaths,
        bool showLegend = true);
        static void listLandmarks(const AlienPlanet& planet);
        static void simulateRoverMovement(
        AlienPlanet& planet,
        const std::vector<std::vector<Node*>>& allPaths,
        int delayMs = SIMULATION_DELAY_MS);
        static void showPathInfo(
        const PlanetGraph& graph,
        const std::vector<std::vector<Node*>>& allPaths,
        const AlienPlanet& planet);
};
// =============================================================================
// Mission Control (Main Application Logic)
// =============================================================================
class MissionControl {
    private:
        AlienPlanet planet;
        PlanetGraph graph;
    public:
        MissionControl(int width, int height);
        void generatePlanet(int numLandmarks, unsigned int seed = 0);
        void runMission(bool animate = true);
        void findPathToLandmark(int landmarkIndex, bool animate = true);
        void displayLandmarkList();
        void displayPlanet(); // New method to display planet visualization
};
#endif // CODE_H