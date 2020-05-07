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

int n,m,e;
struct stu
{
    int num,c,t;
    bool operator < (const stu& a) const
    {
        if(t != a.t) return t > a.t;
        if(c != a.c) return c > a.c;
        return num < a.num;
    }
}s[2333];

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d%d%d",&s[i].c,&m,&e);
        s[i].t = s[i].c + m + e;
        s[i].num = i;
    }
    sort(s + 1,s + 1 + n);
    for(int i = 1;i <= 5;i++)
    {
        printf("%d %d\n",s[i].num,s[i].t);
    }
    return 0;
}