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

int n,a,oda,eva,odb,evb;

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a);
        if(a & 1) oda++;
        else eva++;
    }
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a);
        if(a & 1) odb++;
        else evb++;
    }
    printf("%d",min(oda,evb) + min(odb,eva));
    return 0;
}