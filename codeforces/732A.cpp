// A. Buy a Shovel

#include <iostream>

using namespace std;

int main(){
	
	int k, r;
	scanf("%d %d", &k, &r);
	
	int shovels=0, tmp=k;
	for (int i=0; i<10; ++i){
		if (tmp%10==0) {
			break;
		}
		else if ((tmp%10-r)==0){
			break;
		}
		else tmp+=k;
	}
	shovels = tmp/k;
	
	printf("%d", shovels);	
	
	return 0;
}
