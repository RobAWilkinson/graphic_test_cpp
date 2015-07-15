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
#include "path.hpp"
#include "monster.hpp"
using namespace std;
class Area {
 public:
    std::string description;
    vector<Monster> monsters;
	int height, width;
    int start[2];

    // Empty Initializer

    Area(std::string description, int height, int width) {
		if(!height) {
			height = 16;
		}
		if(!height) {
			height = 16;
		}
        this->description = description;
		this->height = height;
		this->width = width;
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
