#ifndef BATTLE_HPP
#define BATTLE_HPP

// Create the battle class


class Battle
{
public:
	Battle(Creature player, Monster monster)
	{
		std::vector<std::string> choices;
		std::string debug;
		bool hit_or_miss;
		Attack playerAttack, monsterAttack;
		int index;
		// pass the different attack types as a vector of strings to dialogue
		for each (Attack attack in player.attacks)
		{
			choices.push_back(attack.name);

		}
		// receive a 1 based index number of which attack should happen
		index = Dialogue("What would you like to attack with?", choices).activate();
		playerAttack = player.attacks[--index];
		monsterAttack = monster.randomAttack();
		std::cout << "You attack with " << playerAttack.name << std::endl;
		hit_or_miss = player.hit();
		

		/// Fix player.hit() acting weird something to do with rand() I believe

		if (hit_or_miss)
		{
			std::cout << "Your attack hits!" << std::endl;
			debug = std::to_string(damage(playerAttack, monster));

			// Monster health only dropping through the first time
			monster.dropHealth(damage(playerAttack, monster));
			std::cout << "It does " << std::to_string(damage(playerAttack, monster)) << " damage, nice job!" << std::endl;
			std::cout << monster.name << " has " << monster.health << "HP remaining" << std::endl;
		}
		else
		{
			std::cout << "oooh so close, you missed" << std::endl;
		}

	}

	int damage(Attack attack, Monster attackee)
	{	
		return attack.baseMultiplier * attack.baseDamage;

	}
};














#endif