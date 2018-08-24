#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int table[26][26]; // [a][b]: 0 means doesn't matter, [a][b] < 0 means a comes before b.
char names[100][101];

bool buildTable(int n)
{
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < j; i++) {
            //names[i] < names[j]
            int k = 0;
            while(names[i][k] != '\0' && names[j][k] != '\0') {
                int ci = names[i][k] - 'a'; 
                int cj = names[j][k] - 'a';
                if(ci - cj == 0) {
                    k++;
                    continue;
                }
                //now ci should come before cj

                //printf("(%c %c, %d) ", names[i][k], names[j][k], ci - cj);

                if(table[ci][cj] > 0 || table[cj][ci] < 0)
                    return false;
                table[ci][cj] = -1;
                table[cj][ci] = 1;
                break;
            }
            if(names[j][k] == '\0') {
                return false;
            }
        }
    }
    return true;
}

int compare(const void*a, const void*b) {
    int ca = *(char*)a - 'a';
    int cb = *(char*)b - 'a';
    return table[ca][cb];
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%s", names[i]);
    if(!buildTable(n)) {
        printf("Impossible");
    }
    char letters[] = "qwertyuiopasdfghjklzxcvbnm\0";
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            if(table[i][j] == 0)
                table[i][j] = 10;
        }
    }
    qsort(letters, 26, sizeof(char), compare);

    printf("%s", letters);
    return 0;
}