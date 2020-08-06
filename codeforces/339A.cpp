// A. Helpful Maths

#include <iostream>
#include <bits/stdc++.h>

int main(){
	
	std::string s;
	
	getline(std::cin, s);
	
	std::sort(s.begin(), s.end());
	
	auto it=s.begin();
	for (; it<s.end()-1; ++it){
		
		if (isdigit(*it)){
			std::cout << *it << "+";
		}
		
	}
	
	std::cout << *it << std::endl;
	
	return 0;
	
}
