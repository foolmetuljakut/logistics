#include "Map.hpp"

void Map::createSingleLane(size_t length) {
    map = std::vector<Field>(length);
    for(size_t i = 0; i < length; i++) {
        map[i].setPosition(i);
    }
    // two loops to avoid problems with reallocation copies when distributing neighbourship relationships
    for(size_t i = 1; i < length; i++) {
        map[i-1].addNeighbour(map[i]);
    }
}

void Map::addVehicle(size_t newId, size_t position) {
    if(position >= map.size()) {
        throw MapException({"position", std::to_string(position), " > ", std::to_string(map.size()), " (map size)"});
    }

    auto fieldIt = std::find_if(map.begin(), map.end(), [position](const Field& f){ return f.getPosition() == position; });

    bool fieldValid { fieldIt != map.end() };
    if(!fieldValid) {
        throw MapException({"no field with id ", std::to_string(position), " exists."});
    }

    bool fieldFree { !fieldIt->isOccupied() };
    if(!fieldFree) {
        throw MapException({"field with id ", std::to_string(position), " exists but is occupied."});
    } else {
        fieldIt->addVehicle(Vehicle{newId});
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

size_t Map::size() {
    return this->map.size();
}
