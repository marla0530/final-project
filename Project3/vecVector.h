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
vecVector::vecVector() {
	for (int i = 0; i < 10001; i++) {
		vector <string> temp;
		table.push_back(temp);
	}
}
int vecVector::hashFunction(double& key) {
	return key * 100;
}
void vecVector::insert(double& key, string& teamName) {
	int index = hashFunction(key);
	if (index > largest) {
		largest = index;
	}
	table[index].push_back(teamName);
}
void vecVector::top25() {
	int count = 0;
	int temp = largest;
	while (count < 25) {
		for (int i = 0; i < table[temp].size();i++) {
			cout << count + 1 << ", " << table[temp][i] << endl;
			count++;
			if (count == 25) {
				break;
			}
		}
		for (int i = temp - 1; temp > -1; i--)
		{
			if (table[i].size() != 0) {
				temp = i;
				break;
			}
		}
	}
}