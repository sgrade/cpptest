// A. Tram

#include <iostream>

int main(){

	int n, a, b, currentCapacity=0, maxCapacity=0;
	scanf("%d", &n);
	
	// std::cout << n << std::endl;
	
	for (int i=1; i<n+1; ++i){
		scanf("%d %d", &a, &b);
		// std::cout << a << " " << b << std::endl;
		
		currentCapacity += b - a;
		
		if (currentCapacity > maxCapacity) maxCapacity = currentCapacity;
		// std::cout << "currentCapacity: " << currentCapacity << std::endl;
	}
	
	printf("%d", maxCapacity);

return 0;
}
