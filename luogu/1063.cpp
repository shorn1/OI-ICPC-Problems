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

const int N = 233;
int n,res,w[N],dp[N][N];

int dfs(int l,int r)
{
    if(dp[l][r]) return dp[l][r];
    if(l + 1 == r) return dp[l][r] = w[l] * w[r] * w[r + 1];
    for(int i = l;i < r;i++)
        dp[l][r] = max(dp[l][r],dfs(l,i) + dfs(i + 1,r) + w[l] * w[i + 1] * w[r + 1]);
    return dp[l][r];
}

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&w[i]);
        w[i + n] = w[i];
    }
    for(int i = 1;i <= n;i++) res = max(res,dfs(i,i + n - 1));
    printf("%d\n",res);
    return 0;
}