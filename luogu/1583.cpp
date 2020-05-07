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

int n,k,e[233];

struct pe
{
    int w,num;
    bool operator < (const pe& a) const
    {
        if(w != a.w) return w > a.w;
        return num < a.num;
    }
}p[23333];

int main(int argc,char** argv)
{
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= 10;i++) scanf("%d",&e[i]);
    for(int i = 1;i <= n;i++) 
    {
        scanf("%d",&p[i].w);
        p[i].num = i;
    }
    sort(p + 1,p + 1 + n);
    for(int i = 1;i <= n;i++)
    {
        p[i].w += e[(i - 1) % 10 + 1];
    }
    sort(p + 1,p + 1 + n);
    for(int i = 1;i <= k;i++) printf("%d ",p[i].num);
    return 0;
}