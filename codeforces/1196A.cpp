// A. Three Piles of Candies

#include <iostream>

using namespace std;


int main(){
	
	int q;
	scanf("%d\n", &q);
	
	while (q--){
	
		long long p1, p2, p3;
		cin >> p1 >> p2 >> p3;
		
		long long output = p1 + p2 + p3;
		if (output%2 == 0) cout << output / 2 << endl;
		else cout << (output-1) / 2 << endl;
	
}
	
	return 0;
}
