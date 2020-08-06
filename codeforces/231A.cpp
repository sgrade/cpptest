// A. Team

#include <iostream>


int main(){
	
	int n, output=0;
	bool v, p, t, result;
	
	scanf("%d", &n);
	
	for (int i=0; i<n; i++){
		
		std::cin >> v >> p >> t;
		
		result = v ? (p||t) : (p&&t);
		output += (result ? 1 : 0);
		
	}
	
	printf("%d\n", output);
	
	return 0;
}
