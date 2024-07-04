#include <iostream>
#include  <cmath>
#include<string>
#include<algorithm>
#include <vector>

#include<map>
using namespace std;
int main()
{
	int step;
	cin >> step;
	map<string, int>mp;
	//int loop = 1;




	for (int i = 0; i < step; i++) {
		int choice;
		cin >> choice;
		string name;
		switch (choice) {
			case 1:
				cin >> name;
				int grade;
				cin >> grade;
				mp[name] = grade;
				cout << "OK" << endl;
				break;
			case 2:

				cin >> name;
				if (mp.find(name) == mp.end())
					cout << "Not found" << endl;
				else
					cout << mp.find(name)->second << endl;
				break;
			case 3:

				cin >> name;
				if (mp.find(name) == mp.end())
					cout << "Not found" << endl;
				else {
					mp.erase(name);
					cout << "Deleted successfully" << endl;
				}
				break;
			case 4:
				cout << mp.size() << endl;
				break;
		}

	}

}
