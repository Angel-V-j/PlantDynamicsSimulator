#include "Simulator.h"

#include <iostream>

Simulator::Simulator() : chaos(3.957,0.6),
                         weather(25,10),
                         writer("FirstTest"),
                         reader("FirstTest") {
}

void Simulator::run(const int days) {
    std::string line;
    for (int i = 0; i < days; i++) {
        line = time.update(weather,climate,chaos);
        std::cout << line << std::endl;
        writer.writeLine(line);
    }
}