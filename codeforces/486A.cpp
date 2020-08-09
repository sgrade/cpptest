// A. Calculating Function

#include <iostream>

int main(){
	
	long long int n;
	std::cin >> n;
	
	long long int sum=0;
	
	if (n==1) printf("-1");
	else if (n==2) printf("1");
	else {
		long long int i=1;
		//std::cout << i << " " << sum << std::endl;
		for (i=1; i<n; i++){
			sum -= i;
			//std::cout << sum << std::endl;
			i++;
			sum += i;
			//std::cout << sum << std::endl;
		}
		if (i==n){
			sum -=i;
			//std::cout << sum << std::endl;
		}
		std::cout << sum;
	}
	
	return 0;
}
