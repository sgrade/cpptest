// B. Fix You

#include <stdio.h>

using namespace std;


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while (t--){
	
		int n, m;
		scanf("%d %d\n", &n, &m);
		
		char tmp;	
		int cellsToChange = 0;
		
		for (int i=0; i<n; ++i){
			for (int j=0; j<m; ++j){
				scanf("%c", &tmp);
				
				if (i!=n-1 && j==m-1 && tmp!='D')
					cellsToChange ++;
				else if (i==n-1 && j!=m-1 && tmp!='R')
					cellsToChange ++;
								
			}
			scanf("\n");
		}
		
		printf("%d\n", cellsToChange);
	}
	
	return 0;
}
