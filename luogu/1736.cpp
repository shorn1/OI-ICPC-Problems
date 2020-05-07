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

const int M = 2555;
int n,m,a[M][M],dp[M][M],p1[M][M],p2[M][M],res;

int main(int argc,char** argv)
{
    while(scanf("%d%d",&n,&m) > 0)
    {
        res = 0;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                scanf("%d",&a[i][j]);
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
            {
                if(a[i][j]) dp[i][j] = min(dp[i-1][j-1],min(p1[i][j-1],p2[i-1][j])) + 1;
                else
                {
                    p1[i][j] = p1[i][j-1] + 1;
                    p2[i][j] = p2[i-1][j] + 1;
                }
                res = max(res,dp[i][j]);
            }
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                p1[i][j] = dp[i][j] = 0;
        for(int i = 1;i <= n;i++)
            for(int j = m;j >= 1;j--)
            {
                if(a[i][j]) dp[i][j] = min(dp[i-1][j+1],min(p1[i][j+1],p2[i-1][j])) + 1;
                else
                {
                    p1[i][j] = p1[i][j+1] + 1;
                    p2[i][j] = p2[i-1][j] + 1;
                }
                res = max(res,dp[i][j]);
            }
        printf("%d\n",res);
    }
    return 0;
}