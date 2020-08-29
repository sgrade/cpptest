// A. Cards

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    int n;
    scanf("%d\n", &n);

    string s;
    cin >> s;

    int numOfZero = count(s.begin(), s.end(), 'z');
    int numOfOne = (n - numOfZero*4) / 3;
    
	for (int i = 0; i < numOfOne; ++i) printf("1 ");
	for (int j = 0; j < numOfZero; ++j) printf("0 ");

    return 0;
}
