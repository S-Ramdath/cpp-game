#pragma once
#include <iostream>
#include "gameuiclass.h"
using namespace std;


class Enemy {
protected:
	std::string name;
	int health;
	int attackPower;
public:
	void setHealth(int a) {
		health = a; cout << "Entity health = " << health << endl;
	}
	void setAttackPower(int a) {
		attackPower = a; cout << "Entity attack power = " << attackPower << endl;
	}//sets the entity attack power.
	void healthChanger(int enemyAttackPower) {
		health -= enemyAttackPower;
	}//adjusts the attaked entity's health when attacked.
	virtual void attack(string a) {//can be overridden.
		//std::cout << a;
		cout << " attacks and inflicts " << attackPower << " damage to its opponent!" << endl;
	}
	int accessAttackPower() {
		return attackPower;
	}
	int accessHealth() {
		return health;
	}
	void healthStatus() {
		cout << "Entity's health is now " << health << endl;
	}

	virtual void attack() = 0;//must be overridden in derived class.
	virtual void attacked(int enemyAttackPower) = 0;//must be overridden in derived class.
};


class Ninja :public Enemy {//monster class was lost (accidentally deleted). It was exactly like this class.
public:
	Ninja() {
		//printf("&s", name);
		cout << "Ninja ready!" << "\n";
		setAttackPower(20);
		setHealth(50);
	}
	void attack() {
		cout << "Ninja attacks and inflicts " << attackPower << " damage to its opponent!" << endl;
	}
	void attacked(int enemyAttackPower) {
		healthChanger(enemyAttackPower); cout << "Ninja was attacked and sustained " << enemyAttackPower << " damage from its opponent!" << endl;
		healthStatus();
	}
	void statusUpdate(Ninja* a, GameUI* instance) {
		cout << "Ninja's statusUpdate Function has been called." << endl;
		if (health <= 0) {
			delete a;

			instance->line();
		}
	}
	~Ninja() {
		cout << "Ninja is defeated!" << endl;
	}
};
