#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include <map>
#include <sstream>

#include "ATool.hpp"
#include "Workshop.hpp"

extern int gWorkerId;

void announce(const std::string& structureType);

struct Position {
    int x, y, z;
    Position(int x, int y, int z) : x(x), y(y), z(z) { announce("Position"); }
};

struct Statistic {
    int level, exp;
    Statistic(int level, int exp) : level(level), exp(exp) { announce("Statistic"); }
};

class Worker {
private:
    Position                 _coordonnee;
    Statistic                _stat;
    ATool*                   _tool;
    const int                _id;
    std::map<int, Workshop*> _workshops;

    void log(const std::string& message) { std::cout << "[Worker " << _id << "]:\t" << message << std::endl; }

public:
    Worker(Position position, Statistic stat);
    ~Worker() {
        if (_tool != NULL) {
            log("Destroyed. Shovel remains intact.");
        }
    }

    const int& getId() const { return _id; }

    void giveTool(ATool* tool);

    void takeTool();

    void registerWorkshop(Workshop* workshop);

    void work(Workshop* workshop);

    void print() const;
};

inline void ATool::release() {
    if (_owner != NULL) {
        Worker* oldOwner = _owner;
        _owner           = NULL;
        oldOwner->takeTool();
    }
}

#endif  // WORKER_HPP