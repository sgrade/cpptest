// A. Word Capitalization

#include <iostream>
#include <string>

int main(){
		
	std::string s;
	std::cin >> s;
	
	putchar (toupper(s[0]) );
	
	std::cout << s.substr(1, s.size()+1);
	
	return 0;
}
