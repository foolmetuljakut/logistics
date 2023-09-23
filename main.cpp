#include <iostream>

#include "RateModel/Factory.hpp"

#ifdef MAIN
int main(int argc, char **argv) {
    std::cout << "i'm the main function" << std::endl;
    return 0;
}
#endif

#ifdef RATEMODEL1
int main(int argc, char **argv) {
    using fac = RateModel::Factory;
    using item = RateModel::Item;

    fac f;

    std::cout << f << std::endl;

    f.add(item(0), 1, 0);
    f.add(item(1), 2, 0);
    std::cout << f << std::endl;


    return 0;
}
#endif