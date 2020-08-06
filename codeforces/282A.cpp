// A. Bit++

#include <iostream>
using namespace std;

int main(){
	
	int n, x=0, indexOfX;
	cin >> n;
	std::string s, operation;
	
	for (int i=0; i< n; ++i){
		
		cin >> s;
		
		indexOfX = s.find("X");
		
		operation = (indexOfX == 0) ? s.substr(1, 2) : s.substr(0, 2);
		
		if (operation == "++") x++;
		else x--;		
	}
	
	cout << x;

	return 0;

}
