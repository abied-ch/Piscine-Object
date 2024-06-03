#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include <iostream>
#include <map>

class Worker;

extern int gWorkshopId;

class Workshop {
private:
    std::map<int, Worker*> _workers;
    int _id;

public:
    Workshop();

    void log(const std::string& message) { std::cout << "[Workshop " << _id << "]:\t" << message << std::endl; }

    void executeWorkDay();

    void registerWorker(Worker* worker);

    const int& getId() const { return _id; }
};

#endif  //  WORKSHOP_HPP