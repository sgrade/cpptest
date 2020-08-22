// B. Restore the Permutation by Merger

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while (t--){
	
		int n;
		scanf("%d\n", &n);
		//printf("n: %d\n", n);
		
		vector<int> v;
		string s;
		int tmp;
		
		getline(cin, s);
		stringstream ss(s);
		
		//printf("tmp:");
		while (ss >> tmp){
			//printf(" %d", tmp);
			
			auto exist = find(begin(v), end(v), tmp);
			if (exist == end(v)) v.push_back(tmp);
		}
		//cout << endl;
		
		auto it=begin(v);
		for (; it < end(v)-1; it++) printf("%d ", *it);
		printf("%d\n", *it);
	
	}
	
	return 0;
}
