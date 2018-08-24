#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *stair = malloc(sizeof(int)*n);
    int stairCnt = -1;
    for(int i = 0; i < n; i++) {
        int step;
        scanf("%d", &step);
        if(step == 1) {
            stairCnt++;
        }
        stair[stairCnt] = step;
    }
    stairCnt++;
    printf("%d\n", stairCnt);
    for(int i = 0; i < stairCnt; i++) {
        printf("%d ", stair[i]);
    }
    return 0;
}