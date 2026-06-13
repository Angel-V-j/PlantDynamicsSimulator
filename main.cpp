#include <iostream>
#include "manager/Simulator.h"

int main() {
    auto *simulator = new Simulator();
    simulator->run(30);

    return 0;
}
