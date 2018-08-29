#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() 
{
    int n, m;
    scanf("%d%d", &n, &m);
    bool *covered = malloc(sizeof(bool)*(m+1));
    for(int i = 0; i < m+1; i++)
        covered[i] = false;

    for(int i = 0; i < n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        for(int j = l; j <= r; j++) {
            covered[j] = true;
        }
    }

    int cnt = 0;
    for(int i = 1; i < m+1; i++) {
        if(!covered[i])
            cnt++;
    }
    printf("%d\n", cnt);
    for(int i = 1; i < m+1; i++) {
        if(!covered[i])
            printf("%d ", i);
    }
    return 0;
}