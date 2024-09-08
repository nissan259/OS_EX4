#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <stack>
std::stack<int> currPath;
    std::vector<int> circuit;
// Constructor
Graph::Graph(int v) : vertices(v) {
    adjList.resize(vertices);
}

// Add an edge to the graph
void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
    if (v != w) {
        adjList[w].push_back(v);  // Only add the reverse edge if it's not a self-loop
    }
}


// Get degree of a vertex
int Graph::getDegree(int v) const {
    return adjList[v].size();
}

// Display the adjacency list representation of the graph
void Graph::displayGraph() const {
    for (int i = 0; i < vertices; i++) {
        std::cout << "Vertex " << i << ": ";
        for (int adj : adjList[i])
            std::cout << adj << " ";
        std::cout << std::endl;
    }
}

// Check if all vertices with edges have even degree (Eulerian condition)
bool Graph::isEulerian() {
    for (int i = 0; i < vertices; i++) {
        if (getDegree(i) % 2 != 0) {
            return false;
        }
    }
    return true;
}

// Function to print Eulerian circuit
void Graph::printEulerCircuit() {
    if (!isEulerian()) {
        std::cout << "No Eulerian circuit exists." << std::endl;
        return;
    }

    

    // Start from any vertex with edges
    currPath.push(0);
    int currV = 0;

    while (!currPath.empty()) {
        if (adjList[currV].size() > 0) {
            currPath.push(currV);
            int nextV = adjList[currV].front();
            adjList[currV].pop_front();
            adjList[nextV].remove(currV); // Remove the reverse edge as well
            currV = nextV;
        } else {
            circuit.push_back(currV);
            currV = currPath.top();
            currPath.pop();
        }
    }

    // Output Euler circuit
    std::cout << "Eulerian circuit: ";
    for (int v : circuit)
        std::cout << v << " -> ";
    std::cout << "End" << std::endl;
}
