// A. Key races

#include <stdio.h>


int main(){

    int s, v1, v2, t1, t2;
    scanf("%d %d %d %d %d\n", &s, &v1, &v2, &t1, &t2);

    t1 = s*v1 + 2*t1;
    t2 = s*v2 + 2*t2;

    if (t1<t2) printf("First\n");
    else if (t2 < t1) printf("Second\n");
    else printf("Friendship\n");

    return 0;
}