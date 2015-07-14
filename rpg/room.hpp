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
#include <vector>
using namespace std;

class Room
{
public:
    
    std::string center;
	std::vector < Path > paths;
    // Empty initliazer
    Room(std::string center, string paths[4])
    {
        this->center = center;
		for(int i = 0; i < 4; i++) {

        this->paths.push_back(Path(paths[i]));
		}
		

    }
    Room(){}
};

#endif
