// A. Gennady and a Card Game

#include <iostream>
#include <sstream>

using namespace std;


int main(){
	
	string cardOnTable;
	getline(cin, cardOnTable);
	
	string cards;
	getline(cin, cards);
	
	stringstream ss(cards);
	string tmp;
	while (ss >> tmp){
		if (tmp[0]==cardOnTable[0] || tmp[1]==cardOnTable[1]){
			cout << "YES";
			exit(0);
		}
	}
	cout << "NO";
	
	return 0;
}
