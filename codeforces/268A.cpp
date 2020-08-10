//A. Games

#include <iostream>
#include <vector>

int main(){
	
	int n;
	scanf("%d", &n);
	
	// input
	std::vector<std::pair<int, int>> v;
	int h, g;
	for (int i=0; i<n; ++i){
		scanf("%d %d", &h, &g);
		//std::cout << h << g << std::endl;
		v.push_back(std::make_pair(h, g));
	}
	
	// calculation
	int numOfGames=0, homeColor=0;
	for(auto& it: v){
		// 	std::cout << it.first << " " << it.second << std::endl;
		homeColor = it.first;
		for(auto& it2: v){
			// skipping same team
			if(it==it2) continue;
			if(homeColor == it2.second) ++numOfGames;
		}
	}
	
	printf("%d", numOfGames);
	
	return 0;
}
	
	
	
