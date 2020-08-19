// A. Remove Smallest

#include <iostream>
#include <algorithm>

using namespace std;


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while(t--){
			
		int n;
		scanf("%d\n", &n);
		//cout << "n: " << n << endl;
		
		if (n==1) {
			printf("YES\n");
			// avoid scanning the array;
			cin.ignore(50, '\n');
			continue;
		}
		
		int arr[n];
		for (int i=0; i<n; ++i){
			scanf("%d", &arr[i]);
		}
		
		sort(arr, arr+n);
		
		for (int i=1; i<n; ++i) {
			if((arr[i] - arr[i-1]) > 1) {
				printf("NO\n");
				break;
			}
			if (i==n-1) printf("YES\n");
		}
	}
	
	return 0;
}
