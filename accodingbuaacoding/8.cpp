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

int t;
lol a,b,c,d,e,f,g,h;

int main(int argc,char** argv)
{
    scanf("%d",&t);
    for(int i = 1;i <= t;i++)
    {
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f,&g,&h);
        printf("%lld\n",(lol)(((__int128)(a)*c)/b+((__int128)(d)*g*h)/(e*f)));
    }
    
    return 0;
}