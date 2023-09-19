#include "producer.hpp"

void ratemodel::producer::addresource(const item &resourcetype, float amount)
{
    if(stockpile.find(resourcetype) == stockpile.end()) {
        stockpile[resourcetype] = amount;
    }
    else {
        stockpile[resourcetype] += amount;
    }
}

float ratemodel::producer::get(float passedtime)
{
    std::cerr << "float ratemodel::producer::get(float passedtime) not implemented yet" << std::endl;
    return 0.0f;
}
