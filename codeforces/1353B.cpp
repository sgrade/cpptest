// B. Two Arrays And Swaps

#include <iostream>
#include <vector>
#include <algorithm>    // std:: sort, std::iter_swap
#include <numeric>		// std::accumulate

using namespace std;


int main(){
	
	int t, n, k;
	
	scanf("%d\n", &t);
	
	
	while (t){
		
		scanf("%d %d\n", &n, &k);
		//cout << "========" << endl;
		//cout << "n,k: " << n << "," << k << endl;
		
		vector<int> a, b;
		int tmp=0;
		
		for (int i=0; i<n; ++i){
			scanf("%d", &tmp);
			a.push_back(tmp);
		}
		sort(a.begin(), a.end());
		
		for (int j=0; j<n; ++j){
			scanf("%d", &tmp);
			b.push_back(tmp);
		}
		sort(b.begin(), b.end());
		
		/*
		for(auto it: a) cout << it << " ";
		cout << endl;
		for(auto it: b) cout << it << " ";
		cout << endl;
		*/
		
		
		for (int m=0; m<k; ++m){
			if (a[m] < b[n-m-1]){
				iter_swap(a.begin()+m, b.end()-m-1);
			}
			else break;
			
		}
		
		/*
		cout << "-" << endl;
		for(auto it: a) cout << it << " ";
		cout << endl;
		for(auto it: b) cout << it << " ";
		cout << endl;
		*/
		
		cout << accumulate(a.begin(), a.end(), 0) << endl;
			
		--t;
	}
	
	return 0;
}
