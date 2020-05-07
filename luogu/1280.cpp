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

int n,k,cnt = 1,t[23333],dp[23333];

struct tsk
{
    int st,ed;
    bool operator < (const tsk& a) const
    {
        return st > a.st;
    }
}tk[23333];

int main(int argc,char** argv)
{
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= k;i++)
    {
        scanf("%d%d",&tk[i].st,&tk[i].ed);
        t[tk[i].st]++;
    }
    sort(tk + 1,tk + 1 + k);
    for(int i = n;i >= 1;i--)
    {
        if(!t[i]) dp[i] = dp[i + 1] + 1;
        else
        {
            for(int j = 1;j <= t[i];j++)
            {
                dp[i] = max(dp[i],dp[i + tk[cnt].ed]);
                ++cnt;
            }
        }
    }
    printf("%d\n",dp[1]);
    return 0;
}