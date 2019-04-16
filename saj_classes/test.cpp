#pragma once
#include <iostream>
//#include "enemyclass.h"
//#include "ninjaclass.h"
#include "in_progress_entityclass.h"

//void displayName(std::string a) {//takes the character array representing the string.
//	cout << a.c_str() << endl;
//}

int main() {
	//std::string a = "lol";
	//displayName(a);
	Entity *casey = new Entity;
	
	casey->attack("Elab4");

	getchar();
	getchar();
	return 0;
}