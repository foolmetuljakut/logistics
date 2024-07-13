#include "Map.hpp"

void Map::createSingleLane(size_t length) {
    for(size_t i = 0; i < length; i++) {
        map.emplace_back(i);
    }
    // two loops to avoid problems with reallocation copies when distributing neighbourship relationships
    for(size_t i = 1; i < length; i++) {
        map[i-1].addNeighbour(map[i]);
    }
}

void Map::addVehicle(size_t newId) {
    if(!map.front().isOccupied()) {
        map.front().addVehicle(Vehicle{newId});
    }
}

bool Map::isOccupied(size_t position) {
    auto it = std::find_if(map.begin(), map.end(), [position](const Field& item) {
        return item.getPosition() == position;
    });
    if(it != map.end()) {
        return it->isOccupied();
    } else {
        throw MapException({"position ", std::to_string(position), " could not be found."});
    }
}

void Map::update() {
    // create random update for each tile
    std::vector<size_t> indices;
    for(size_t i = 0; i < map.size(); i++) {
        bool lookingAtVehicle { map[i].isOccupied()}, nextFieldExists{i+1 < map.size()};

        if( lookingAtVehicle && nextFieldExists) {
            bool nextFieldIsFree{!map[i+1].isOccupied()};

            if(nextFieldIsFree) {
                indices.push_back(i);
            }
        }
    }
    if(indices.size() > 1) {
        std::shuffle(indices.begin(), indices.end(), g);
    }

    // assumption: createSingleLane connects i -> i+1
    for(size_t i : indices) {
        map[i].transfer(i+1);
    }
}
