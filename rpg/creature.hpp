//
//  creature.hpp
//  rpg
//
//  Created by Robert Wilkinson on 12/20/14.
//  Copyright (c) 2014 Robert WIlkinson. All rights reserved.
//

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>

class Creature
{
public:
    std::string name;
    std::string className;
    
    // Creature stats. Reasonable values are in parentheses
    int health;     // Current hit points (10-1000+)
    int maxHealth;  // Maximum hit points (10-1000+)
    int str;        // Strength. Determines damage in battle (1-100)
    int end;        // Endurance. Determines maximum health (1-100)
    int dex;        // Dexterity. Determines speed in battle (1-100)
    double hitRate; // Modifier to hit chance. (1-150)
    
    // Current level of the creature.
    // Determines the amount of experience that it gives to the
    // victor when defeated (see Battle class for more)
    // and the amount of experience required to level up again.
    // Upon levelling up the creature will gain stat improvements.
    // 1-50 is reasonable
    unsigned int level;
    
    // Current experience. 0-1M is reasonable, see the levelup() function
    // for a decent scale
    unsigned int exp;
    
    Creature(std::string name, int health, int str, int end, int dex, double hitRate, unsigned int level = 1, std::string className = "")
    {
        this->name = name;
        this->health = health;
        this->str = str;
        this->end = end;
        this->dex = dex;
        this->hitRate = hitRate;
        this->level = level;
        this->className = className;
        this->exp = 0;
        
    }
    Creature(){}
};

#endif /* CREATURE_HPP */