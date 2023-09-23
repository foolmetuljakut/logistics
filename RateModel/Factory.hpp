#ifndef ratemodel_factory_hpp
#define ratemodel_factory_hpp

#include "Item.hpp"

#include <map>
#include <iostream>

namespace RateModel
{
    class Factory {
        struct Inventory {
            float trafo;
            float stockpile;
        };
        std::map<Item, Inventory> inventory;
    public:
        void add(const Item& type, const float& traforule, const float& stockpile = 0);
        
        friend std::ostream& operator<<(std::ostream& out, const Factory& f);
    };

    std::ostream& operator<<(std::ostream& out, const Factory& f);

} // namespace ratemodel


#endif // !ratemodel_factory_hpp