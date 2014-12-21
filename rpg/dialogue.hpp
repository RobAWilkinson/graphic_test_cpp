//
//  dialogue.cpp
//  rpg
//
//  Created by Robert Wilkinson on 12/20/14.
//  Copyright (c) 2014 Robert WIlkinson. All rights reserved.
//
#ifndef DIALOGUE_HPP
#define DIALOGUE_HPP

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
// Gameplay uses dialogue

class Dialogue
{
private:
    std::string description;
    std::vector<std::string> choices;
public:
    Dialogue(std::string description, std::vector<std::string> choices)
    {
        this->description = description;
        this->choices = choices;
    }
    int activate()
    {
        std::cout << description << std::endl;
        for (int i = 0; i < this->choices.size(); ++i) {
            std::cout << i+1 << ": " << this->choices[i] << std::endl;
        }
        int userInput = -1;
        
        while(true)
        {
        std:std::cin >> userInput;
            if (userInput >= 0 && userInput <= choices.size()) {
                return userInput;
            }
        }
        return 0;
    }
};
#endif
