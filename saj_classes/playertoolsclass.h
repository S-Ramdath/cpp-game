#pragma once

class Tools {
public:
	static void healthPack(int increaseSize, Entity*a) {//gives a health boost to entity pointed to by a.
		a->setHealth(a->getHealth()+increaseSize);
		//healthToIncrease += increaseSize;
	}
	static void tazer(int decreasemagnitude, Entity*a){//weakens the entity pointed to by a.
		a->setAttackPower(a->getAttackPower() - decreasemagnitude);
		//enemyAttackPower -= decreaseSize;
		}
	static void BJT_PROJECT(Entity *a,Entity *b) {
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\tBJT DESIGN PROJECT COMES INTO THE GAME\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		a->setHealth(-1000000);
		b->setHealth(-1000000);
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\tBJT DESIGN PROJECT ATTACKS\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		
		//a->statusUpdate2();
		//a->statusUpdate(a);
		
		//b->statusUpdate2();
		//b->statusUpdate(b);
		
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\tBJT DESIGN PROJECT WINS\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	}
};
