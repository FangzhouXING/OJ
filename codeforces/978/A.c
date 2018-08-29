#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() 
{
    int n;
    scanf("%d", &n);
    int *nums = malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++) {
        scanf("%d", nums+i);
    }
    int first = n;
    for(int i = n-1; i >= 0; i--) {
        int curIdx = i;
        bool dup = false;
        for(int j = i+1; j < n; j++) {
            if (nums[j] == nums[i]) {
                dup = true;
                break;
            }
        }
        if(!dup) {
            nums[--first] = nums[i];
        }
    }
    printf("%d\n", n-first);
    for(int i = first; i < n; i++) 
        printf("%d ", nums[i]);
    return 0;
}