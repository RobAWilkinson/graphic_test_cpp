#ifndef ATTACK_HPP
#define ATTACK_HPP
using namespace std;

class Attack
{
public:
	//name, type,, base damage and damage multipler
	string name, type;
	int baseDamage;
	double baseMultiplier;
	Attack(string name, string type, int baseDamage, double baseMultiplier)
	{
		this->name = name;
		this->type = type;
		this->baseDamage = baseDamage;
		this->baseMultiplier = baseMultiplier;
	}
	Attack(){};
};




#endif
