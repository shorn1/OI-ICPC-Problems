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
int n;
int t[M],dp1[M],dp2[M],res;

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&t[i]);
    }
    for(int i = 1;i <= n;i++)
    {
        dp1[i] = dp2[i] = 1;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j < i;j++)  if(t[i] > t[j]) dp1[i] = max(dp1[i],dp1[j] + 1);
    }
    for(int i = n;i >= 1;i--)
    {
        for(int j = n ;j > i;j--) if(t[i] > t[j]) dp2[i] = max(dp2[i],dp2[j] + 1);
    }
    for(int i = 1;i <= n;i++) 
    {
        res = max(res,dp1[i] + dp2[i] - 1);
    }
    printf("%d\n",n - res);
    return 0;
}