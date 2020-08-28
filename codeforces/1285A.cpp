// A. Mezo Playing Zoma

#include <iostream>
#include <string>
#include <algorithm>


int main(){
	
	int n;
	scanf("%d\n", &n);
	
	std::string s;
	std::getline(std::cin, s);
	
	int l, r;
	l = std::count(s.begin(), s.end(), 'L');
	r = n-l;
	
	printf("%d\n", l+r+1);
	
	return 0;
}
