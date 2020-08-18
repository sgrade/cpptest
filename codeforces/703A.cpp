// A. Mishka and Game

#include <iostream>

using namespace std;


int main(){
	
	int n;
	scanf("%d\n", &n);
	
	int m, c, wins=0;
	for (int i=0; i<n; ++i){
		scanf ("%d %d", &m, &c);
		if (m>c) ++wins;
		else if (m<c) --wins;
	}
	
	if (wins > 0) printf("Mishka");
	else if (wins < 0) printf("Chris");
	else printf("Friendship is magic!^^");
	
	return 0;
}
