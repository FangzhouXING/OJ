#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int abs(int a) {
    return a < 0 ? -a : a;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *diffs = malloc(sizeof(int)*n);
    int totalDiff = 0;
    for(int i = 0; i < n; i++) {
        int left,right;
        scanf("%d%d", &left, &right);
        int d = left - right;
        diffs[i] = d;
        totalDiff += d;
    }
    int maxAbs = abs(totalDiff);
    int maxIndex = -1;
    for(int i = 0; i < n; i++) {
        int newdiff = abs(totalDiff-2*diffs[i]);
        if(newdiff > maxAbs) {
            maxIndex = i;
            maxAbs = newdiff;
        }
    }
    printf("%d", maxIndex+1);
    return 0;
}