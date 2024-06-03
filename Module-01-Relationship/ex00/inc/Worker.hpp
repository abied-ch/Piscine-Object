#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include <map>

#include "ATool.hpp"
#include "Workshop.hpp"

int gWorkerId = 0;

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
    const int _id;
    std::map<int, Workshop*> _workshops;

    void log(const std::string& message) { std::cout << "[Worker " << _id << "]: " << message << std::endl; }

public:
    Worker(Position position, Statistic stat) : _coordonnee(position), _stat(stat), _tool(NULL), _id(gWorkerId++) {}
    ~Worker() {
        if (_tool != NULL) {
            log("Destroyed. Shovel remains intact.");
        }
    }

    void giveTool(ATool* tool) {
        std::string newToolType = tool->getType();
        if (tool->hasOwner()) {
            log("Taking " + newToolType + " from previous owner.");
            tool->release();
        }

        if (_tool != NULL) {
            log("Worker already has a tool: " + _tool->getType() + ". Releasing tool.");
            _tool->release();
        }
        log("Now holding " + newToolType + ".");
        _tool = tool;
        _tool->newOwner(this);
    }

    void takeTool() {
        if (_tool != NULL) {
            log("Putting " + _tool->getType() + " back.");
        }
        _tool = NULL;
    }

    void registerWorkshop(Workshop* workshop) {
        int newWorkshopId = workshop->getId();
        if (_workshops.find(newWorkshopId) == _workshops.end()) {
            _workshops[newWorkshopId] = workshop;
            log("Registered to Workshop " + workshop->getId());
        }
    }

    void work(Workshop* workshop) {
        log()
        std::cout << "Worker " << _id << " started working in Workshop " << workshop->getId() << std::endl;
    }

    const int& getId() const { return _id; }

    void print() const {
        std::cout << "Worker(Position: (" << _coordonnee.x << ", " << _coordonnee.y << ", " << _coordonnee.z
                  << "), Statistic: (Level: " << _stat.level << ", Exp: " << _stat.exp << "))" << std::endl;
        if (_tool != NULL) {
            std::cout << "Worker has a " << _tool->getType() << " with " << _tool->getNumberOfUses() << " uses left."
                      << std::endl;
        } else {
            std::cout << "Worker does not have a " << _tool->getType() << "." << std::endl;
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