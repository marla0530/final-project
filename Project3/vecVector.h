#pragma once
using namespace std;
#include <vector>
#include <string>
#include<iostream>
class vecVector {
private:
	vector <vector <string> >table;
	int largest = -1;
public:
	void insert(double& key, string& teamName);
	int hashFunction(double& key);
	void top25();
	vecVector();
};
