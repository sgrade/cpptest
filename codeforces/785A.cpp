//A. Anton and Polyhedrons

#include <iostream>
#include <map>

int main(){
	
	int n;
	scanf("%d", &n);
	
	std::map<std::string, int> mp;
	mp["Tetrahedron"]=4;
	mp["Cube"]=6;
	mp["Octahedron"]=8;
	mp["Dodecahedron"]=12;
	mp["Icosahedron"]=20;
	
	std::string tmp;
	int output=0;
	for (int i=0; i<n; ++i){
		std::cin >> tmp;
		output += mp[tmp];
	}
	
	printf("%d", output);
	
	return 0;
}
