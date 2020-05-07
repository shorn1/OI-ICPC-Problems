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

const int M = 133;
int m,n,a[M][M],dp[M][M],res;

int main(int argc,char** argv)
{
    scanf("%d%d",&m,&n);
    for(int i = 1;i <= m;i++)
        for(int j = 1;j <= n;j++) 
            scanf("%d",&a[i][j]);
    for(int i = 1;i <= m;i++)
        for(int j = 1;j <= n;j++) 
            {
                if(a[i][j]) dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
                res = max(res,dp[i][j]);
            }
    printf("%d",res);
    return 0;
}