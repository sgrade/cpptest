//A. Anton and Letters

#include <iostream>
#include <set>

int main(){
	
	std::string s;
	
	getline(std::cin, s);
	s.pop_back();
	s.erase(s.begin(), s.begin()+1);
	
	while(true){
		size_t found = s.find(", ");
		if(found != std::string::npos){
			s.erase(found, 2);
		}
		else break;
	}
	
	std::set<char> st;
	for(unsigned i=0; i<s.size(); ++i){
		st.insert(s[i]);
	}
	
	int letters = st.size();
	
	printf("%d", letters);
	
	return 0;
}
