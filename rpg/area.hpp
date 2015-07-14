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
class Area
{
public:
    std::string description;
    Room rooms[4][4];
    // Empty Initializer

    Area(std::string description, string rooms[4][4], string paths[4][4][4] )
    {
        this->description = description;
        for (int i; i < 4; i++) {
            for (int j ; i < 4; i++) {
                this->rooms[i][j] = Room(rooms[i][j], paths[i][j]);
            }
        }
        
        
    }
    Room findRoom(int x, int y)
    {
        return this->rooms[y-1][x-1];
    }
    Area(){}
    
};

#endif
