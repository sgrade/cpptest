// A. Word

#include <iostream>
#include <bits/stdc++.h>

int main(){
	
	std::string s;
	getline(std::cin, s);
	
	unsigned upperChars = 0;
	
	for (auto& it: s){
		
		if (isupper(it)){
			upperChars++;
		}
	}
	
	if ((s.size()-upperChars)<upperChars){
		transform(s.begin(), s.end(), s.begin(), ::toupper);
	}
	else transform(s.begin(), s.end(), s.begin(), ::tolower);
	
	std::cout << s;
	
	return 0;
}
