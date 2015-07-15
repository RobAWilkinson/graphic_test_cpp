//
//  path.hpp
//  rpg
//
//  Created by Robert Wilkinson on 12/23/14.
//  Copyright (c) 2014 Robert WIlkinson. All rights reserved.
//
#include <string>

#ifndef PATH_hpp
#define PATH_hpp
class Path {
 public:
    bool blocked = false;
    std::string description;
    Path(std::string description) {
        this->description = description;
    }
    // Default constructor
    Path(){}
};
#endif
