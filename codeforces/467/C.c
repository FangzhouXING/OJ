#include <stdio.h>
#include <stdlib.h>

int nums[5000];
int sums[5000];

int maxSum(int n, int m, int k)
{
    if(k <= 0)
        return  0;
    if(n+1 < m)
        return 0;
    if(n+1 == m)
        return sums[n];
    int max = (sums[n] - sums[n-m]) + maxSum(n-m, m, k-1); //take n;
    int putN = maxSum(n-1,m,k);
    if(max < putN)
        max = putN;
    return max;
}

int main() 
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", nums+i);
    
    sums[0] = nums[0];
    for(int i = 1; i < n; i++)
        sums[i] = sums[i-1] + nums[i];
    
    int max = maxSum(n, m, k);
    printf("%d", max);
    return 0;
}