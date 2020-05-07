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

int n;
char s[23333];

void build(int l,int r)
{
    if(r > l)
    {
        build(l,(l + r) >> 1);
        build(((l + r) >> 1) + 1,r);
    }
    int bb = 0,ii = 0;
    for(int i = l;i <= r;i++)
    {
        if(s[i] == '0') bb = 1;
        else if(s[i] == '1') ii = 1;
    }
    if(bb && ii) putchar('F');
    else if(bb) putchar('B');
    else putchar('I');
}

int main(int argc,char** argv)
{
    scanf("%d%s",&n,s);
    build(0,(1 << n) - 1);
    return 0;
}