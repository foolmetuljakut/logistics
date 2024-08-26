#include <iostream>
#include <sstream>
#include <string>

#include "BasicLaneTraffic/Application.hpp"

int main(int argc, char** argv) {
    Application app;

    app.print();
    for (size_t i = 0; i < 20; i++) {
        app.update();
        app.print();
    }
    return 0;
}