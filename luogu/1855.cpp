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
int n,m,t,a[M],b[M],dp[M][M],res;

int main(int argc,char** argv)
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i = 1;i <= n;i++) scanf("%d%d",&a[i],&b[i]);
    for(int k = 1;k <= n;k++)
    {
        for(int i = m;i >= a[k];i--)
        {
            for(int j = t;j >= b[k];j--)
            {
                dp[i][j] = max(dp[i][j],dp[i - a[k]][j - b[k]] + 1);
                res = max(res,dp[i][j]);
            }
        }
    }
    printf("%d\n",res);
    return 0;
}