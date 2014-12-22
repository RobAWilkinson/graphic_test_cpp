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
	int intelligence; // Intelligence, determines mana pool and spell powers
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

    Creature(std::string name, int health, int str, int end, int dex, int intelligence, double hitRate, unsigned int level = 1, std::string className = "")
    {
        this->name = name;
        this->health = health;
        this->str = str;
        this->end = end;
        this->dex = dex;
		this->intelligence = intelligence;
        this->hitRate = hitRate;
        this->level = level;
        this->className = className;
        this->exp = 0;
        
    }
    Creature(){}
    // returns experience needed to level up
    unsigned int expToLevel(unsigned int level)
    {
        return 128 * level * level;
    }
    // checks to see if needs level up
    // adjusts stats accordingly and returns true if leveled up false if nots
    bool levelUp()
    {
        if (this->exp >= expToLevel(this->level + 1)) {
            // Advance to the next level
            ++ level;
            
            // Variables to track stat changes, they should all be resolved at the end of the function
            unsigned int healthBoost = 0;
            unsigned int strBoost = 0;
            unsigned int endBoost = 0;
            unsigned int dexBoost = 0;
			unsigned int intBoost = 0;
            
            // Give a large Health Increase every Four levels
            
            if ( level % 4 == 0 )
            {
                healthBoost = 10 + (rand() % 4) + this->end /4;
                
            }
            
            // Else give a normal one
            else
            {
                healthBoost = (rand() % 4) + this->end /4;
            }
            
            // IF is a fighter increase strength and endurance,
            if (this->className == "Fighter") {
                strBoost = 1;
                endBoost = 1;
                if ( rand() % 2 == 0) { 
					dexBoost = 1;
					intBoost = 1;
				}
                
            }
            
            // If is a rogue increase dexterity and endurance
            if (this->className == "Rogue") {
                endBoost = 1;
                dexBoost = 1;
                if (rand() % 2 == 0){ 
					strBoost = 1;
					intBoost = 1;
				}
            }
			// If a mage, increase intelligence
			if (this->className == "Mage")
			{
				endBoost = 1;
				intBoost = 1;
				if (rand() % 2 == 0)
				{
					strBoost = 1;
					dexBoost = 1;
				}


			}
            
            // Readjust the class variables based on the new boosts
            this->health += healthBoost;
            this->str += strBoost;
            this->end += endBoost;
            this->dex += dexBoost;
            
            // Tell the user they grew a level
            std::cout << "Congratualions " << this->name << " has leveled up" << std::endl;
            std::cout << "Strength: " << this->str << std::endl;
            std::cout << "Endurance: " << this->end << std::endl;
            std::cout << "Dexterity: " << this->dex << std::endl;
			std::cout << "Intelligence: " << this->intelligence << std::endl;
            std::cout << "Now has " << this->health << std::endl;
            return true;
        }
        return false;
    }
	void describe()
	{
		std::cout << "You are a level " << this->level << " " << this->className << std::endl;
		std::cout << "Strength: " << this->str << std::endl;
		std::cout << "Endurance: " << this->end << std::endl;
		std::cout << "Dexterity: " << this->dex << std::endl;
		std::cout << "Intelligence: " << this->intelligence << std::endl;
	}
};

#endif /* CREATURE_HPP */