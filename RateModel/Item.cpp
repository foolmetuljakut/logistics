#include "Item.hpp"

bool RateModel::operator<(const Item &lhs, const Item &rhs) {
    return lhs.id < rhs.id;
}

unsigned RateModel::Item::Id() const
{
    return id;
}
