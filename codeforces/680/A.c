#include <stdio.h>

int main() {
    int nums[5];
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        scanf("%d", nums+i);
        sum += nums[i];
    }
    int minSum = sum;
    for(int i = 0; i < 5; i++) {
        int cnt = 1;
        for(int j = i+1; j < 5; j++) {
            if(nums[j] == nums[i])
                cnt++;
        }
        if(cnt < 2)
            continue;
        if(cnt > 3)
            cnt = 3;
        if(minSum > sum - cnt*nums[i])
            minSum = sum - cnt*nums[i];
    }
    printf("%d", minSum);
    return 0;
}