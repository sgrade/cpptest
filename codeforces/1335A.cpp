// A. Candies and Two Sisters

#include <iostream>

using namespace std;


int main(){
	
	int n;
	scanf("%d", &n);
	
	int inp;
	for(int i=0; i<n; ++i){
		scanf("%d", &inp);
		
		if(inp%2==0) cout << inp/2 - 1 << endl;
		else cout << inp/2 << endl;	
	}
	
	return 0;
}
