#pragma once
#include <iostream>
#include <string>
using namespace std;

class Entity {
protected:
	string name = "default";
	//vector<char> a= name;
	int health=10;
	int attackPower=10;

public:
	Entity() {
		cout << "\nEntity created!" << "\n";
		userSetName();
		userSetHealth();
		userSetAttackPower();
	}

	//~Entity() {
	//	cout << name << " is defeated!" << endl;
	//}

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

	void userSetHealth() {//allows user to set entity health.
		int a;
		cout << "Enter "<<name<<"'s health:";
		cin >> a;
		health = a;
		cout << name << "'s health = " << health << endl;
	}

	void userSetAttackPower() {//allows user to set entity attack power.
		int a;
		cout << "Enter "<<name<<"'s attack power:";
		cin >> a;
		attackPower = a;
		cout << name<<"'s attack power = " << attackPower << endl;
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
	
	void statusUpdate(Entity*a) {
		if (a->health <= 0) {
			//delete a; //
			cout << a->getName() << " is defeated!" << endl;
			a = NULL;
			
		}
	}

	//int attack(string b) {//Shows that entity attacks and returns the entity's attack power.
	//	if (health <= 0) {
	//		delete this;
	//		return 0;
	//	}
	//	cout << name << " attacks and inflicts " << attackPower <<" damage"<< " to " << b <<"!"<< endl;
	//	return attackPower;
	//}

	//void attack2(Entity* a) {//entity attacks and victim is also affected.
	//	if (a != NULL) {
	//		if (health <= 0) {
	//			delete this;
	//			return;
	//		}
	//		cout << this->name << " attacks and inflicts " << attackPower << " damage" << " to " << a->name << "!" << endl;
	//		cout << a->name << " was attacked and sustained " << this->attackPower << " damage from " << a->name << "!" << endl;
	//		a->setHealth(a->getHealth() - this->health);
	//	}
	//	else return;
	//}



	//void attacked(int enemyAttackPower, string enemyName) {//Shows that the entity has been attacked and subtracts the attacker's attack power from the entity's health.
	//	if (health <= 0) {
	//		delete this;
	//		return;
	//	}
	//	health -= enemyAttackPower;
	//	cout << name << " was attacked and sustained " << enemyAttackPower << " damage from " << enemyName << "!" << endl;
	//	cout << name << "'s health is now " << health << endl;
	//	if (health <= 0) {
	//		delete this;
	//		return;
	//	}
	//}
};
