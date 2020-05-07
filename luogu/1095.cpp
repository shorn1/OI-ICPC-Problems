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

const int M = 333333;
int m,s,t,dp[M],res,flg;

int main(int argc,char** argv)
{
    scanf("%d%d%d",&m,&s,&t);
    for(int i = 1;i <= t;i++)
    {
        if(m >= 10)
        {
            dp[i] = dp[i - 1] + 60;
            m -= 10;
        }
        else
        {
            dp[i] = dp[i - 1];
            m += 4;
        }
    }
    for(int i = 1;i <= t;i++)
    {
        dp[i] = max(dp[i],dp[i - 1] + 17);
        if(dp[i] >= s && !flg)
        {
            res = i;
            flg = 1;
        }
    }
    if(dp[t] >= s) printf("Yes\n%d\n",res);
    else printf("No\n%d\n",dp[t]);
    return 0;
}