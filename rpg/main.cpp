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
#include "battle.hpp"
#include "area.hpp"
#include "room.hpp"
#include "path.hpp"

Creature dialogue_newChar();
void describe(Creature player);


int main(void) {
    Creature player;
    srand(time(NULL));
	Monster monster;
	Battle battle;
    Area area;

    area = Area("A leafy green wood, sunlight dapples the ground through the leaves of the tree",
                [
                 [ Room("a sunlight path",[
                                           Path("a dense green wood"),
                                           Path("a dense green wood"),
                                           Path("a hard packed dirt path"),
                                           Path("a dense green wood")
                                           ]
                        ),
                  Room("a sunlight path",[
                                          Path("a dense green wood"),
                                          Path("a hard dirt path"),
                                          Path("a hole in the dense trees"),
                                          this->rooms[0,0].paths[2]
                                          ]
                       ),
                  
                  
                  Room("a treasure chest", [
                                            Path("a dense forest"),
                                            Path("a dense forest"),
                                            Path("a dense forest"),
                                            Path("a crack in the trees")
                                            ]
                       ),
                  Room(),
                  ],
                 [
                  Room(),
                  Room("a sunlight path", [
                                           this->rooms[0,1,].paths[1],
                                           Path("a sunlight path"),
                                           Path("a sunlight path"),
                                           Path("a sunlight path"),
                                           this->rooms[1,1].paths[2]
                                           ]
                       ),
                  Room("a sunlight path", [
                                           this->rooms[0,2],paths[1],
                                           Path("densely packed trees"),
                                           Path("a sunlight path"),
                                           Path("densely packed trees")
                                           ]
                       ),
                  Room("a sunlight path", [
                                           this->rooms[0,3].paths[1],
                                           Path("densely packed trees"),
                                           Path("densely packed trees"),
                                           PAth("densely packed trees")
                                           ]
                       ),
                  ],
                 [ Room(),
                  Room("a sunlight path", [
                                           this->rooms[1,1,].paths[1],
                                           Path("densely packed woods"),
                                           Path("densely packed woods"),
                                           Path("densely packed woods"),
                                           ]
                       ),
                  Room(),
                  Room()
                  ],
                 [ Room(),
                  Room("a burning campfire", [
                                              this->rooms[2,1].paths[1],
                                              Path("densely packed trees"),
                                              Path("densely packed trees"),
                                              Path("densely packed trees")
                                              ]
                       ),
                  Room(),
                  Room()
                  ]
                 ]
                );
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
	start:
	result = Dialogue("What woudl you like to do?", { "Explore", "Look Around" }).activate();
	switch (result)
	{
	int fight_or_flight;
	case 1:
		monster = Monster("Green Slime", "poison", 20, 5, 10.0, 1);
		monster.addAttack("slime", "poison", 3, 1.0);
		monster.addAttack("Bite", "physical", 3, 1.2);
		fight_or_flight = Dialogue(("A " + monster.name + "appeared \n Woudl you like to?"), { "Battle", "Run Away" }).activate();
		switch (fight_or_flight){
		case 1:
			std::cout << "you choose to fight!";
			battle = Battle(player, monster);
			battle.fight();
			goto start;
			break;
		default:
			std::cout << "You ran away :(";
			break;

        }
		break;
    case 2:

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
	Creature player;
    int result = Dialogue("Choose your class", {"Fighter","Rogue", "Mage"}).activate();
    switch (result) {
        case 1:
            player = Creature(name, 35, 20, 10, 5, 5, 10.0, 1, "Fighter" );
			player.addAttack("punch", "physical", 3, 1.0);
			player.addAttack("Kick", "physical", 3, 1.2);
			player.addAttack("DEBUG", "DEBUG", 20, 3);
			return player;
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
