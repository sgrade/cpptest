// A. Nearest Interesting Number

#include <iostream>
#include <string>

using namespace std;


int main(){
	
	int a;
	cin >> a;
	
	while (true){
		
		string aStr = to_string(a);
		
		int sum = 0;
		for (auto i: aStr){
			sum += i;
		}
		
		if (sum%4==0) break;
		else {
			a++;
		}
	}
	
	cout << a << endl;
	
	return 0;
}
