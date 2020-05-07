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

int n,k,res;

void dfs(int l,int s,int m)
{
    if(m >= k)
    {
        if(s == n) ++res;
        return;
    }
    for(int i = l;s + i * (k - m) <= n;i++)
        dfs(i,s + i,m + 1);
}

int main(int argc,char** argv)
{
    scanf("%d%d",&n,&k);
    dfs(1,0,0);
    printf("%d\n",res);
    return 0;
}