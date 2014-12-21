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

Creature dialogue_newChar();


int main(void) {
    Creature player;
    srand(time(NULL));
    int result = Dialogue("Welcome",{"New Game"}).activate();
    switch (result) {
        case 1:
            player = dialogue_newChar();
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
    int result = Dialogue("Choose your class", {"Fighter","Rogue"}).activate();
    switch (result) {
        case 1:
            return Creature(name,35,20,10,5,10.0,1,"Fighter" );
            break;
        case 2:
            return Creature(name,30,5,10,20,15.0,1,"Rogue");
            break;
        default:
            return Creature(name, 30, 10, 10, 10, 10.0, 1,
                            "Adventurer");
            break;
    }
}
