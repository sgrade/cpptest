// A. Translation

#include <iostream>
#include <bits/stdc++.h>

int main(){
	
	std::string s, t;
	std::cin >> s >> t;
	
	reverse(s.begin(), s.end());
	
	int different = s.compare(t);
	
	if (different) {
		std::cout << "NO";
	}
	else std::cout << "YES";
	
	return 0;
}
