#include "Worker.hpp"

int gWorkerId = 1;

Worker::Worker(Position position, Statistic stat) : _coordonnee(position), _stat(stat), _tool(NULL), _id(gWorkerId++) {
}

void announce(const std::string& structureType) {
    std::cout << "[Info]:\t\tInitializing instance of " << structureType << "." << std::endl;
}

void Worker::giveTool(ATool* tool) {
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

void Worker::takeTool() {
    if (_tool != NULL) {
        log("Putting " + _tool->getType() + " back.");
    }
    _tool = NULL;
}

void Worker::registerWorkshop(Workshop* workshop) {
    int                newWorkshopId = workshop->getId();
    std::ostringstream oss;
    if (_workshops.find(newWorkshopId) == _workshops.end()) {
        _workshops[newWorkshopId] = workshop;
        oss << "Registered to Workshop " << workshop->getId() << ".";
    } else {
        oss << "Already member of Workshop " << workshop->getId() << ".";
    }
    log(oss.str());
}

void Worker::work(Workshop* workshop) {
    std::ostringstream oss;
    oss << "Started working in Workshop " << workshop->getId() << ".";
    log(oss.str());
}

void Worker::print() const {
    std::ostringstream oss;
    std::cout << "[Worker " << _id << "]:\t";
    std::cout << "Status: (Position: (" << _coordonnee.x << ", " << _coordonnee.y << ", " << _coordonnee.z
              << "), Statistic: (Level: " << _stat.level << ", Exp: " << _stat.exp << "))" << std::endl;
    std::cout << "[Worker " << _id << "]:\t";
    if (_tool != NULL) {
        std::cout << "Worker has a " << _tool->getType() << " with " << _tool->getNumberOfUses() << " uses left."
                  << std::endl;
    } else {
        std::cout << "Worker does not have a tool." << std::endl;
    }
}