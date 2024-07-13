#include "Map.hpp"

void Map::createSingleLane() {
    for(size_t i = 0; i < 200; i++) {
        map.emplace_back(i);
        if(i > 0) {
            map[i-1].addNeighbour(map[i]);
        }
    }
    map[0].addVehicle(Vehicle{0});
}

void Map::update() {
    // create random update for each tile
    std::vector<size_t> indices;
    for(size_t i = 0; i < map.size(); i++) {
        indices.push_back(i);
    }
    std::shuffle(indices.begin(), indices.end(), g);

    // assumption: createSingleLane connects i -> i+1
    for(size_t i : indices) 
        if(map[i].hasVehicle(0)) {
            std::cout << "moving from " << i << " to " << i+1 << "\n";
            map[i].transfer(i+1);
        }

    std::cout << std::endl;


}
