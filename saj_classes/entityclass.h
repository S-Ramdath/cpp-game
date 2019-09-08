#pragma once
#include <iostream>
#include <string>
#include <time.h>
using namespace std;


class Entity {
//protected:
	string name = "";
	int health=100;
	int attackPower=10;

public:
	Entity() {
		cout << "\nEntity created!" << "\n";
		userSetName();
	}

	~Entity() {
		cout << name << " is defeated!" << endl;
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

	void displayName() {//display name of entity.
		cout << name << endl;
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
};
