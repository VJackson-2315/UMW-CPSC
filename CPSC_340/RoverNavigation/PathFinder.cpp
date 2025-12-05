/**
* ExoNav: Alien Planet Rover Navigation System
* PathFinder.cpp - Implementations of pathfinding algorithms
*
* STUDENT TODO: Implement the pathfinding algorithms in this file.
* The function signatures are provided, but the implementation is missing.
* Complete the Dijkstra's algorithm and Uniform Cost Search methods.
*/
#include "PathFinder.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <algorithm>

// Method to reconstruct the path from a DijkstraResult
std::vector<Node*> DijkstraResult::getPathTo(Node* target) const {
    std::vector<Node*> path;
    Node* current = target;
    // Check if a path exists
    if (previous.find(target) == previous.end() && startNode != target) {
        return path; // No path found
    }

    // Build the path from target to start
    while (current != nullptr) {
        path.push_back(current);
        if (current == startNode) break;
            auto it = previous.find(current);
        if (it != previous.end()) {
            current = it->second;
        } else {
            break;
        }
    }

    // Reverse to get path from start to target
    std::reverse(path.begin(), path.end());
    return path;
}

// Dijkstra's algorithm implementation - finds shortest paths to ALL nodes
DijkstraResult PathFinder::dijkstra(Node* start, const PlanetGraph& graph) {
    // STUDENT TODO: Implement Dijkstra's algorithm here
    // Initialize the result
    DijkstraResult result;
    result.startNode = start;

    //For all nodes: default distance infinite, previous node null
    for(Node* node : graph.getNodes()) {
        result.distances[node] = 99999999;
        result.previous[node] = nullptr;
    }
    //starting node is 0 away from starting node
    result.distances[start] = 0;
    result.previous[start] = nullptr;
    //priority queue
    std::priority_queue<std::pair<int, Node*>, // Template is a pair of the cumulative cost, and destination
        std::vector<std::pair<int, Node*>>, // Default
        std::greater<std::pair<int, Node*>> // Comparisons for min-heap, sorts on first thing
    > q;

    q.push({0, start}); // Pushing 0 and the start node
    while (!q.empty()) {
        // set current to dequeue
        Node* curr = q.top().second;
        int currDist = q.top().first;
        q.pop();

        for (int i = 0; i < curr->edges.size(); i++) { // For each neighbor
            int tentCost = curr->edges[i].cost + currDist;
            Node* dest = curr->edges[i].destination;

            if (tentCost < result.distances[dest]) { // If there's a lesser distance
                result.distances[dest] = tentCost;
                result.previous[dest] = curr;
                q.push({tentCost, dest});
            }
        }
    }
    return result;
}

// Uniform Cost Search implementation - finds shortest path to a SPECIFIC target
std::vector<Node*> PathFinder::uniformCostSearch(Node* start, Node* target) {
    // STUDENT TODO: Implement Uniform Cost Search here

    std::unordered_map<Node*, int> distances;
    std::unordered_map<Node*, Node*> previous;
    //std::unordered_map<Node*, bool> visited; -> Did not work for now, used the vector
    std::vector<Node*> visited;

    std::priority_queue<std::pair<int, Node*>,
        std::vector<std::pair<int, Node*>>,
        std::greater<std::pair<int, Node*>>
    > q;

    // Initialize the start
    distances[start] = 0;
    previous[start] = nullptr;
    visited.push_back(start);
    q.push({0, start});

    while (!q.empty()) {
        // Gets the current node
        Node* curr = q.top().second;
        int currDist = q.top().first;
        q.pop();
        if (curr == target) { // Stops once the target is found
            break;
        }
        for (int i = 0; i < curr->edges.size(); i++) {
            int tentCost = curr->edges[i].cost + currDist;
            Node* dest = curr->edges[i].destination;
            // Result used to check the visit status on dest
            auto result = std::find(visited.begin(), visited.end(), dest);
            if (tentCost < distances[dest] ||  result == visited.end()) { // If there's a lesser cost or it has never been visited
                // Update distances and push into the queue
                distances[dest] = tentCost;
                previous[dest] = curr;
                q.push({tentCost, dest});
                if (result == visited.end()) { // To stop overflow of the vector
                    visited.push_back(dest);
                }

            }
        }
    }

    std::vector<Node*> path;

// Reverse and return the path
    while (target != nullptr) {
        path.push_back(target);
        target = previous[target];
    }
   std::reverse(path.begin(), path.end());
    return path;
}

// Find paths to all landmarks using Dijkstra's algorithm results
std::vector<std::vector<Node*>> PathFinder::findPathsToAllLandmarks(PlanetGraph& graph, const AlienPlanet& planet) {
    std::vector<std::vector<Node*>> allPaths;

    // Start from rover position
    Point currentPos = planet.getRoverPosition();
    Node* currentNode = graph.findNodeAtPosition(currentPos);
    if (!currentNode) {
        return allPaths; // Can't find a valid starting node
    }

    // Visit each landmark in order
    for (const Landmark& landmark : planet.getLandmarks()) {
        Node* targetNode = graph.findNodeAtPosition(landmark.getPosition());
        if (!targetNode) {
            continue; // Skip invalid landmarks
        }
        // Run Dijkstra's algorithm from current position
        DijkstraResult result = dijkstra(currentNode, graph);
        // Get the path to this specific landmark from the results
        std::vector<Node*> path = result.getPathTo(targetNode);
        // If a path was found, add it and update current position
        if (!path.empty()) {
            allPaths.push_back(path);
            currentNode = targetNode;
        }
    }
    return allPaths;
}