//
//  path.hpp
//  rpg
//
//  Created by Robert Wilkinson on 12/23/14.
//  Copyright (c) 2014 Robert WIlkinson. All rights reserved.
//

#ifndef PATH_hpp
#define PATH_hpp
#include <string>

class Path
{
public:
    std::string description;
    Path(std::string description)
    {
        this->description = description;
        
    }
    
    // Default constructor
    Path(){}
};
#endif
