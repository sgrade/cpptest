// B. Honest Coach

#include <iostream>
#include <algorithm>

using namespace std;


int main (){
	
	int t;
	scanf("%d\n", &t);
	
	while(t--){
		
		int n, tmp;
		scanf("%d\n", &n);
				
		int s[n];
		for(int i=0; i<n; ++i){
			scanf("%d", &tmp);
			s[i] = tmp;
		}
		
		sort(s, s+n);
		
		if (n==2){
			printf("%d\n", s[1]-s[0]);
			continue;
		}
		
		int m = s[1] - s[0];
		for (int i=2; i<n; ++i){
			if (s[i]-s[i-1] < m) m = s[i]-s[i-1];
		}
		
		printf("%d\n", m);

	}
	
	return 0;
}
