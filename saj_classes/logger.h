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