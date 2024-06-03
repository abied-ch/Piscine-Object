#include <cerrno>
#include <cstring>
#include <exception>
#include <iostream>

#include "Graph.hpp"
#include "Vector2.hpp"

int main() {
    try {
        Graph graph(10, 10);
        graph.addPoint(Vector2(0, 0));
        graph.addPoint(Vector2(2, 2));
        graph.addPoint(Vector2(4, 2));
        graph.addPoint(Vector2(2, 4));

        graph.draw();
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}