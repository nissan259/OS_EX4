#include "Graph.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void generateRandomGraph(Graph &g, int vertices, int edges, int seed) {
    std::srand(seed); // Initialize the random seed

    for (int i = 0; i < edges; i++) {
        int v = std::rand() % vertices;
        int w = std::rand() % vertices;

        // Make sure not to add self-loops (v != w)
        while (v == w) {
            w = std::rand() % vertices;
        }

        g.addEdge(v, w);
    }
}

int main() {
    int vertices, edges, choice, seed;

    // Input the number of vertices and edges
    std::cout << "Enter the number of vertices: ";
    std::cin >> vertices;
    
    std::cout << "Enter the number of edges: ";
    std::cin >> edges;

    // Check for valid input
    if (vertices <= 0) {
        std::cerr << "Error: Number of vertices must be greater than 0." << std::endl;
        return 1;
    }
      if (edges <= 0) {
        std::cerr << "Error: Number of edges must be greater than 0." << std::endl;
        return 1;
    }

    // Create a graph with the input number of vertices
    Graph g(vertices);

    // Ask user whether to generate a random graph or manually input edges
    std::cout << "Enter 1 to input edges manually, or 2 to generate a random graph: ";
    std::cin >> choice;

    if (choice == 1) {
        // Input each edge manually and add it to the graph
        std::cout << "Enter the edges (pair of vertices for each edge):" << std::endl;
        for (int i = 0; i < edges; i++) {
            int v, w;
            std::cout << "Edge " << i + 1 << ": ";
            std::cin >> v >> w;

            // Validate the vertices of the edge
            if (v < 0 || v >= vertices || w < 0 || w >= vertices) {
                std::cerr << "Error: Invalid edge. Vertices must be between 0 and " << vertices - 1 << "." << std::endl;
                return 1;
            }

            g.addEdge(v, w);
        }
    } else if (choice == 2) {
        // Generate a random graph
        std::cout << "Enter the random seed: ";
        std::cin >> seed;

        generateRandomGraph(g, vertices, edges, seed);
    } else {
        std::cerr << "Invalid choice." << std::endl;
        return 1;
    }

    // Display the adjacency list of the graph
    std::cout << "Graph adjacency list:" << std::endl;
    g.displayGraph();

    // Check if the graph has an Eulerian circuit
    std::cout << "Checking for Eulerian circuit..." << std::endl;
    if (g.isEulerian()) {
        std::cout << "This graph has an Eulerian circuit." << std::endl;
        g.printEulerCircuit();
    } else {
        std::cout << "No Eulerian circuit exists in this graph." << std::endl;
    }

    return 0;
}

//explian how to run the code 
// make 
// ./randomGraph
// Enter the number of vertices: 4
// Enter the number of edges: 4
// Enter 1 to input edges manually, or 2 to generate a random graph: 2
// Enter the random seed: 123
// then you will see the output of the graph
//rember that seed 123 is will set the ouptout of the graph to be predictable cuase it will generate the same graph every time you run it

// ./randomGraph
// Enter the number of vertices: 4
// Enter the number of edges: 4
// Enter 1 to input edges manually, or 2 to generate a random graph: 1
// Enter the edges (pair of vertices for each edge):
// Edge 1: 0 1
// Edge 2: 1 2
// Edge 3: 2 3
// Edge 4: 3 0
// then you will see the output of the graph
//This graph has an Eulerian circuit.
//Eulerian circuit: 0 -> 3 -> 2 -> 1 -> 0 -> End

//to run the test cases
// make test
// ./test


// to run the valigrind run with this coommand
//valgrind --tool=memcheck --leak-check=full --track-origins=yes ./RandomGraph 2> valgrind_memcheck_report.txt


//gcov
// run all the caeses that you want to cover 
//lcov --capture --directory . --output-file coverage.info
//genhtml coverage.info --output-directory out

//gprof
//run the code and then do do this ./RandomGraph
//gprof ./RandomGraph gmon.out > gprof_report.txt
