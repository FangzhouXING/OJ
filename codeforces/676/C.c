#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    char *str = malloc(sizeof(char)*(n+1));
    scanf("%s", str);
    
    int maxLen = 0;
    int curLen = 0;
    int lastReplaceIndex = -1;
    char ctr = 'a'; //character to replace 
    int kc = k;
    for(int i = 0; i < n; i++) {
        if(kc > 0) {
            curLen = i - lastReplaceIndex;
            if(str[i] == ctr)
                kc--;
        } else {
            if(str[i] != ctr) {
                curLen = i - lastReplaceIndex;
            } else {
                lastReplaceIndex++;
                while(str[lastReplaceIndex] != ctr)
                    lastReplaceIndex++;
                curLen = i - lastReplaceIndex;
            }
        }
        if(maxLen < curLen)
            maxLen = curLen;
    }
    curLen = 0;
    lastReplaceIndex = -1;
    ctr = 'b'; //character to replace 
    kc = k;
    for(int i = 0; i < n; i++) {
        if(kc > 0) {
            curLen = i - lastReplaceIndex;
            if(str[i] == ctr)
                kc--;
        } else {
            if(str[i] != ctr) {
                curLen = i - lastReplaceIndex;
            } else {
                lastReplaceIndex++;
                while(str[lastReplaceIndex] != ctr)
                    lastReplaceIndex++;
                curLen = i - lastReplaceIndex;
            }
        }
        if(maxLen < curLen)
            maxLen = curLen;
    }
    
    printf("%d", maxLen);
    return 0;
}