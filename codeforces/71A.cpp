// A. Way Too Long Words

#include <iostream>
#include <string>

using namespace std;

int main(){
		
	int n;
	cin >> n;
	
	string s;
	for (int i=0; i<n; i++){
		
		cin >> s;
		
		if (s.size() > 10){
			cout << s.front();
			cout << (s.substr(1, s.size()-2)).size();
			cout << s.back() << endl;
		}
		else{
			cout << s << endl;
		}
	}
return 0;

}
