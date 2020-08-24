// A. Black Square

#include <iostream>
#include <string>

using namespace std;


int main(){
	
	int a1, a2, a3, a4;
	scanf("%d %d %d %d\n", &a1, &a2, &a3, &a4);
	
	int arr[4] = {a1, a2, a3, a4};
	
	string s;
	getline (cin, s);
	
	int cal = 0;
	for (unsigned i=0; i < s.size(); ++i){
		
		// In ASCII numbers start from 48
		// Additional "-1" because arr indexes start from 0
		int aIndex = (int)s[i] - 48 - 1;
		cal += arr [ aIndex ];
	}
	
	printf("%d\n", cal);
	
	return 0;
}
