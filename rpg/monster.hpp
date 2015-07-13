#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <string>
#include <vector>
#include "attack.hpp"
// createThe  Monster class

using namespace std;

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
	string name, type;
	int health, maxHealth, str;
	double hitRate;
	unsigned int level;
	vector < Attack > attacks;

	Monster(string name, string type, int health, int str, double hitRate, unsigned int level)
	{
		this->name = name;
		this->type = type;
		this->health = health;
		this->maxHealth = health;
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
	void addAttack(string attack_name, string attack_type, int baseDamage, double baseMultiplier)
	{
		Attack new_attack = Attack(attack_name, attack_type, baseDamage, baseMultiplier);
		this->attacks.push_back(new_attack);

	}
	Attack randomAttack()
	{
		return this->attacks[rand() % this->attacks.size()];
	}
	void dropHealth(int damage)
	{
		this->health -= damage;
	}
	bool alive()
	{
		if (this->health > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// Default constructor for declarations
		Monster(){}




	
};

#endif
