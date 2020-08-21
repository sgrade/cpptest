// A. Maximum in Table

#include <iostream>

using namespace std;


int main(){
	
	int n;
	scanf("%d\n", &n);
	
	int arr[n][n];
	
	if (n == 1) {
		printf("%d\n", 1);
		exit(0);
	}
	
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			
			if (i==0 || j==0) arr[i][j] = 1;
			else arr[i][j] = arr[i-1][j] + arr[i][j-1];
			
		}
	}
	
	printf("%d\n", arr[n-1][n-1]);
	
	return 0;
}
