// A. Beautiful Matrix

#include <iostream>
#include <cmath>

int main(){
	
	// i - number of row
	// j - number of column
	// element - matrix element
	int i=1, j, element=0;
	
	// traversing the rows
	while (i<6){
		
		// std::cout << "i: " << i << std::endl;
		
		// need to reset j for each row, 
		// otherwise only first row will be checked for all j
		j = 1;
		
		// traversing the columns
		while (j<6){
			//std::cout << "j: " << j << std::endl;
			scanf("%d", &element);
			if (element==1) break;
			++j;
		}
		if (element==1) break;
		++i;
	}
	
	// std::cout << i << ", " << j << std::endl;
	
	// number of moves
	// Note: abs - absolute value
	printf("%d", abs(i-3) + abs(j-3));
	
return 0;
}
