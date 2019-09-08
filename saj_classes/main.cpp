#include "gamemanagerclass.h" //gamemanager.h includes all other header files.

int main() {

	GameManager *instance = new GameManager;

	Entity *obj1 = new Entity;
	Entity *obj2 = new Entity;

	Tools *tools = new Tools;
	
	instance->pause();
	//while ((obj1 != NULL)&&(obj2 != NULL)) {//inside the loop is the code that represents one round of the game.
	while ((obj1->alive != false) && (obj2->alive != false)) {//inside the loop is the code that represents one round of the game.
		//next dev step: get this working then encapsulate this whole round into one function.
		if ((obj1 != NULL) && (obj2 != NULL))
			instance->oneAttackTurn(obj1, obj2);//obj1 attacks obj2.
		if ((obj1!=NULL)&&(obj2!=NULL))
			instance->playerChoice(obj1, obj2, tools);//player controlling obj1 has to choose now.
		if (obj1 != NULL && obj2 != NULL)
			instance->oneAttackTurn(obj2, obj1);//obj2 attacks obj1.
		if (obj1 != NULL && obj2 != NULL)
			instance->playerChoice(obj2, obj1, tools);//player controlling obj2 has to choose now.
		//one round is complete!
	}
	instance->pause();

	delete obj1;
	delete obj2;
	delete tools;
	delete instance;
	
	return 0;
}