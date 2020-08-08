// A. Beautiful Year

#include <iostream>

int main(){
	
	int y;
	scanf("%d", &y);
	
	int i=0, j=0, found=0, duplicate;
	
	while (!found){
		duplicate=0;
		//std::cout << std::endl;
		//std::cout << "found: " << found << std::endl;
		if (found==1) break;
		y+=1;
		std::string s = std::to_string(y);
		//std::cout << s << std::endl;
		
		for (i=0; i<4; ++i){
			if (duplicate) break;
			//std::cout << "i: " << i << std::endl;
			for (j=0; j<4; ++j) {
				//std::cout << "j: " << j << std::endl;
				//std::cout << s[i] << s[j] << " ";
				if (i==j) {
					if (i==3 && j==3){
						//std::cout << "FOUND!!!" << std::endl;
						found=1;
						break;
					}
					//std::cout << "Don't compare with itself" << std::endl;
					continue;
				}
				else if (s[i]!=s[j]){
					//std::cout << "!=" << std::endl;
					continue;
				}
				else {
					//std::cout << "Duplicate!" << std::endl;
					duplicate=1;
				}
			}
			//std::cout << "Reached the end of the for loop" << std::endl;
			//std::cout << "i: " << i << " j: " << j << std::endl;
		}
	}
	
	std::cout << y;
	
	return 0;
}
