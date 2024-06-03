#include "ATool.hpp"
#include "Worker.hpp"
#include "Workshop.hpp"

int main() {
    Position  pos(1, 2, 3);
    Statistic stat(5, 100);
    Shovel    shovel(10);
    Hammer    hammer(15);

    Worker worker1(pos, stat);
    Worker worker2(Position(4, 5, 6), Statistic(10, 200));

    Workshop workshop;
    Workshop workshop1;

    worker1.giveTool(&shovel);
    worker1.print();

    workshop.registerWorker(&worker1);
    workshop.registerWorker(&worker2);
    workshop1.registerWorker(&worker1);
    workshop1.registerWorker(&worker2);

    worker2.giveTool(&shovel);
    worker1.print();
    worker2.print();

    worker2.print();
    shovel.use();

    workshop.executeWorkDay();

    return 0;
}
