#pragma once
#include <iostream>
#include <string>
#include "entityclass.h"
#include "gamemanagerclass.h"
#include "playertoolsclass.h"
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

	static void oneAttackTurn(Entity* a,Entity*b) {//a attacks b ONLY.
		if ((a != NULL)&&(b != NULL)) {
			line();
				cout << a->getName() << " attacks and inflicts " << a->getAttackPower() << " damage to " << b->getName() << "!" << endl;//announces a's attack on b.
				b->setHealth(b->getHealth() - a->getAttackPower());//subtracts a's attackpower from b's health.
				cout << b->getName() << " was attacked and sustained " << a->getAttackPower() << " damage from " << a->getName() << "!" << endl;//announces the effect of a's attack on b.
				cout << b->getName()<<"'s health is now " << b->getHealth() << endl;//displays b's health.
				//cout << "statusUpdate should be called now." << endl;
				b->statusUpdate(b);//check b's status, if it's health<=0 it displays that b is defeated and assigns b's pointer to NULL.			
			line();	
		}
		else return;
	}

	static void playerChoice(Entity*a,Entity*b,Tools*t) {//allows the player (before the other player attacks) controlling entity a (NOTE: a points to the entity.) to evaluate the battle situation and then use tools accordingly.
		if ((a != NULL)&&(b != NULL)) {
			int choice = 0;
			cout << b->getName() << "'s stats are:\n";
			cout << "Health: " << b->getHealth() << endl;
			cout << "Attackpower: " << b->getAttackPower() << endl;
			line();

			cout << a->getName() << "'s stats are:\n";
			cout << "Health: " << a->getHealth() << endl;
			cout << "Attackpower: " << a->getAttackPower() << endl;
			line();

			cout << "Player controlling " << a->getName() << ", before you are attacked, please select one tool that you would like to use:\n";
			cout << "1: 100-Healthpack.\n";
			cout << "2: Tazer\n";
			cout << "3. BJT DESIGN PROJECT. (hehehehehehehehehehhehehehehehehehehehehehe!)\n";
			cout << "4. None. (u a bad man?!)\n";

			
			cin >> choice;
			//test user input
			//while 
			switch (choice) {
			case 1:
				t->healthPack(100, a);
				break;
			case 2:
				t->tazer(50, b);
				break;
			case 3:
				t->BJT_PROJECT(a, b);
				break;
			case 4:
				break;
			}
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

			cout << "One of you has been already defeated!\n";
			return; }
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

	/*void instantiator(GameManager* instance, Entity* m, Entity* n) {
	instance->line();

	//instance->oneRound(*instance, *n, *m);

	//instance->AttackPrompt();
	//n->attack();
	//m->attacked(n->accessAttackPower());
	//m->statusUpdate(m, instance);

	line();

	//instance->monsterAttackPrompt();
	//m->attack();
	//n->attacked(m->accessAttackPower());
	//n->statusUpdate(n, instance);

	line();

	delete instance;
}*/

};