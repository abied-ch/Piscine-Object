#ifndef ATOOL_HPP
#define ATOOL_HPP

#include <iostream>

class Worker;

class ATool {
private:
    int               _numberOfUses;
    const std::string _type;
    Worker*           _owner;

public:
    ATool(int uses, const std::string& type, Worker* owner = NULL) : _numberOfUses(uses), _type(type), _owner(owner) {
        std::cout << "[Tool]:\t\tTool of type " << type << " created." << std::endl;
    }

    void use() {
        if (_numberOfUses > 0) {
            _numberOfUses--;
            std::cout << "[Tool]:\t\t" << _type << " used, remaining uses: " << _numberOfUses << "." << std::endl;
        } else {
            std::cout << "[Tool]:\t\t" << _type << " has no more uses left!" << std::endl;
        }
    }

    const std::string& getType() const { return _type; }
    const int&         getNumberOfUses() const { return _numberOfUses; }
    bool               hasOwner() { return _owner != NULL; }
    void               newOwner(Worker* owner) { _owner = owner; }
    virtual void       release();
};

class Shovel : public ATool {
public:
    Shovel(int uses, Worker* owner = NULL) : ATool(uses, "Shovel", owner) {}
};

class Hammer : public ATool {
public:
    Hammer(int uses, Worker* owner = NULL) : ATool(uses, "Hammer", owner) {}
};

#endif  // ATOOL_HPP