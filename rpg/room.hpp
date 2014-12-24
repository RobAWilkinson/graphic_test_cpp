//
//  room.hpp
//  rpg
//
//  Created by Robert Wilkinson on 12/23/14.
//  Copyright (c) 2014 Robert WIlkinson. All rights reserved.
//

#ifndef ROOM_HPP
#define ROOM_HPP
#include "path.hpp"

class Room
{
public:
    
    std::string center;
    Path* path;
    // Empty initliazer
    Room(std::string center, Path paths[4])
    {
        this->center = center;
        this->path = paths;

    }
    Room(){}
};

#endif
