#include "Workshop.hpp"

#include "Worker.hpp"

int gWorkshopId = 1;

Workshop::Workshop() : _id(gWorkshopId++) {
}

void Workshop::executeWorkDay() {
    std::ostringstream oss;
    for (std::map<int, Worker*>::iterator worker = _workers.begin(); worker != _workers.end(); ++worker) {
        worker->second->work(this);
        oss << "Worker " << worker->first << " started workday.";
        log(oss.str());
        oss.str("");
    }
}

void Workshop::registerWorker(Worker* worker) {
    int newWorkerId = worker->getId();
    std::ostringstream oss;
    if (_workers.find(newWorkerId) == _workers.end()) {
        _workers[newWorkerId] = worker;
        oss << "Registered Worker " << newWorkerId << ".";
    } else {
        oss << "Worker " << newWorkerId << " is already registered.";
    }
    log(oss.str());
}