/**
* ExoNav: Alien Planet Rover Navigation System
* PathFinder.h - Declarations for pathfinding algorithms
*
* Students will implement these algorithms in PathFinder.cpp
*/
#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "Code.h"
#include <vector>
#include <unordered_map>
/**
* Structure to hold the results of Dijkstra's algorithm
* Contains distances to all nodes and information to reconstruct paths
*/

struct DijkstraResult {
    // Maps each node to its distance from the start node
    std::unordered_map<Node*, int> distances;
    // Maps each node to its predecessor in the shortest path
    std::unordered_map<Node*, Node*> previous;
    // The start node of the search
    Node* startNode;
    // Reconstructs the path from start to a specific target
    std::vector<Node*> getPathTo(Node* target) const;
};
/**
* Class for implementing pathfinding algorithms
* Students will focus on implementing these algorithms
*/

class PathFinder {
public:
    /**
    * Dijkstra's algorithm for finding the shortest paths from a start node to ALL
    other nodes
    *
    * @param start The starting node
    * @param graph The graph containing all nodes
    * @return A DijkstraResult containing distances and path information
    */
    static DijkstraResult dijkstra(Node* start, const PlanetGraph& graph);
    /**
    * Uniform Cost Search algorithm for finding the shortest path between two
    specific nodes
    *
    * @param start The starting node
    * @param target The target node
    * @return A vector of nodes representing the shortest path
    */
    static std::vector<Node*> uniformCostSearch(Node* start, Node* target);
    /**
    * Find paths to all landmarks using Dijkstra's algorithm results
    *
    * @param graph The planet graph
    * @param planet The alien planet
    * @return A vector of paths (each path is a vector of nodes)
    */
    static std::vector<std::vector<Node*>> findPathsToAllLandmarks(
    PlanetGraph& graph,
    const AlienPlanet& planet);
};
#endif // PATHFINDER_H