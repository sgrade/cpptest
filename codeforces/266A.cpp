// A. Stones on the Table

#include <iostream>

int main(){

	int n, s_size, counter=0;
	std::string s;
	
	scanf("%d", &n);
	std::cin >> s;
	s_size = s.size();
	
	if (s_size > 1){
		
		for (int i=1; i<s_size; ++i){
			if (s[i] == s[i-1]){
				counter +=1;
			}
		}
	}
		
	printf("%d", counter);

return 0;
}
