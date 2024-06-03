#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include <map>

#include "Worker.hpp"

int gWorkshopId = 0;

class Workshop {
private:
    std::map<int, Worker*> _workers;
    int _id;

public:
    Workshop() : _id(gWorkshopId++) {}

    void executeWorkDay() {
        for (std::map<int, Worker*>::iterator worker = _workers.begin(); worker != _workers.end(); ++worker) {
            worker->second->work(this);
        }
    }

    void registerWorker(Worker* worker) {
        int newWorkerId = worker->getId();
        if (_workers.find(newWorkerId) == _workers.end()) {
            _workers[newWorkerId] = worker;
        }
    }

    const int& getId() const { return _id; }
};

#endif  //  WORKSHOP_HPP