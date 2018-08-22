#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool cExist[256];
int latest[100000][256];
int main() {
    int n;
    scanf("%d", &n);
    char *str = malloc(sizeof(char) * (n+1));
    scanf("%s", str);
    int begin = -1;
    int end = -1;
    cExist[str[0]] = true;
    for(int i = 0; i < 256; i++)
        latest[0][i] = INT_MAX;
    latest[0][str[0]] = 0;
    for(int i = 1; i < n; i++) {
        char c = str[i];
        cExist[c] = true;
        for(int j = 0; j < 256; j++) {
            latest[i][j] = latest[i-1][j]; 
        }
        latest[i][c] = i;
    }

    int minRange = n;
    for(int i = 0; i < n; i++) {
        int min = i;
        bool allExist = true;
        for(int j = 0; j < 256; j++) {
            if(!cExist[j])
                continue;
            if(latest[i][j] == INT_MAX) {
                allExist = false;
                break;
            }
            if (min > latest[i][j]) {
                min = latest[i][j];
            }
        }

        if (allExist && i-min+1 < minRange)
            minRange = i-min+1;
    }
    printf("%d", minRange);
    return 0;
}