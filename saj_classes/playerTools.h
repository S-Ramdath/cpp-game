#pragma once
#include <iostream>
#include "entity.h"

using namespace std;

class Tools {
protected:
	Entity* owner = NULL;
	bool used = false;
public:
	void usedUpdate() {
		used = true;
	}
	void setOwner(Entity*a) {
		owner = a;
	}
};
/*
class healthPack : public Tools {
	void use(int amount, Entity* a) {//gives a health boost to an entity by a specified amount.
		if (used == false) a->setHealth(a->getHealth() + amount);
		else cout << "This has been used already" << endl;
	}
};

class tazer : public Tools {
	void use(int amount, Entity* a) {//decreases an entity's attack power by a specified amount.
		if (used == false) a->setAttackPower(a->getAttackPower() - amount);
		else cout << "This has been used already" << endl;
	}
};

class BJT: public Tools {
	void use(Entity* a, Entity* b) {// year ones, ask a year 2 what will go on heehehehehhe.
		if (used == false) {cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\tBJT DESIGN PROJECT COMES INTO THE GAME\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		a->setHealth(-1000000);
		b->setHealth(-1000000);
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\tBJT DESIGN PROJECT ATTACKS\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\tBJT DESIGN PROJECT WINS\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl; }
		else cout << "This has been used already" << endl;
	}
class healthPack : public Tools {
	void use(int amount, Entity* a) {//gives a health boost to an entity by a specified amount.
		if (used == false) a->setHealth(a->getHealth() + amount);
		else cout << "This has been used already" << endl;
	}
};

class tazer : public Tools {
	void use(int amount, Entity* a) {//decreases an entity's attack power by a specified amount.
		if (used == false) a->setAttackPower(a->getAttackPower() - amount);
		else cout << "This has been used already" << endl;
	}
};

class BJT: public Tools {
	void use(Entity* a, Entity* b) {// year ones, ask a year 2 what will go on heehehehehhe.
		if (used == false) {cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\tBJT DESIGN PROJECT COMES INTO THE GAME\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		a->setHealth(-1000000);
		b->setHealth(-1000000);
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\tBJT DESIGN PROJECT ATTACKS\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\tBJT DESIGN PROJECT WINS\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl; }
		else cout << "This has been used already" << endl;
	}
*/

class healthPack : public Tools {
	void use(int amount, Entity* a) {//gives a health boost to an entity by a specified amount.
		if (used == false) a->setHealth(a->getHealth() + amount);
		else cout << "This has been used already" << endl;
	}
};

class tazer : public Tools {
	void use(int amount, Entity* a) {//decreases an entity's attack power by a specified amount.
		if (used == false) a->setAttackPower(a->getAttackPower() - amount);
		else cout << "This has been used already" << endl;
	}
};

class BJT: public Tools {
	void use(Entity* a, Entity* b) {// year ones, ask a year 2 what will go on heehehehehhe.
		if (used == false) {cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\tBJT DESIGN PROJECT COMES INTO THE GAME\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		a->setHealth(-1000000);
		b->setHealth(-1000000);
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\tBJT DESIGN PROJECT ATTACKS\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\tBJT DESIGN PROJECT WINS\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl; }
		else cout << "This has been used already" << endl;
	}
};