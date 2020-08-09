// A. Insomnia cure

#include <iostream>

void check(const int a, const int d, int arr[]){
	for (int i=a-1; i<d; i+=a){
		arr[i]=1;
	}
}

int main(){
	
	int k, l, m, n, d;
	scanf("%d", &k);
	scanf("%d", &l);
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &d);
	
	int damaged[d];
	for (int i=0; i<d; ++i) damaged[i]=0;
	
	check(k, d, damaged);
	check(l, d, damaged);
	check(m, d, damaged);
	check(n, d, damaged);
	
	int output=0;
	for(auto it: damaged) output += it;
	
	printf("%d", output);
		
	return 0;
}
