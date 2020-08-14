// A. Police Recruits

#include <iostream>

using namespace std;

int main(){
	
	int n;
	scanf("%d", &n);
	
	int officers=0, crimes=0;
	
	int tmp;
	for (int i=0; i<n; ++i){
		scanf("%d", &tmp);
		
		if (tmp<0){
			if (officers < 1) crimes += 1;
			else officers -= 1;
		}
		else officers += tmp;
		
		// printf("Officers: %d, Crimes: %d\n", officers, crimes);
	}
	
	printf ("%d", crimes);
	
	return 0;
}
