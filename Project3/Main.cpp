#include "vecVector.h"
#include "bst.h"
#include <istream>
#include <sstream>
#include <fstream>
#include <chrono>
using namespace std::chrono;

typedef high_resolution_clock Clock;

int main()
{
	vecVector vV;
	BST tree;

	ifstream inFile("data.csv");
	if (inFile.is_open())
	{
		cout << "reading data......" << endl;
		string headers;
		string team;
		string line;
		string temp;
		double power;
		getline(inFile, headers);
		for(int i=0;i<50000;i++) {
			getline(inFile, line);
			istringstream stream(line);
			getline(stream, team, ',');
			getline(stream, temp);
			power = stod(temp);
			vV.insert(power, team);
			tree.root=tree.insert(tree.root, power, team);
		}
	}
	inFile.close();
	cout << "Complete" << endl;



	cout << "Array Vector approach" << endl;
	cout << endl;
	auto t1 = Clock::now();
	vV.top25();
	auto t2 = Clock::now();
	cout << "search time: " << duration_cast<nanoseconds>(t2 - t1).count()<< " nanoseconds" << endl;
	cout << endl;

	cout << "K th largest from a BST approach" << endl;
	cout << endl;
	t1 = Clock::now();
	tree.top25();
	t2 = Clock::now();
	cout << "search time: " << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
	cout << endl;

	return 0;
}