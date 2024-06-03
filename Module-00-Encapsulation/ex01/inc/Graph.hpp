#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <png.h>

#include <iostream>
#include <vector>

#include "Vector2.hpp"

class Graph {
private:
    const Vector2 _size;
    std::vector<Vector2> _points;
    std::vector<std::pair<Vector2, Vector2> > _lines;

public:
    Graph(float width, float height);

    void addPoint(const Vector2& point);
    void addLine(const Vector2& start, const Vector2& end);
    void readPointsFromFile(const std::string& filename);
    void draw() const;
};

#endif  // GRAPH_HPP