// A. Phoenix and Balance

#include <iostream>
#include <math.h>       /* pow */
#include <vector>
#include <numeric>		// std::accumulate

using namespace std;


int main(){
	
	int t, n;
	scanf("%d\n", &t);
	
	while (t){
		
		scanf("%d\n", &n);
		
		int a=0, b=0;
		vector<int> v;
		
		for(int i=1; i<n+1; ++i){
			v.push_back(pow(2, i));
		}
		
		a = accumulate(v.begin(), v.begin()+n/2-1, 0);
		a += v[v.size()-1];
		
		b = accumulate(v.begin()+n/2-1, v.end()-1, 0);
		
		// cout << "a, b: " << a << " " << b << endl;
		cout << abs(a - b) << endl;
		
		
		--t;
	}
	
	return 0;
}
