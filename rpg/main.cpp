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
using namespace std;

Creature dialogue_newChar();
Monster getRandomMonster();
void describe(Creature player);


int main(void) {
    Creature player;
    srand(time(NULL));
  Monster monster;
  Battle battle;
    Area area;
  // mock data to test
  string roomdescriptions[4][4];
  string paths[4][4][4];
  // area = Area("a leafy wood", roomdescriptions, paths);

    int result = Dialogue("Welcome", {"New Game"}).activate();
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
  result = Dialogue(
    "What would you like to do?",
    { "Explore", "Look Around" }
  ).activate();
  switch (result) {
    int fight_or_flight;
    case 1:
      monster = getRandomMonster();
      fight_or_flight = Dialogue(
        ("A " + monster.name + "appeared \n Would you like to?"),
        { "Battle", "Run Away" }
      ).activate();
      switch (fight_or_flight) {
        case 1:
          cout << "you choose to fight!";
          battle = Battle(&player, &monster);
          battle.fight();
          goto start;
          break;
        default:
          cout << "You ran away :(";
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
Monster getRandomMonster() {
    // TODO(rahb) load monster data from a database of some sorts
    // TODO(rahb) have a database of prebuilt monsters
    Monster monster = Monster("Green Slime", "poison", 20, 5, 10.0, 1);
    monster.addAttack("slime", "poison", 3, 1.0);
    monster.addAttack("Bite", "physical", 3, 1.2);
    return monster;
}

Creature dialogue_newChar() {
    // ask for name and class
    cout << "Choose your name" << endl;
    string name;
    cin >> name;
  Creature player;
    int result = Dialogue(
      "Choose your class",
      {"Fighter", "Rogue", "Mage"}
    ).activate();
    switch (result) {
      case 1:
        player = Creature(name, 35, 20, 10, 5, 5, 10.0, 1, "Fighter");
        player.addAttack("punch", "physical", 3, 1.0);
        player.addAttack("Kick", "physical", 3, 1.2);
        player.addAttack("DEBUG", "DEBUG", 20, 3);
        return player;
      case 2:
          return Creature(name, 30, 5, 10, 20, 10, 15.0, 1, "Rogue");
      case 3:
        return Creature(name, 20, 3, 10, 10, 20, 15.0, 1, "Mage");
      default:
        return Creature(name, 30, 10, 10, 10, 10, 10.0, 1, "Adventurer");
    }
}
