// A. Boy or Girl

#include <iostream>
#include <set>

int main(){
	
	std::string s;
	std::cin >> s;
	
	std::set<char> tmp(s.begin(), s.end());
	
	std::string output = tmp.size()%2 ? "IGNORE HIM!": "CHAT WITH HER!";
	
	std::cout << output;

return 0;
}
