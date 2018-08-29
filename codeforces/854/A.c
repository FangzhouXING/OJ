#include <stdio.h>

int gcd(int a, int b) {
    if(a < b)
        return gcd(b, a);
    if(b == 0)
        return a;
    return gcd(b, a%b);
}
int main()
{
    int n;
    scanf("%d", &n);
    if(n % 2 == 0) {
        int a = n/2, b = n/2;
        while(gcd(a, b) != 1)
            a--, b++;
        printf("%d %d",a, b);
    } else {
        printf("%d %d", (n-1)/2, (n+1)/2);
    }
    return 0;
}