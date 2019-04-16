#include <iostream>
using namespace std;
//inheritance and polymorphism

//polymorphism
class Enemy {
protected:
	
	int attackPower;
public:
	//virtual void attack() {//this is a virtual function. This may or may not be overidden in the derived class.
	//}
	virtual void attack() = 0;//this is a pure virtual function. This must be overridden in the derived class.
		void setAttackPower(int a) {
		attackPower = a;
	}
		

};


class Ninja :public Enemy {
public:
	void attack() {
		cout << "Ninja attacks!" << endl;
	}
	
};

class Monster :public Enemy {
public:
	void attack() {
		cout << "Monster attacks!" << endl;
	}
	
};

int main() {

	Ninja n1;
	Monster m1;
	Enemy*e1 = &n1;//pointer e1 points to the object n1.
	Enemy*e2 = &m1;//pointer e2 points to the object m1.

	e1->setAttackPower(20);
	e2->setAttackPower(80);

	e1->attack();
	e2->attack();

	getchar();
	return 0;
}