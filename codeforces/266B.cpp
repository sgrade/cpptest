// B. Queue at the School

#include <iostream>
#include <cstring>

int main(){
	
	int n, t;
	std::cin >> n >> t;
	
	std::string s;
	std::cin >> s;
	//std::cout << s << std::endl;
	
	if(n==1){
		std::cout << s;
		exit(0);
	}
	
	for (int i=0; i<t; ++i){
		//std::cout << "New cycle" << std::endl;
		for (int j=0; j<n; ++j){
			//std::cout << j << j+1<< s[j] << s[j+1] << std::endl;
			if (s[j] == 'B' && s[j+1] == 'G'){
				//std::cout << "Swapping " << std::endl;
				s[j]='G';
				s[j+1]='B';
				// To shift the windwow in two positions
				// One time j is incremented here
				// and another time in for(++j)
				j+=1;
			}
		}
		//std::cout << s << std::endl;
	}
	
	std::cout << s << std::endl;
	
	return 0;
}
