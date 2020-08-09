// A. Arrival of the General

#include <iostream>
#include <vector>
#include <bits/stdc++.h>	//max_element, min_element

int main(){
	
	int n;
	scanf("%d", &n);
	
	std::vector<int> v;
	int tmp;
	for (int i=0; i<n; ++i){
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	
	int max = *max_element(v.begin(), v.end());
	auto maxIt = find(v.begin(), v.end(), max);
	int maxIndex=0;
	// There is no need to check if maxIt exist, but I do it
	if(maxIt!=v.end()) maxIndex=distance(v.begin(), maxIt);
	//std::cout << "maxIndex: " << maxIndex << std::endl;
	
	int min = *min_element(v.begin(), v.end());
	// searching in REVERSE direction
	// if there are duplicates, we choose the closest to the end
	auto minIt = find(v.rbegin(), v.rend(), min);
	int minIndex=0;
	// There is no need to check if maxIt exist, but I do it
	if(minIt!=v.rend()) minIndex=distance(v.rbegin(), minIt);
	//std::cout << "minIndex: " << minIndex << std::endl;
	
	int swaps=0;
	// to move max to the front
	swaps += maxIndex;
	//std::cout << swaps << std::endl;
	// to move min to the back
	swaps += minIndex;
	//std::cout << swaps << std::endl;
	
	// when we swap max and min, we move 2 elements in one go,
	// thus we should take it into account in total number of swaps
	// Note: remember, that minIndex is reverse, so
	// we need to convert it back for comparison
	int minIndexForward = distance(v.begin(), minIt.base()-1);
	//std::cout << "minIt.base(): " << *minIt.base() << std::endl;
	//std::cout << maxIndex << " " << minIndexForward << std::endl;
	if (maxIndex > minIndexForward) swaps-=1;
	
	std::cout << swaps;
	
	return 0;
}
