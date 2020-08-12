// A. I_love_%username%

#include <iostream>
#include <set>

using namespace std;

int main(){
	
	int n;
	scanf("%d", &n);
	
	set<int> st;
	int cur, output=0;
	
	// first read. 
	// Without it rbegin() in the loop crashes the program
	cin >> cur;
	st.insert(cur);
	
	while(n-1){
		
		// read current input
		cin >> cur;
		
		// check if current is less than the min or more than the max
		if( (cur < *st.begin()) || (cur > *st.rbegin()) ) ++output;
		
		st.insert(cur);
		
		--n;
	}
	
	printf("%d", output);
	
	return 0;
}
