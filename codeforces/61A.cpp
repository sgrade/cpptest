// A. Ultra-Fast Mathematician

#include <iostream>

int main(){
	
	std::string n1, n2;
	getline(std::cin, n1);
	getline(std::cin, n2);
	
	for (unsigned i=0; i<n1.size(); ++i){
		std::cout << ((n1[i]) ^ (n2[i]));
	}
	
	return 0;
}
