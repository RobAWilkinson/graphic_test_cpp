#ifndef AREA_HPP
#define AREA_HPP

//
//  area.hpp
//  rpg
//
//  Created by Robert Wilkinson on 12/23/14.
//  Copyright (c) 2014 Robert WIlkinson. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include "room.hpp"
#include "path.hpp"
using namespace std;
class Area {
 public:
    std::string description;
    vector<Room> rooms;
    vector<Monster> monsters;
    int start[2];

    // Empty Initializer

    Area(std::string description, int start[2] ) {
        this->description = description;
        this->start[0] = start[0];
        this->start[1] = start[1];
    }
    Area * append_room(Room room) {
      this->rooms.push_back(room);
      return this;
    }
    Area * add_monster(Monster monster) {
      this->monsters.push_back(monster);
      return this;
    }
    // TODO(sam) fix this
    // Room find_room(int x, int y) {
    //     return this->rooms[y-1][x-1];
    // }
    Area(){}
};

#endif
