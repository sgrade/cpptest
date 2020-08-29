// B. File Name

#include <iostream>
#include <string>

using namespace std;


int main(){
	
	int n;
	scanf("%d\n", &n);
	
	string s;
	cin >> s;
	
	int charsToRemove=0, tmp=0;
	for (int i=0; i<n; ++i){
		if (s[i] == 'x') tmp += 1;
		else tmp = 0;
		if (tmp > 2) charsToRemove += 1;
	}
	
	printf("%d\n", charsToRemove);
	
	return 0;
}
