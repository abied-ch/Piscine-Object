#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>

#include "ATool.hpp"

void announce(const std::string& structureType) {
    std::cout << "Initializing instance of " << structureType << "." << std::endl;
}

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
    Position _coordonnee;
    Statistic _stat;
    ATool* _tool;

public:
    Worker(Position position, Statistic statistic) : _coordonnee(position), _stat(statistic), _tool(NULL) {}
    ~Worker() {
        if (_tool != NULL) {
            std::cout << "Worker destroyed - Shovel remains." << std::endl;
        }
    }

    void giveTool(ATool* tool) {
        std::string newToolType = tool->getType();
        if (tool->hasOwner()) {
            std::cout << "Taking " << newToolType << " from previous owner." << std::endl;
            tool->release();
        }

        if (_tool != NULL) {
            std::cout << "Worker already has a tool: " << _tool->getType() << ". Releasing tool." << std::endl;
            _tool->release();
        }
        std::cout << "Giving " << newToolType << " to Worker." << std::endl;
        _tool = tool;
        _tool->newOwner(this);
    }

    void takeTool() {
        if (_tool != NULL) {
            std::cout << "Taking " << _tool->getType() << " from Worker." << std::endl;
        }
        _tool = NULL;
    }

    void print() const {
        std::cout << "Worker(Position: (" << _coordonnee.x << ", " << _coordonnee.y << ", " << _coordonnee.z
                  << "), Statistic: (Level: " << _stat.level << ", Exp: " << _stat.exp << "))" << std::endl;
        if (_tool != NULL) {
            std::cout << "Worker has a Shovel with " << _tool->getNumberOfUses() << " uses left." << std::endl;
        } else {
            std::cout << "Worker does not have a Shovel." << std::endl;
        }
    };
};

inline void ATool::release() {
    if (_owner != NULL) {
        Worker* oldOwner = _owner;
        _owner = NULL;
        oldOwner->takeTool();
    }
}

#endif  // WORKER_HPP