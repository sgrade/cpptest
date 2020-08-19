// A. Minimal Square

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	
	int t;
	scanf("%d\n", &t);
	
	int a, b;
	
	while(t--) {
		scanf("%d %d\n", &a, &b);
		
		// making sure a always smaller
		if (b<a) swap(b, a);
		//cout << "a, b: " << a << ", " << b << endl;
		
		if (a==b) {
			printf("%d\n", (a+b)*(a+b));
			continue;
		}
		
		if (b/a < 2) {
			while(b%a !=0) b+=1;
		}
				
		printf("%d\n", b*b);		
		
	}

	return 0;
}
