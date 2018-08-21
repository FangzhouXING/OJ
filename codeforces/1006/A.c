#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if(num % 2 == 0)
            printf("%d ", num-1);
        else 
            printf("%d ", num);
    }
    return 0;
}