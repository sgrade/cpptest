// A. Restoring Three Numbers

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	int x1, x2, x3, x4;
	scanf("%d %d %d %d", &x1, &x2, &x3, &x4);
	
	vector<int> v = {x1, x2, x3, x4};
	sort(v.begin(), v.end());
	
	int a, b, c;
	a = v[3] - v[0];
	b = v[3] - v[1];
	c = v[3] - v[2];
	
	printf("%d %d %d", a, b, c);
	
	return 0;
}
