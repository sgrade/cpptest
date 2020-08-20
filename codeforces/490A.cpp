// A. Team Olympiad

#include <iostream>
#include <algorithm>		// std::min
#include <vector>

using namespace std;


int main (){
	
	int n;
	scanf("%d\n", &n);
	
	int tmp;
	vector<int> a1, a2, a3;
	for (int i=1; i<n+1; ++i){
		scanf("%d", &tmp);
		if (tmp==1) a1.push_back(i);
		if (tmp==2) a2.push_back(i);
		if (tmp==3) a3.push_back(i);
	}
	
	int w = min({a1.size(), a2.size(), a3.size()});
	printf("%d\n", w);
	
	for (int i=0; i<w; ++i){
		printf("%d %d %d\n", a1[i], a2[i], a3[i]);
	}
	
	return 0;
}
