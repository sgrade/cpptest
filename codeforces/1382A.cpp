// A. Common Subsequence

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while (t--){
		
		int n, m;
		scanf ("%d %d\n", &n, &m);
		
		int tmp;
		set<int> a;
		for (int i=0; i<n; ++i){
			scanf("%d", &tmp);
			a.insert(tmp);
		}
		// for (auto it: a) cout << it;
		// cout << endl;
		
		set<int> b;
		for (int i=0; i<m; ++i){
			scanf("%d", &tmp);
			b.insert(tmp);
		}
		// for (auto it: b) cout << it;
		// cout << endl;
		
		bool found = 0;
		for (auto it: a){
			// cout << "Match? " << it << endl;
			auto match = find(b.begin(), b.end(), it);
			if (match != b.end()) {
				cout << "YES" << endl;
				cout << 1 << " " << it << endl;
				found = 1;
				break;
			}
		}
		if (!found) cout << "NO" << endl;
		// cout << "======" << endl;
	}
	
	return 0;
}
