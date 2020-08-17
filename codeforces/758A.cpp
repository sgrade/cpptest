// A. Holiday Of Equality

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main (){
	
	int n, s=0;
	scanf("%d", &n);
	
	vector<int> v;
	int tmp;
	while (n){
		scanf("%d", &tmp);
		v.push_back(tmp);
		--n;
	}
	
	sort(v.begin(), v.end());
	
	int max = v.back();
	for (unsigned i=0; i<v.size()-1; ++i){
		s+= max-v[i];
	}
	
	printf("%d", s);
	
	return 0;
}
