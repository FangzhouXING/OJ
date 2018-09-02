#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);
    int total1 = 0, total2 = 0;
    for(int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        total1 += tmp;
    }
    for(int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        total2 += tmp;
    }
    if(total1 >= total2)
        printf("Yes");
    else
        printf("No");
    return 0;
}