// A. Short Substrings

#include <iostream>

using namespace std;

int main(){
	
	int t;
	scanf("%d\n", &t);
	
	string tmp;
	for (int i=0; i<t; ++i){
		getline(cin, tmp);
		string output;
		output = tmp.substr(0, 2);
		if (tmp.size() > 2){
			for (unsigned j=2; j<tmp.size(); j+=2){
				output += tmp[j+1];
			}
		}
		cout << output << endl;
	}
	
	return 0;
}
