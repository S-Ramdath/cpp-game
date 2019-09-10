#pragma once
#include <iostream>
#include <string>
#include "playerTools.h"

using namespace std;

class Entity {
	string name = "";
	int health=100;
	int attackPower=10;
	Tools* tazer=NULL;
	Tools* healthPack=NULL;
	Tools* BJT=NULL;
public:
	Entity() {
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
	void setTazer(Tools*a) {
		this->tazer = a;
	}
	void setHealthPack(Tools* a) {
		this->healthPack = a;
	}
	void setBJT(Tools*a) {
		this->BJT = a;
	}
};
//-------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <string>
#include <time.h>
//#include "entityclass.h"
#include "gamemanager.h"
#include "playerTools.h" //includes entity.h already
#include "logger.h"
using namespace std;

class GameManager {
public:
	GameManager() {
		line();
		cout << "WELCOME TO THE GAME!" << endl;
		cout << "Press enter to begin." << endl;
		line();
		getchar();
	}
	~GameManager() {
		line();
		cout << "GAME OVER" << endl;
		cout << "Press enter to exit." << endl;
		line();
		getchar();
	}

	static void createToolsAndLinkToolsToEntities(Entity* a, Entity* b) {//
		tazer* tazerA;
		tazer* tazerB;
		healthPack* healthPackA;
		healthPack* healthPackB;
		BJT* bjt;
		tazerA->setOwner(a);
		tazerB->setOwner(b);

	}

	static void linkEntitiesToTools(Entity* a, Entity* b,Tools*tazerA,Tools*tazerB,Tools*healthPackA,Tools*healthPackB,Tools*bjt) {
		
		a->setBJT(bjt);
		b->setBJT(bjt);
	}

	static void oneAttackTurn(Entity* a, Entity* b) {//a attacks b ONLY.
		if ((a->getHealth() > 0) && (b->getHealth() > 0)) {
			line();
			cout << a->getName() << " attacks and inflicts " << a->getAttackPower() << " damage to " << b->getName() << "!" << endl;//announces a's attack on b.
			b->setHealth(b->getHealth() - a->getAttackPower());//subtracts a's attackpower from b's health.
			cout << b->getName() << "'s health is now " << b->getHealth() << endl;//displays b's health.
			line();
		}
		else return;
	}

	static void playerChoice(Entity* a, Entity* b, Tools* t) {//allows the player (before the other player attacks) controlling entity a (NOTE: a points to the entity.) to evaluate the battle situation and then use tools accordingly.
		if ((a->getHealth() > 0) && (b->getHealth() > 0)) {
			//int choice;
			cout << b->getName() << "'s stats are:\n";
			cout << "Health: " << b->getHealth() << endl;
			cout << "Attackpower: " << b->getAttackPower() << endl;
			line();

			cout << a->getName() << "'s stats are:\n";
			cout << "Health: " << a->getHealth() << endl;
			cout << "Attackpower: " << a->getAttackPower() << endl;
			line();

			cout << "Player controlling " << a->getName() << ", please select what you would like to do:\n";
			cout << "1: Use Healthpack (increases your health by 100)\n";
			cout << "2: Use Tazer (decreases opponent attack power by 1)\n";
			cout << "3. BJT DESIGN PROJECT. (hehehehehehehehehehhehehehehehehehehehehehe!)\n";
			cout << "4. None. (u a bad man?!)\n";

			//choose(a, b, t);

		}
		else {
			cout << b->getName() << "'s stats are:\n";
			cout << "Health: " << b->getHealth() << endl;
			cout << "Attackpower: " << b->getAttackPower() << endl;
			line();
			cout << a->getName() << "'s stats are:\n";
			cout << "Health: " << a->getHealth() << endl;
			cout << "Attackpower: " << a->getAttackPower() << endl;
			line();
			return;
		}
	}

	static void choose(Entity* a, Tools* t) {
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			//a->
			break;
		case 2:
			//t->tazer(20, b);
			break;
		case 3:
			//t->BJT_PROJECT(a, b);
			break;
		case 4:
			break;
		default:
			cout << "Incorrect selection. Try again:" << endl;
			//choose(a, b, t);
		}
	}

	static void line() {//draws a line. 
		cout << "-------------------------------------------" << endl;
	}
	static void pause() {
		line();
		cout << "Press enter to continue." << endl;
		line();
		getchar();
		//line();
	}

	static void newLine() {
		cout << "\n";
	}
};
//--------------------------------------------------------------------------------
#pragma once
#include <fstream>
#include <iostream>

using namespace std;

void logger(string a) {//outputs to text file and to console.
	cout << a;
	ofstream var("log.txt");
	var << a;
	var.close();
}
//-------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------------------------------------------------
#include "gamemanager.h" //gamemanager.h includes all other header files.

void winCheck(Entity* obj1, Entity* obj2);
void test();
void test2();

int main() {
	test();
	return 0;
}

void winCheck(Entity*obj1,Entity*obj2) {
	if (obj1->getHealth() == -1000000 && obj2->getHealth() == -1000000) {//check if BJT DP was used.
		return;
	}
	if (obj2->getHealth() <= 0) {//check obj2 health.
		delete obj2;//destroy obj2.
		cout << obj1->getName() << " wins!" << endl;//obj1 wins.
		return;
	}
	if (obj1->getHealth() <= 0) {//check obj1 health.
		delete obj1;//destroy obj2.
		cout << obj2->getName() << " wins!" << endl;//obj2 wins.
		return;
	}
}

void test() {
	GameManager* instance = new GameManager;

	Entity* obj1 = new Entity;
	Entity* obj2 = new Entity;

	Tools* tools = new Tools;

	instance->pause();
	//while ((obj1 != NULL)&&(obj2 != NULL)) {//inside the loop is the code that represents one round of the game.
	while ((obj1->getHealth() > 0) && (obj2->getHealth() > 0)) {//inside the loop is the code that represents one round of the game.
		//next dev step: get this working then encapsulate this whole round into one function.
		if ((obj1->getHealth() > 0) && (obj2->getHealth() > 0)) instance->playerChoice(obj1, obj2, tools);//player controlling obj1 has to choose now.
		winCheck(obj1, obj2);
		if ((obj1->getHealth() > 0) && (obj2->getHealth() > 0)) instance->oneAttackTurn(obj1, obj2);//obj1 attacks obj2.
		winCheck(obj1, obj2);
		if ((obj1->getHealth() > 0) && (obj2->getHealth() > 0)) instance->playerChoice(obj2, obj1, tools);//player controlling obj2 has to choose now.
		winCheck(obj1, obj2);
		if ((obj1->getHealth() > 0) && (obj2->getHealth() > 0)) instance->oneAttackTurn(obj2, obj1);//obj2 attacks obj1.
		winCheck(obj1, obj2);
		//one round is complete!
	}
	instance->pause();

	//delete obj1;
	//delete obj2;
	delete tools;
	delete instance;
}

void test2() {

}

