#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.hpp"

// Test graph creation and edge addition
TEST_CASE("Graph creation and edge addition") {
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    CHECK(g.getDegree(0) == 1);
    CHECK(g.getDegree(1) == 2);
    CHECK(g.getDegree(2) == 1);
}

// Test graph with an Eulerian circuit
TEST_CASE("Eulerian circuit exists") {
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);

    CHECK(g.isEulerian() == true);
}

// Test graph without an Eulerian circuit
TEST_CASE("No Eulerian circuit") {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    CHECK(g.isEulerian() == false);
}

// Test random graph generation with known seed
TEST_CASE("Random graph generation") {
    Graph g(4);
    std::srand(123); // Set seed for predictable output
    for (int i = 0; i < 4; i++) {
        int v = std::rand() % 4;
        int w = std::rand() % 4;
        while (v == w) w = std::rand() % 4;
        g.addEdge(v, w);
    }

    // Test degrees (specific to this seed)
    CHECK(g.getDegree(0) > 0);
    CHECK(g.getDegree(1) > 0);
    CHECK(g.getDegree(2) > 0);
    CHECK(g.getDegree(3) > 0);
}

// Additional test case: Check for self-loops
TEST_CASE("Self-loop handling") {
    Graph g(3);
    g.addEdge(0, 0);  // Add a self-loop
    CHECK(g.getDegree(0) == 1);  // Self-loop should increase degree

    // No Euler circuit should exist
    CHECK(g.isEulerian() == false);
}

// Additional test case: Graph with isolated vertices
TEST_CASE("Graph with isolated vertices") {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    // Vertices 3 and 4 are isolated
    CHECK(g.getDegree(3) == 0);
    CHECK(g.getDegree(4) == 0);

    // No Euler circuit should exist
    CHECK(g.isEulerian() == false);
}

// Additional test case: Large graph
TEST_CASE("Large graph Eulerian circuit check") {
    int vertices = 1000;
    Graph g(vertices);

    // Create a large Eulerian cycle
    for (int i = 0; i < vertices - 1; i++) {
        g.addEdge(i, i + 1);
    }
    g.addEdge(vertices - 1, 0);  // Connect the last vertex back to the first

    CHECK(g.isEulerian() == true);
}
