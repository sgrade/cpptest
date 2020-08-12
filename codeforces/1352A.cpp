//A. Sum of Round Numbers

#include <iostream>
#include <vector>

int main(){
	
	int t;
	scanf("%d", &t);
	
	int n;
	while(t>0){
		
		scanf("%d", &n);
		//std::cout << "t, n: " << t << ", " << n << std::endl;
			
		if (n==10 || n==100 || n==1000 || n==10000){
			printf("1\n%d\n", n);
			--t;
			continue;
		}
		
		int thousands = n-n%1000;
		int hundreds = n%1000-n%100;
		int tens = n%100-n%10;
		int ones = n%10;
		
		std::vector<int> v;
		if (thousands) v.push_back(thousands);
		if (hundreds) v.push_back(hundreds);
		if (tens) v.push_back(tens);
		if (ones) v.push_back(ones);
		
		std::cout << v.size() << std::endl;
		for (unsigned i=0; i<v.size(); ++i){
			std::cout << v[i];
			if (i<v.size()) printf(" ");
		}
		std::cout << std::endl;
		
		--t;
	}
	
	return 0;
}
