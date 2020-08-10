// A. Hit the Lottery

#include <iostream>

using namespace std;

int main(){
	
	int n;
	scanf("%d", &n);
	
	//1 , 5, 10, 20, 100
	
	int count=0;
	if(n>=100) {
		count += n/100;
		//cout << "100: " << count << endl;
		n%=100;
	}
	if(n>=20){
		count+= n/20;
		//cout << "20: " << count << endl;
		n%=20;
	}
	if(n>=10){
		count+= n/10;
		//cout << "10: " << count << endl;
		n%=10;
	}
	if (n>=5){
		count+= n/5;
		//cout << "5: " << count << endl;
		n%=5;
	}
	count+=n;
	
	printf("%d", count);
	
	return 0;
}
