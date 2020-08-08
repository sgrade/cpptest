//A. Nearly Lucky Number

#include <iostream>
#include <algorithm>

int main(){
	
	std::string s;
	std::cin >> s;
	
	int numOfFours=0, numOfSevens=0;
	
	numOfFours = count(s.begin(), s.end(), '4');
	//std::cout << numOfSevens << std::endl;
	
	numOfSevens = count(s.begin(), s.end(), '7');
	//std::cout << numOfFours << std::endl;
	
	
	int total = numOfFours + numOfSevens;
	//std::cout << total << std::endl;
	if (total == 4 || total == 7){
		std::cout << "YES";
	}
	else std::cout << "NO";
	
	return 0;
}
