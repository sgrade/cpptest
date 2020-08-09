// A. I Wanna Be the Guy

#include <iostream>
#include <sstream>

int main(){
	
	int n;
	scanf("%d", &n);
	// to skip the endline symbol after n
	std::cin.ignore();
	
	// array for the game levels
	int levels[n];
	for (int i=0; i<n; ++i) levels[i]=0;
	
	// parsing the players' levels
	int xLevels, yLevels, tmp;
	
	scanf("%d", &xLevels);
	while (xLevels){
		scanf("%d", &tmp);
		levels[tmp-1] = 1;
		xLevels--;
	}
	
	scanf("%d", &yLevels);
	while (yLevels){
		scanf("%d", &tmp);
		levels[tmp-1] = 1;
		yLevels--;
	}
	
	int totalLevels=0;
	for (auto it: levels){
		totalLevels += it;
	}
	
	std::string output;
	output = totalLevels==n ?\
	printf("I become the guy.") :\
	printf("Oh, my keyboard!");
	
	return 0;
}
