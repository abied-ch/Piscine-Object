#include "Graph.hpp"

#include <png.h>

#include <algorithm>
#include <fstream>
#include <iostream>

#include "Vector2.hpp"

Graph::Graph(float width, float height) : _size(width, height) {
    if (width > 99 or height > 99) {
        throw std::runtime_error("Max graph size: 99 x 99");
    }
}

void Graph::addPoint(const Vector2& point) {
    _points.push_back(point);
}

void Graph::addLine(const Vector2& start, const Vector2& end) {
    _lines.push_back(std::make_pair(start, end));
}

void Graph::readPointsFromFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (not file.is_open()) {
        throw std::runtime_error("Cannot open file.");
    }
    float x, y;
    while (file >> x >> y) {
        addPoint(Vector2(x, y));
    }
}

void Graph::draw() const {
    std::vector<std::vector<char> > grid((int)_size.y + 1, std::vector<char>((int)_size.x + 1, '.'));
    for (size_t i = 0; i < _points.size(); ++i) {
        int x = (int)_points[i].x;
        int y = (int)_points[i].y;
        if (x >= 0 and x <= _size.x and y >= 0 and y <= _size.y) {
            grid[y][x] = 'X';
        }
    }

    for (int y = (int)_size.y; y >= 0; --y) {
        std::cout << y << "  ";
        for (int x = 0; x <= _size.x; ++x) {
            std::cout << grid[y][x] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "  ";
    for (int x = 0; x <= _size.x; ++x) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
