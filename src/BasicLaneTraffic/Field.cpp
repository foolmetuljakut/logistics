#include "Field.hpp"

void Field::addVehicle(const Vehicle &v)
{
    if (isOccupied())
        throw FieldException{"tried to move a vehicle onto an occupied field."};
    vehicles.emplace_back(v);
}

bool Field::hasVehicle(const size_t &id) noexcept
{
    return std::find_if(vehicles.begin(), vehicles.end(), [id](auto v)
                        { return v.getId() == id; }) != vehicles.end();
}

bool Field::isNeighbour(const Field &f) const noexcept
{
    return std::find(neighbours.begin(), neighbours.end(), &f) != neighbours.end();
}

void Field::addNeighbour(Field &f) noexcept
{
    neighbours.push_back(&f);
}

void Field::transfer(const size_t &target)
{
    if (vehicles.size() == 0)
        throw FieldException{"tried to transfer a non-existing vehicle on ", std::to_string(x)};

    auto tf = std::find_if(neighbours.begin(), neighbours.end(), [target](auto &n)
                           { return n->x == target; });
    if (tf == neighbours.end())
        throw FieldException{"neighbour ", std::to_string(target), " didn't exist as neighbour on ", std::to_string(x)};

    if ((*tf)->isOccupied())
        throw FieldException{"tried to transfer onto an occupied field: ", std::to_string(x), " -> ", std::to_string(target)};

    // TODO replace with move
    (*tf)->vehicles.push_back(vehicles.front());
    vehicles.clear();
}

bool operator==(const Field &lhs, const Field &rhs)
{
    return lhs.x == rhs.x;
}