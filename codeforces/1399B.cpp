// B. Gifts Fixing

#include <iostream>
#include <algorithm>

using namespace std;


int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		
		int a[n], b[n];
		for (int i=0; i<n; ++i) cin >> a[i];
		for (int i=0; i<n; ++i) cin >> b[i];
		
		if (n==1){
			if(a[0]>b[0]) cout << a[0]-b[0];
			else cout << b[0]-a[0];
			continue;
		}
		
		sort(a, a+n);
		sort(b, b+n);
		
		auto lastA = unique(begin(a), end(a));
		auto lastB = unique(begin(b), end(b));
		
	}
	
	return 0;
}
