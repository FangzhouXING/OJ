#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long int nums[5000];
long long int sums[5000];

long long int dp[5000][5000];
bool e[5000][5000];
long long int maxSum(long long int n, long long int m, long long int k)
{
    if(k <= 0) {
        return  0;
    }
    if(n+1 < m) {
        return 0;
    }
    if(n+1 == m)
        return sums[n];
    if(!e[n-m][k-1]) {
        dp[n-m][k-1] = maxSum(n-m, m, k-1);
        e[n-m][k-1] = true;
    }
    long long int max = (sums[n] - sums[n-m]) + dp[n-m][k-1]; //take n;
    if(!e[n-1][k]) {
        dp[n-1][k] = maxSum(n-1, m, k);
        e[n-1][k] = true;
    }
    long long int putN = dp[n-1][k];
    if(max < putN)
        max = putN;
    e[n][k] = true;
    dp[n][k] = max;
    return max;
}

int main() 
{
    long long int n, m, k;
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    for(int i = 0; i < n; i++)
        scanf("%I64d", nums+i);
    
    sums[0] = nums[0];
    for(int i = 1; i < n; i++)
        sums[i] = sums[i-1] + nums[i];
    
    long long int max = maxSum(n, m, k);
    printf("%I64d", max);
    return 0;
}