#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <list>

class Graph {
private:
    int vertices; // Number of vertices
    std::vector<std::list<int>> adjList; // Adjacency list for graph representation

public:
    Graph(int v); // Constructor

    void addEdge(int v, int w); // Add an edge to the graph
    bool isEulerian(); // Check if the graph has an Eulerian circuit
    void printEulerCircuit(); // Print the Eulerian circuit if it exists

    int getVertices() const; // Get number of vertices
    int getDegree(int v) const; // Get degree of a vertex
    void displayGraph() const; // Display the graph
};

#endif
