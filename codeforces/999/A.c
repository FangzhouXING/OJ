#include <stdio.h>

int main() 
{
    int n, k;
    scanf("%d%d", &n, &k);
    int left = 0, right = 0;
    while(n > 0) {
        int difficulty;
        scanf("%d", &difficulty);
        n--;
        if(difficulty > k)
            break;
        left++;
    }
    while(n > 0) {
        int difficulty;
        scanf("%d", &difficulty);
        n--;
        if(difficulty > k)
            right = 0;
        else 
            right++;
    }
    printf("%d", left+right);
    return 0;
}