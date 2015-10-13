#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <iostream>
#include <string>

class Monster {
	public:
		Monster(std::string name, int health, int power);
		Monster();

		std::string getName();
		void setName(const std::string newName);
		int getHealth();
		void setHealth(const int newHealth);
		int getPower();
		void setPower(const int newPower);

		void damage(int dmg);
		bool isAlive();

	private:
		std::string m_name;
		int m_health;
		int m_power;
		bool m_dead;
};

#endif