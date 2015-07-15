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
using namespace std;

class Room {
 public:
    Room *north;
    Room *south;
    Room *east;
    Room *west;

    std::string center;
  std::vector < Path > paths;
    // Empty initializer
    Room(std::string center, string paths[4]) {
      this->center = center;
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
