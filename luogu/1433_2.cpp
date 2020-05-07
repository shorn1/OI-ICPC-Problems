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

const int M = 23;
int n,vis[M];
double x[M],y[M],d[M][M],dp[M][33333];
double res = 2333333333333333333.0;

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%lf%lf",&x[i],&y[i]);
    for(int i = 0;i < n;i++)
    {
        for(int j = i + 1;j <= n;j++)
            d[i][j] = d[j][i] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
    }
    for(int i = 0;i < M;i++)
        for(int k = 0;k <= (1 << n) - 1;k++) 
            dp[i][k] = res;
    for(int k = 1;k <= (1 << n) - 1;k++) 
        for(int i = 1;i <= n;i++)
        {
            if(k == (1 << (i - 1)))
            {
                dp[i][k] = 0;
            }
            else if(k &  (1 << (i - 1)))
            {
                for(int j = 1;j <= n;j++)
                {
                    if((k & (1 << (j - 1)) && i != j))
                    {
                        dp[i][k] = min(dp[i][k],dp[j][k - (1 << (i - 1))] + d[i][j]);
                    }
                }
            }
        }
    for(int i = 1;i <= n;i++)
    {
        res = min(res,dp[i][(1 << n) - 1] + d[0][i]);
    }
    printf("%.2f",res);
    return 0;
}