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

const int M = 5055;
int n,a[M],dp[M],r[M],r1,r2;

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
    for(int i = 1;i <= n;i++) dp[i] = 1;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j < i;j++) 
        {
            if(a[i] < a[j]) dp[i] = max(dp[i],dp[j] + 1);
        }
        r1 = max(r1,dp[i]);
        for(int j = 1;j < i;j++) 
        {
            if(a[i] == a[j] && dp[i] == dp[j]) r[j] = 0;
            else if(dp[i] == dp[j] + 1 && a[i] < a[j]) r[i] += r[j]; 
        }
        r[i] = max(1,r[i]);
    }
    for(int i = 1;i <= n;i++)
    {
        if(dp[i] == r1) r2 += r[i];
    }
    printf("%d %d\n",r1,r2);
    return 0;
}