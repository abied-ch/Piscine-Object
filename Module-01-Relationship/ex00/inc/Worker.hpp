#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>

class Worker;

void announce(const std::string& structType) {
    std::cout << "Initializing instance of " << structType << " structure." << std::endl;
}

struct Position {
    int x, y, z;
    Position(int x, int y, int z) : x(x), y(y), z(z) { announce("Position"); }
};

struct Statistic {
    int level, exp;
    Statistic(int level, int exp) : level(level), exp(exp) { announce("Statistic"); }
};

struct Shovel {
    int numberOfUses;
    Worker* owner;

    Shovel(int uses, Worker* owner = NULL) : numberOfUses(uses), owner(owner) { announce("Shovel"); }

    void use() {
        if (numberOfUses > 0) {
            numberOfUses--;
            std::cout << "Shovel used, remaining uses: " << numberOfUses << std::endl;
        } else {
            std::cout << "Shovel has no more uses left!" << std::endl;
        }
    }
};

class Worker {
private:
    Position _coordonnee;
    Statistic _stat;
    Shovel* _shovel;

public:
    Worker(Position position, Statistic statistic) : _coordonnee(position), _stat(statistic), _shovel(NULL) {}
    ~Worker() {
        if (_shovel != NULL) {
            std::cout << "Worker destroyed - Shovel remains." << std::endl;
        }
    }

    void giveShovel(Shovel* shovel) {
        if (shovel->owner != NULL) {
            std::cout << "Taking Shovel from previous owner." << std::endl;
            shovel->owner->takeShovel();
        }

        if (_shovel != NULL) {
            std::cout << "Worker already has a Shovel. Reassigning new Shovel to Worker." << std::endl;
        } else {
            std::cout << "Giving Shovel to Worker." << std::endl;
        }
        _shovel = shovel;
        _shovel->owner = this;
    }

    void takeShovel() {
        if (_shovel != NULL) {
            std::cout << "Taking Shovel from Worker." << std::endl;
        }
        _shovel->owner = NULL;
        _shovel = NULL;
    }

    void print() const {
        std::cout << "Worker(Position: (" << _coordonnee.x << ", " << _coordonnee.y << ", " << _coordonnee.z
                  << "), Statistic: (Level: " << _stat.level << ", Exp: " << _stat.exp << "))" << std::endl;
        if (_shovel != NULL) {
            std::cout << "Worker has a Shovel with " << _shovel->numberOfUses << " uses left." << std::endl;
        } else {
            std::cout << "Worker does not have a Shovel." << std::endl;
        }
    };
};

#endif  // WORKER_HPP