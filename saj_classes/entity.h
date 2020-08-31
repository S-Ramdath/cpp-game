#pragma once
#include <iostream>
#include <string>
#include "playerTools.h"

using namespace std;

class Entity {
	string name = "";
	int health = 100;
	int attackPower = 10;

	//Tools* tazer = NULL;
	tazer *my_tazer;

	//healthPack* healthPack = NULL;
	healthPack *my_healthPack;

	//Tools* BJT = NULL;
	BJT *my_BJT;

public:
	Entity() {
		this->my_tazer = NULL;
		this->my_healthPack = NULL;
		this->my_BJT = NULL;
		cout << "\nEntity created!" << "\n";
		userSetName();
	}
	~Entity() {
		//make announceDefeat to call this.
	}
	void userSetName() {//allows user to set entity name.
		string input;
		cout << "Enter a name for the entity:";
		cin >> input;
		if (input == "") {
			name = "default";
		}
		else {
			name = input;
		}
		cout << "Entity name is set as " << name << endl;
	}
	void setHealth(int a) {
		health = a;
	}
	void setAttackPower(int a) {
		attackPower = a;
	}
	string getName() {//returns the entity's name.
		return name;
	}
	int getHealth() {//returns the entity's health.
		return health;
	}
	int getAttackPower() {
		return attackPower;
	}
	void displayHealth() {
		cout << this->name << "'s health is " << this->health;
	}
	void displayAttackPower() {
		cout << this->name << "'s attack power is " << this->attackPower;
	}
	void setTazer(tazer* a) {
		this->my_tazer = a;
	}
	void setHealthPack(healthPack* a) {
		this->my_healthPack = a;
	}
	void setBJT(BJT* a) {
		this->my_BJT = a;
	}
};
