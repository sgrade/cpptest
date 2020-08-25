// A. Combination Lock

#include <iostream>
#include <string>
#include <algorithm>


using namespace std;


int main(){
	
	int n;
	scanf("%d\n", &n);
	
	string state, comb;
	getline(cin, state);
	getline(cin, comb);
	
	int s, c, moves=0;
	for (int i=0; i<n; ++i){
		// "-48" to convert from ASCII string to number
		s = (int)state[i] - 48;
		c = (int)comb[i] - 48;
		
		if (s==c) continue;
		else moves += min({abs(s-c), s+10-c, 10-s+c});
	}
	
	printf("%d", moves);
	
	return 0;
}
