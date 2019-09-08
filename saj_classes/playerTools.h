#pragma once
#include <iostream>
#include "entityclass.h"

using namespace std;
class oldTools {
public:
	
};

class Tools {
protected:
	bool used = false;
	void useUpdate() {
		used = true;
	}
};

class healthPack : Tools {
	static void use(int amount, Entity* a) {//gives a health boost to an entity by a specified amount.
		a->setHealth(a->getHealth() + amount);
	}
};

class tazer : Tools {
	static void use(int amount, Entity* a) {//decreases an entity's attack power by a specified amount.
		a->setAttackPower(a->getAttackPower() - amount);
	}
};

class BJT_DESIGN_PROJECT : Tools {
	static void use(Entity* a, Entity* b) {// ask a year 2 what will go on heehehehehhe.
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\tBJT DESIGN PROJECT COMES INTO THE GAME\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		a->setHealth(-1000000);
		b->setHealth(-1000000);
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\tBJT DESIGN PROJECT ATTACKS\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\tBJT DESIGN PROJECT WINS\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	}
};