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

const int N = 33333,M = 66;
int n,m,v[M][3],w[M][3],dp[N];

int main(int argc,char** argv)
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i++)
    {
        int v1,p1,q;
        scanf("%d%d%d",&v1,&p1,&q);
        if(!q)
        {
            v[i][0] = v1;
            w[i][0] = p1;
        }
        else if(!v[q][1])
        {
            v[q][1] = v1;
            w[q][1] = p1;
        }
        else
        {
            v[q][2] = v1;
            w[q][2] = p1;
        }
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = n;j >= 0;j--)
        {
            if(j >= v[i][0]) dp[j] = max(dp[j],dp[j - v[i][0]] + v[i][0] * w[i][0]);
            if(j >= v[i][0] + v[i][1]) dp[j] = max(dp[j],dp[j - v[i][0] - v[i][1]] + v[i][0] * w[i][0] + v[i][1] * w[i][1]);
            if(j >= v[i][0] + v[i][2]) dp[j] = max(dp[j],dp[j - v[i][0] - v[i][2]] + v[i][0] * w[i][0] + v[i][2] * w[i][2]);
            if(j >= v[i][0] + v[i][1] + v[i][2]) dp[j] = max(dp[j],dp[j - v[i][0] - v[i][1] - v[i][2]] + v[i][0] * w[i][0] + v[i][1] * w[i][1] + v[i][2] * w[i][2]);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}