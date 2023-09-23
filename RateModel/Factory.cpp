#include "Factory.hpp"

void RateModel::Factory::add(const Item &type, const float &traforule, const float &stockpile)
{
    if(inventory.find(type) == inventory.end())
    {
        inventory[type] = { traforule, stockpile }; // Factory.Inventory { trafo, amount }
    }
}

std::ostream &RateModel::operator<<(std::ostream &out, const Factory &f)
{
    out << "{";
    unsigned i = 0;
    for(auto kv : f.inventory)
        out << "\n\t" << kv.second.trafo << "/" << kv.second.stockpile << " of type " << kv.first.Id()
            << ( ++i == f.inventory.size() ? "\n" : ",");
    out << "} -> 1";
    return out;
}
