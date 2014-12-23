#ifndef BATTLE_HPP
#define BATTLE_HPP

// Create the battle class


class Battle
{
private:
	Creature player;
	Monster monster;
public:
	Battle(Creature player, Monster monster)
	{
		this->player = player;
		this->monster = monster;
	}
	void fight()
	{
		std::vector<std::string> choices;
		std::string debug;
		bool hit_or_miss;
		Attack playerAttack, monsterAttack;
		int index;
		// pass the different attack types as a vector of strings to dialogue
        // pass the different attack types as a vector of strings to dialogue
        for(int i =0; i < this->player.attacks.size();i++)
        {
            choices.push_back(player.attacks[i].name);
            
        }
		while (this->monster.alive())
		{
			// receive a 1 based index number of which attack should happen
			index = Dialogue("What would you like to attack with?", choices).activate();
			playerAttack = this->player.attacks[--index];
			monsterAttack = this->monster.randomAttack();
			std::cout << "You attack with " << playerAttack.name << std::endl;
			hit_or_miss = player.hit();


			/// Fix player.hit() acting weird something to do with rand() I believe

			if (hit_or_miss)
			{
				std::cout << "Your attack hits!" << std::endl;

				// Monster health only dropping through the first time
				monster.dropHealth(damage(playerAttack));
				std::cout << "It does " << std::to_string(damage(playerAttack)) << " damage, nice job!" << std::endl;
				std::cout << this->monster.name << " has " << this->monster.health << "HP remaining" << std::endl;
				std::cout << this->monster.name << " attacks with " << monsterAttack.name << std::endl;
				std::cout << "It does " << damage(monsterAttack) << "to you!" << std::endl;
				this->player.health -= damage(monsterAttack);
				std::cout << this->player.name << " now has " << this->player.health << " HP" << std::endl;

			}
			else
			{
				std::cout << "oooh so close, you missed" << std::endl;
			}
		}
		player.exp += expGain();
		std::cout << "Congratulations you defeated a:";
		std::cout << this->monster.name << std::endl;
		std::cout << this->player.name << " has gained ";
		std::cout << expGain() << "XP";
		std::cout << "by Defeating a " << this->monster.name << std::endl;
		if (this->player.levelUp())
		{
			std::cout << " Congratulations!" << std::endl;
			std::cout << this->player.name << " has leveled up" << std::endl;
			std::cout << this->player.name << " is now " << player.level << std::endl;
		}
	}

	int damage(Attack attack)
	{	
		return attack.baseMultiplier * attack.baseDamage;

	}
	int expGain()
	{
		return (this->monster.level * this->monster.maxHealth);
	}

	//default constructor
	Battle() {}
};














#endif