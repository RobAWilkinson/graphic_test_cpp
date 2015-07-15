//
//  room.hpp
//  rpg
//
//  Created by Robert Wilkinson on 12/23/14.
//  Copyright (c) 2014 Robert WIlkinson. All rights reserved.
//

#ifndef ROOM_HPP
#define ROOM_HPP
#include <vector>
#include <string>
#include "path.hpp"
#include "area.hpp"
using namespace std;

class Room {
 public:
 	Area *parent_area;
    Room *north;
    Room *south;
    Room *east;
    Room *west;
	int positionX, positionY;

    std::string center;
  std::vector < Path > paths;
    // Empty initializer
    Room(std::string center, int positionX, int positionY, Area *parent_area) {
	  this->positionY = positionY;
	  this->positionX = positionX;
      this->center = center;
	  this->parent_area = parent_area;
      for (int i = 0; i < 4; i++) {
          this->paths.push_back(Path(paths[i]));
      }
    }

    Room * go_west() {
      if (this->paths[3].blocked) {
        throw 1;
      }
      if (this->west) {
        return this->west;
      }
      Room new_room = Room();
      this->west = &new_room;
      return this->west;
    }
    Room() {}
};

#endif
