// A. Three Pairwise Maximums

#include <iostream>
#include <algorithm>


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	
	while (t--){
		
		int x, y, z;
		scanf("%d %d %d\n", &x, &y, &z);
		
		int arr[3] = {x, y, z};
		std::sort(arr, arr+3);
		
		// Editorial - https://codeforces.com/blog/entry/80257
		if (arr[1] != arr[2]) printf("NO\n");
		else {
			printf("YES\n");
			printf("%d %d %d\n", arr[0], arr[0], arr[2]);
		}
	}
	
	return 0;
}
