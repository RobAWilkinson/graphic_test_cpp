#ifndef BATTLE_HPP
#define BATTLE_HPP
#include <vector>
#include "attack.hpp"
#include "creature.hpp"
#include "monster.hpp"

// Create the battle class

using namespace std;
class Battle
{
private:
	Creature *player;
	Monster *monster;
public:
	Battle(Creature *player, Monster *monster)
	{
		this->player = player;
		this->monster = monster;
	}
	void fight()
	{
		vector<string> choices;
		string debug;
		bool hit_or_miss;
		Attack playerAttack, monsterAttack;
		int index;
		// pass the different attack types as a vector of strings to dialogue
        for(int i =0; i < this->player->attacks.size();i++)
        {
            choices.push_back(player->attacks[i].name);
            
        }
		while (this->monster->alive())
		{
			// receive a 1 based index number of which attack should happen
			index = Dialogue("What would you like to attack with?", choices).activate();
			playerAttack = this->player->attacks[--index];
			monsterAttack = this->monster->randomAttack();
			cout << "You attack with " << playerAttack.name << endl;
			hit_or_miss = player->hit();


			// TODO Fix player->hit() acting weird something to do with rand() I believe

			if (hit_or_miss)
			{
				cout << "Your attack hits!" << endl;

				// Monster health only dropping through the first time
				monster->dropHealth(damage(playerAttack));
				cout << "It does " << to_string(damage(playerAttack)) << " damage, nice job!" << endl;
				cout << this->monster->name << " has " << this->monster->health << "HP remaining" << endl;
				cout << this->monster->name << " attacks with " << monsterAttack.name << endl;
				cout << "It does " << damage(monsterAttack) << "to you!" << endl;
				this->player->health -= damage(monsterAttack);
				cout << this->player->name << " now has " << this->player->health << " HP" << endl;

			}
			else
			{
				cout << "oooh so close, you missed" << endl;
			}
		}
		player->exp += expGain();
		cout << "Congratulations you defeated a:";
		cout << this->monster->name << endl;
		cout << this->player->name << " has gained ";
		cout << expGain() << "XP";
		cout << "by Defeating a " << this->monster->name << endl;
		if (this->player->levelUp())
		{
			cout << " Congratulations!" << endl;
			cout << this->player->name << " has leveled up" << endl;
			cout << this->player->name << " is now " << player->level << endl;
		}
	}

	int damage(Attack attack)
	{	
		return attack.baseMultiplier * attack.baseDamage;

	}
	int expGain()
	{
		return (this->monster->level * this->monster->maxHealth);
	}

	//default constructor
	Battle() {}
};
#endif
