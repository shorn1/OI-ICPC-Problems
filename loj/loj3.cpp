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

int T;
char s[23333];

int main(int argc,char** argv)
{
#ifndef shorn
    freopen("copycat.in","r",stdin);
    freopen("copycat.out","w",stdout);
#else

#endif
    scanf("%d",&T);
    for(int i = 1;i <= T;i++)
    {
        scanf("%s",s);
        printf("%s\n",s);
    }
    return 0;
}