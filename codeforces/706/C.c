#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

char *strrev1(char *str)
{
    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

int main() {
    long long int n;
    scanf("%I64d", &n);
    long long int *costs = malloc(sizeof(long long int)*n);
    for(int i = 0; i < n; i++)
        scanf("%I64d", costs+i);
    long long int *NC = malloc(sizeof(long long int)*n);
    long long int *RC = malloc(sizeof(long long int)*n);
    NC[0] = 0;
    RC[0] = costs[0];

    bool *NP = malloc(sizeof(bool)*n);
    bool *RP = malloc(sizeof(bool)*n);
    NP[0] = RP[0] = true;

    char *buf0 = malloc(sizeof(char)*100000);
    char *buf1 = malloc(sizeof(char)*100000);

    scanf("%s", buf0);
    for(int i = 1; i < n; i++) {
        scanf("%s", buf1);
        NC[i] = RC[i] = 92233720368547758;
        NP[i] = RP[i] = false;
        if(strcmp(buf0, buf1) <= 0 && NP[i-1] && NC[i] > NC[i-1] ) {
            NC[i] = NC[i-1];
            NP[i] = true;
        }
        strrev1(buf0);
        if(strcmp(buf0, buf1) <= 0 && RP[i-1] && NC[i] > RC[i-1] ) {
            NC[i] = RC[i-1];
            NP[i] = true;
        }
        strrev1(buf1);
        if(strcmp(buf0, buf1) <= 0 && RP[i-1] && RC[i] > RC[i-1] + costs[i]) {
            RC[i] = RC[i-1] + costs[i];
            RP[i] = true;
        }
        strrev1(buf0);
        if(strcmp(buf0, buf1) <= 0 && NP[i-1] && RC[i] > NC[i-1] + costs[i]) {
            RC[i] = NC[i-1] + costs[i];
            RP[i] = true;
        }
        strrev1(buf1);

        if(!(RP[i] || NP[i])) {
            printf("-1");
            return 0;
        }

        char *tmp = buf0;
        buf0 = buf1;
        buf1 = tmp;
    }

    long long int minCost = NC[n-1] < RC[n-1] ? NC[n-1] : RC[n-1];
    printf("%I64d", minCost);
    return 0;
}