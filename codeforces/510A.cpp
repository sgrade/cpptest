//A. Fox And Snake

#include <iostream>
#include <iomanip> 		//setw, setfill
using namespace std;

int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);
	
	while(n>0){
		
		cout << setw(m) << setfill ('#') << '#' << endl;
		--n;
		if (n>0) cout << setw(m) << setfill ('.') << '#' << endl;
		--n;
		if (n>0) cout << setw(m) << setfill ('#') << '#' << endl;
		--n;
		if (n>0) cout << '#' << setw(m-1) << setfill ('.') << '.' << endl;
		--n;
	}
	
	return 0;
}
