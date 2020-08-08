// A. George and Accommodation

#include <iostream>

int main(){
	
	int n, p, q, rooms=0;
	scanf("%d", &n);
	
	for (int i=0; i<n; ++i){
		std::cin >> p >> q;
		if (q-p>1) rooms++;
	}
	
	printf("%d", rooms);
	
	return 0;
}
