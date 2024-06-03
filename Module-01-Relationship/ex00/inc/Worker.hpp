#ifndef WORKER_HPP
#define WORKER_HPP

struct Position {
    int x, y, z;
    Position(int x, int y, int z) : x(x), y(y), z(z) {}
};

struct Statistic {
    int level, exp;
    Statistic(int level, int exp) : level(level), exp(exp) {}
};

class Worker {
private:
    Position _coordonnee;
    Statistic _stat;

public:
    Worker(Position position, Statistic statistic);
};

#endif  // WORKER_HPP