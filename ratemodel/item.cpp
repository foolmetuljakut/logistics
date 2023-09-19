#include "item.hpp"

bool ratemodel::operator<(const item &lhs, const item &rhs) {
    return lhs.id < rhs.id;
}
