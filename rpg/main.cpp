//
//  main.cpp
//  rpg
//
//  Created by Robert Wilkinson on 12/20/14.
//  Copyright (c) 2014 Robert WIlkinson. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <cstdlib>
#include <ctime>
#include "dialogue.hpp"
#include "creature.hpp"
#include "monster.hpp"

Creature dialogue_newChar();
void describe(Creature player);


int main(void) {
    Creature player;
    srand(time(NULL));
	Monster monster;
    int result = Dialogue("Welcome",{"New Game"}).activate();
    switch (result) {
        case 1:
            player = dialogue_newChar();
			player.describe();
            break;
        default:
            return 0;
            break;
    }
	result = Dialogue("What woudl you like to do?", { "Explore", "Look Around" }).activate();
	switch (result)
	{
	int fight_or_flight;
	case 1:
		monster = Monster("Green Slime", "poison", 20, 5, 10.0, 1);
		fight_or_flight = Dialogue(("A " + monster.name + "appeared \n Woudl you like to?"), { "Battle", "Run Away" }).activate();
		switch (fight_or_flight){
		case 1:
			std::cout << "you choose to fight!";
			break;
		default:
			std::cout << "You ran away :(";
			break;

		}
		break;
	default:
		return 0;
		break;
	}
    return 0;
}

Creature dialogue_newChar()
{
    //ask for name and class
    std::cout << "Choose your name" << std::endl;
    std::string name;
    std::cin >> name;
    int result = Dialogue("Choose your class", {"Fighter","Rogue", "Mage"}).activate();
    switch (result) {
        case 1:
            return Creature(name, 35, 20, 10, 5, 5, 10.0, 1, "Fighter" );
            break;
        case 2:
            return Creature(name, 30, 5, 10, 20, 10, 15.0, 1, "Rogue");
            break;
		case 3:
			return Creature(name, 20, 3, 10, 10, 20, 15.0, 1, "Mage");
        default:
            return Creature(name, 30, 10, 10, 10, 10, 10.0, 1,
                            "Adventurer");
            break;
    }
}
