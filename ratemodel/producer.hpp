#ifndef ratemodel_producer_hpp
#define ratemodel_producer_hpp

#include "item.hpp"

#include <map>
#include <iostream>

namespace ratemodel {
    class producer {
        std::map<item, unsigned> stockpile;
    public:
        void addresource(const item& resourcetype, float amount);
        float get(float passedtime);
    };
};

#endif//ratemodel_producer_hpp