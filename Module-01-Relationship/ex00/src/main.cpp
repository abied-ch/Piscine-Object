#include "Worker.hpp"

int main() {
    Position pos(1, 2, 3);
    Statistic stat(5, 100);
    Shovel shovel(10);

    Worker worker1(pos, stat);
    Worker worker2(Position(4, 5, 6), Statistic(10, 200));

    std::cout << std::endl;

    worker1.giveShovel(&shovel);
    worker1.print();

    std::cout << "\nGiving Shovel to worker2:" << std::endl;
    worker2.giveShovel(&shovel);
    worker1.print();
    worker2.print();

    std::cout << "\nUsing Shovel by worker2:" << std::endl;
    worker2.print();
    shovel.use();

    return 0;
}