// A. Choosing Teams

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, k, y;
	scanf("%d %d", &n, &k);
	
	vector<int> v;
	while(n){
		scanf("%d", &y);
		v.push_back(y);
		--n;
	}
	
	sort(v.begin(), v.end());
	
	int teams=0;
	for (int i=0; i<k; ++i){

		auto it = find(v.begin(), v.end(), 5);
		v.erase(it, v.end());
		
		//for(auto itr: v) cout << itr;
		//cout << endl;
		
		teams=v.size()/3;
		//cout << teams << endl;
		
		if (teams>0){
			for (unsigned j=0; j<(v.size()-v.size()%3); ++j){
				v[j]+=1;
			}
		}
		else break;

	}
	
	printf("%d", teams);
	
	return 0;
}
