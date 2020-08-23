// A. Collecting Coins

#include <iostream>
#include <algorithm>


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while (t--){

		int a, b, c, n;
		scanf("%d %d %d %d\n", &a, &b, &c, &n);
		//printf("%d %d %d %d:\t", a, b, c, n);
		
		int arr[3] = {a, b, c};
		std::sort(arr, arr+3);
		
		int coinsToEqualize = arr[2]-arr[1] + arr[2]-arr[0];
		
		if (n == coinsToEqualize){
			printf("YES\n");
		}
		else if ((n - coinsToEqualize > 2) && \
			(n-coinsToEqualize) % 3 == 0) printf("YES\n");

		else printf("NO\n");
	}
	
	return 0;
}
