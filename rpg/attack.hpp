#ifndef ATTACK_HPP
#define ATTACK_HPP

class Attack
{
public:
	//name, type,, base damage and damage multipler
	std::string name, type;
	int baseDamage;
	double baseMultiplier;
	Attack(std::string name, std::string type, int baseDamage, double baseMultiplier)
	{
		this->name = name;
		this->type = type;
		this->baseDamage = baseDamage;
		this->baseMultiplier = baseMultiplier;
	}
	Attack(){};
};




#endif