// A. Amusing Joke

#include <iostream>
#include <map>

using namespace std;

int main(){
	
	string g, h, s;
	getline(cin, g);
	getline(cin, h);
	getline(cin, s);
	
	map<char, int> gh;
	string tmp = g+h;
	for(unsigned i=0; i<tmp.size(); ++i){
		++gh[tmp[i]];
	}
	
	bool no=0;
	for(unsigned j=0; j<s.size(); ++j){
		--gh[s[j]];
	}
	
	for(auto it: gh){
		// cout << it.first << ": " << it.second << endl;
		if(it.second!=0){
			no=1;
			break;
		}
	}
	
	if(no) cout << "NO";
	else cout << "YES";
	
	return 0;
}
