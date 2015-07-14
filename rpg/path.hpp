//
//  path.hpp
//  rpg
//
//  Created by Robert Wilkinson on 12/23/14.
//  Copyright (c) 2014 Robert WIlkinson. All rights reserved.
//

#ifndef PATH_hpp
#define PATH_hpp
using namespace std;

class Path
{
public:
    string description;
    Path(string description)
    {
        this->description = description;
        
    }
    
    // Default constructor
    Path(){}
};
#endif
