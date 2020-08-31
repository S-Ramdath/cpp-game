#pragma once
#include <iostream>
#include <string>
#include <time.h>
//#include "entityclass.h"
//#include "gamemanager.h"
#include "playerTools.h" //includes entity.h already
#include "logger.h"
using namespace std;

class GameManager {
public:
	GameManager() {
		line();
		cout << "WELCOME TO THE GAME!" << endl;
		cout << "Press enter to begin." << endl;
		this->twoPlayerGame;
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
	
	static void winCheck(Entity* obj1, Entity* obj2) {
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


	static void twoPlayerGame() {
		Entity* obj1 = new Entity;
		Entity* obj2 = new Entity;

		Tools* tools = new Tools;

		pause();
		//while ((obj1 != NULL)&&(obj2 != NULL)) {//inside the loop is the code that represents one round of the game.
		while ( ( (obj1->getHealth() > 0) && (obj2->getHealth() > 0) ) || ( (&obj1!=NULL)&&(&obj2!=NULL) ) ) {
			//inside the loop is the code that represents one round of a two player game.
			//next dev step: get this working then encapsulate this whole round into one function.
			if ((obj1->getHealth() > 0) && (obj2->getHealth() > 0)) playerChoice(obj1, obj2, tools);//player controlling obj1 has to choose now.
			winCheck(obj1, obj2);
			if ((obj1->getHealth() > 0) && (obj2->getHealth() > 0)) oneAttackTurn(obj1, obj2);//obj1 attacks obj2.
			winCheck(obj1, obj2);
			if ((obj1->getHealth() > 0) && (obj2->getHealth() > 0)) playerChoice(obj2, obj1, tools);//player controlling obj2 has to choose now.
			winCheck(obj1, obj2);
			if ((obj1->getHealth() > 0) && (obj2->getHealth() > 0)) oneAttackTurn(obj2, obj1);//obj2 attacks obj1.
			winCheck(obj1, obj2);
			//one round is complete!
		}
		pause();
	}

	

};