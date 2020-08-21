// B. Restore the Permutation by Merger

#include <stdio.h>
#include <vector>
#include <algorithm>


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while (t--){
	
		int n, tmp;
		scanf("%d\n", &n);
		
		std::vector<int> v;
		while (v.size() < (unsigned)n){
			scanf("%d", &tmp);
			// printf("tmp: %d\n", tmp);
			auto exist = find(begin(v), end(v), tmp);
			if (exist == end(v)) v.push_back(tmp);
		}
		
		auto it=begin(v);
		for (; it < end(v)-1; it++) printf("%d ", *it);
		printf("%d\n", *it);
	
	}
	
	return 0;
}
