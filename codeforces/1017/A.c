#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int rank = 1;
    int a,b,c,d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int sum = a + b + c + d;
    for(int i = 1; i < n; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int sum2 = a + b + c + d;
        if (sum2 > sum)
            rank++;
    }
    printf("%d", rank);
    return 0;
}