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

int n,m;

struct Std
{
    int k,s;
    bool operator < (const Std &x) const
    {
        return s == x.s ? k < x.k : s > x.s;
    }
}a[23333];

int main(int argc,char** argv)
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d%d",&a[i].k,&a[i].s);
    }
    sort(a+1,a+1+n);
    int t = static_cast<int>(1.5 * static_cast<double>(m));
    while(a[t].s == a[t+1].s) ++t;
    printf("%d %d\n",a[t].s,t);
    for(int i = 1;i <= t;i++)
    {
        printf("%d %d\n",a[i].k,a[i].s);
    }
    return 0;
}