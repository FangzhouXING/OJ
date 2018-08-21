#include <stdio.h>

int cnt[101];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        cnt[num]++;
    }
    int max = 0;
    for(int i = 0; i < 101; i++) {
        if (max < cnt[i])
            max = cnt[i];
    }
    printf("%d", max);
    return 0;
}