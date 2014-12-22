#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <string>
// createThe  Monster class

class Monster
{
	//Monster clas has these properties:
	//name,
	//type: undead, goblin etc etc
	// Health, current Hp
	//MaxHealth, how much HP it has,
	//Hit rate, how often it connects
	//Strength, how hard it hits for
	//level, 
public:
	std::string name, type;
	int health, maxHealth, str;
	double hitRate;
	unsigned int level;

	Monster(std::string name, std::string type, int health, int str, double hitRate, unsigned int level)
	{
		this->name = name;
		this->type = type;
		this->health = health;
		this->str = str;
		this->hitRate = hitRate;
		this->level = level;
	}
	bool hit()
	{
		if ((rand() % 20) < this->hitRate)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int baseDamage()
	{
		return ((this->level * this->str) * .25);


	}
		Monster(){}




	
};

#endif