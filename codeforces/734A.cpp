// A. Anton and Danik

#include <iostream>
#include <algorithm>

int main(){
	
	int n;
	std::string s;
	
	scanf("%d", &n);
	std::cin >> s;
	
	unsigned antonWins = count(s.begin(), s.end(), 'A');
	
	if (s.size() - antonWins > antonWins) std::cout << "Danik";
	else if (s.size() - antonWins < antonWins) std::cout << "Anton";
	else std::cout << "Friendship"; 
	
	return 0;
}
