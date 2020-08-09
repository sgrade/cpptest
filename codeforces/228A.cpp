// A. Is your horseshoe on the other hoof?

#include <iostream>
#include <vector>
#include <set>

int main(){
	
	std::vector<int> v;
	
	int tmp;
	while (std::cin >> tmp) v.push_back(tmp);
	
	std::set<int> st(v.begin(), v.end());
	
	int output = v.size() - st.size();
	printf("%d", output);
	
	return 0;
}
