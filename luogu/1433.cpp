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
double x[M],y[M],d[M][M];
double res = 2333333333333333333.0;

void dfs(int k,int t,double l)
{
    if(l > res) return;
    if(k >= n)
    {
        res = min(res,l);
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            dfs(k + 1,i,l + d[t][i]);
            vis[i] = 0;
        }
    }
    
}

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%lf%lf",&x[i],&y[i]);
    for(int i = 0;i < n;i++)
    {
        for(int j = i + 1;j <= n;j++)
            d[i][j] = d[j][i] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
    }
    dfs(0,0,0.0);
    printf("%.2f",res);
    return 0;
}