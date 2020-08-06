// A. Next Round

#include <iostream>

int main(){
	
	// inputs
	int n, k;
	scanf("%d %d", &n, &k);
	
	// to iterate through input
	int i=0;
	
	// score - k-th place finisher's score
	// tmp - score of the next finishers 
	// (to check if they have same score
	int score=0, tmp=0;

	// i = 1 because we already scanned the first score
	for (; i<k; ++i){
		scanf("%d", &score);
		// std::cout << "Score, Counter: " << score << ", " << i << std::endl;
		
		// check if there is no positive score
		if (!score) {
			// we can return i (not i-1), because i starts from 0
			printf("%d", i);
			return 0;
		}
	}
	
	for (; i<n; ++i){
		scanf("%d", &tmp);
		if (tmp < score){
			break;
		}
		// std::cout << "Score, Counter: " << score << ", " << i << std::endl;

	}
	
	printf("%d", i);
	
	return 0;
}
