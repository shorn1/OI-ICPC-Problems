#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

#define ns namespace
#define lol long long
using ns std;

const int M = 233;
int m,n,a[M][M],dp[M][M];

int main(int argc,char** argv)
{
    scanf("%d%d",&m,&n);
    for(int i = 1;i <= m;i++)
        for(int j = 1;j <= n;j++) 
            scanf("%d",&a[i][j]);
    for(int i = 1;i <= m;i++)
        for(int j = 1;j <= n;j++) 
            dp[i][j] = max(dp[i - 1][j - 1],max(dp[i - 1][j],dp[i - 1][j + 1])) + a[i][j];
    printf("%d\n",max(dp[m][n / 2],max(dp[m][n / 2 + 1],dp[m][n / 2 + 2])));
    return 0;
}