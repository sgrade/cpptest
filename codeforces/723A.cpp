// A. The New Year: Meeting Friends

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

	int x1, x2, x3;
	scanf("%d %d %d", &x1, &x2, &x3);
	
	int arr[] = {x1, x2, x3};
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	sort(arr, arr+arrSize);
	
	int distance = (arr[2]-arr[1])+ (arr[1]-arr[0]);
	
	printf("%d", distance);
	
    return 0;
}
