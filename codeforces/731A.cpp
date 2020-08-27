// A. Night at the Museum

#include <iostream>
#include <algorithm>

using namespace std;


int main(){
	
	string s;
	cin >> s;
	
	// ASCII: a = 97; z = 122
	// for (auto it: s) cout << (int)it << endl;
	
	int r = 0, cur, prev = 1;
	for (unsigned i=0; i<s.size(); ++i){
		
		cur = (int)s[i] - 96;
		
		//cout << cur << " " << abs(cur-prev) << " " << 26 - abs(cur-prev) << endl;
		r += min( abs(cur-prev), 26 - abs(cur-prev));
		
		prev = cur;
		
	}
	
	cout << r << endl;
	
	return 0;
}
