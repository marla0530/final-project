#include "vecVector.h"

// initialize a vector of vectors with size of 10001 because there could be 10001 data point
vecVector::vecVector() {
	for (int i = 0; i < 10001; i++) {
		vector <string> temp;
		table.push_back(temp);
	}
}

//multiply the input key by 100 so it can represent the index of vector
int vecVector::hashFunction(double& key) {
	return key * 100;
}

// insert the data into the table while keep track of the largest element
void vecVector::insert(double& key, string& teamName) {
	int index = hashFunction(key);
	if (index > largest) {
		largest = index;
	}
	table[index].push_back(teamName);
}

//print out the top 25 teams
void vecVector::top25() {
	int count = 0;
	int temp = largest;
	while (count < 25) {
		
		//first print out every thing in the vector that has the largest values
		for (int i = 0; i < table[temp].size(); i++) {
			cout << count + 1 << ", " << table[temp][i] << endl;
			count++;
			
			//if 25 teams were printed stop
			if (count == 25) {
				break;
			}
		}
		
		//update the next vector with highest element by looking for vectors 1 index at a time down 
		for (int i = temp - 1; temp > -1; i--)
		{
			if (table[i].size() != 0) {
				temp = i;
				break;
			}
		}
	}
}
