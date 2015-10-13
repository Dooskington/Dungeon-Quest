#include "Monster.hpp"

	Monster::Monster(std::string name, int health, int power) 
	: m_name(name), m_health(health), m_power(power), m_dead(false) {

	}

	Monster::Monster() 
	: m_name(""), m_health(0), m_power(0), m_dead(false) {

	}

	std::string Monster::getName() {
		return m_name;
	}

	void Monster::setName(const std::string newName) {
		m_name = newName;
	}

	int Monster::getHealth() {
		return m_health;
	}

	void Monster::setHealth(const int newHealth) {
		m_health = newHealth;
	}

	int Monster::getPower() {
		return m_power;
	}

	void Monster::setPower(const int newPower) {
		m_power = newPower;
	}

	void Monster::damage(int dmg) {
		m_health -= dmg;
		if(m_health <= 0) {
			std::cout << m_name << " died." << std::endl;
			m_dead = true;
		}
	}

	bool Monster::isAlive() {
		return !m_dead;
	}