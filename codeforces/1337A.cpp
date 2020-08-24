// A. Ichihime and Triangle

#include <iostream>
#include <random>


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while (t--){
		
		int a, b, c, d;
		scanf("%d %d %d %d\n", &a, &b, &c, &d);
		
		// !!! In triangle sum of any two sides is more than third side
		// This is why the below doesn't work
		/*
		std::random_device rd;  //Will be used to obtain a seed for the random number engine
		std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
		
		std::uniform_int_distribution<> distrib1(a, b);
		std::uniform_int_distribution<> distrib2(b, c);
		std::uniform_int_distribution<> distrib3(c, d);
		
		printf("%d %d %d\n", \
			distrib1(gen), distrib2(gen), distrib3(gen));
		*/
		
		// From editorial:
		// many possible solutions, but b, c, c is always a solution
		
		// b, b, c doesn't work because b+b can be < c;
		printf("%d %d %d\n", b, c, c);
		
	}
	
	return 0;
}
