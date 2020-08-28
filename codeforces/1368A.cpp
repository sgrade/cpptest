// A. C+=

#include <iostream>
#include <algorithm>

using namespace std;


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while(t--){
		
		long long a, b, n;
		cin >> a >> b >> n;
		
		int operations = 0;
		while (a <= n) {
			if (a>b) swap (a, b);
			a+=b;
			operations += 1;
		}
		
		printf("%d\n", operations);
	}
	
	return 0;
}
