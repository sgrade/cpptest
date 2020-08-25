// A. Bus to Udayland

#include <iostream>
#include <string>

using namespace std;


int main(){
	
	int n;
	scanf("%d\n", &n);
	
	string arr[n];
	
	string tmp;
	string flag = "NO";
	for(int i=0; i<n; ++i){
		
		getline(cin, tmp);
				
		if (flag == "NO" && tmp[0]=='O' && tmp[1]=='O') {
			tmp[0]='+';
			tmp[1]='+';
			flag = "YES";
		}
		
		if (flag == "NO" && tmp[3]=='O' && tmp[4]=='O') {
			tmp[3]='+';
			tmp[4]='+';
			flag = "YES";
		}
		
		arr[i] = tmp;
		
	}
	
	cout << flag << endl;
	
	if (flag == "YES") {
		for (auto it: arr) cout << it << endl;
	}
	
	return 0;
}
