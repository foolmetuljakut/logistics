#include <iostream>

#include "ratemodel/producer.hpp"

#ifdef RATEMODEL1
int main(int argc, char **argv) {
    std::cout << "i'm unittest ratemodel0" << std::endl;
    return 0;
}
#endif

#ifdef MAIN
int main(int argc, char **argv) {
    std::cout << "i'm the main function" << std::endl;
    return 0;
}
#endif