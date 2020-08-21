// A. Magical Sticks

#include <iostream>

using namespace std;


int main(){
	
	int t;
	cin >> t;
	
	while (t--){
		
		int n;
		scanf("%d\n", &n);
		
		if (n==1) cout << 1 << endl;
		else if (n%2 == 0) cout << n/2 << endl;
		else cout << n/2+1 << endl;
		
	}
	
	return 0;
}
