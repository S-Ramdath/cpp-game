#include "gamemanager.h" //gamemanager.h includes all other header files.

//void winCheck(Entity* obj1, Entity* obj2);
//void test();
void test2();

int main() {
	test2();
	return 0;
}


/*
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
*/

void test2() {
	GameManager game1;
}