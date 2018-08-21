#include <stdio.h>

int canBuy[100001];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        canBuy[tmp]++;
    }
    int sum = 0;
    for(int i = 0; i < 100001; i++) {
        sum += canBuy[i];
        canBuy[i] = sum;
    }
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        int coin;
        scanf("%d", &coin);
        if(coin > 100000)
            printf("%d\n", canBuy[100000]);
        else
            printf("%d\n", canBuy[coin]);
    }
    return 0;
}