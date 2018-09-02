#include <stdio.h>

int diff(int a, int b)
{
    return a > b ? a-b:b-a;
}
int main()
{
    int n, h, a, b, k;
    scanf("%d%d%d%d%d", &n, &h, &a, &b, &k);
    for(int i = 0; i < k; i++) {
        int ta,fa, tb,fb;
        scanf("%d%d%d%d", &ta, &fa, &tb, &fb);
        int total = diff(ta, tb);
        total += diff(fa,fb);
        if(fa < a)
            total += a-fa;
        if(fa > b)
            total += fa-b;
        if(fb < a)
            total += a-fb;
        if(fb > b)
            total += fb-b;
        printf("%d\n", total);
    }
}