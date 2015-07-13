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
using namespace std;
class Dialogue
{
private:
    string description;
    vector<string> choices;
public:
    Dialogue(string description, vector<string> choices)
    {
        this->description = description;
        this->choices = choices;
    }
    int activate()
    {
        cout << description << endl;
        for (int i = 0; i < this->choices.size(); ++i) {
            cout << i+1 << ": " << this->choices[i] << endl;
        }
        signed int userInput = -1;
        
        while(true)
        {
        cin >> userInput;
            if (userInput >= 0 && userInput <= choices.size()) {
                return userInput;
            }
        }
        return 0;
    }
};
#endif
