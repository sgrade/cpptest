// B. CopyCopyCopyCopyCopy

#include <stdio.h>
#include <vector>
#include <set>

using namespace std;


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while (t--){
		
		int n;
		scanf("%d\n", &n);
		
		int tmp;
		vector<int> v;
		for (int i=0; i<n; ++i){
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		
		set<int> st(v.begin(), v.end());
			
		printf("%d\n", (int)st.size());
	}
	
	return 0;
}
