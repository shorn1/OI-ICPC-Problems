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

int n,k,a[23333],m;
lol res;

int main(int argc,char** argv)
{
    scanf("%d%d",&n,&k);
    while(k > 0)
    {
        a[m++] = k & 1;
        k >>= 1;
    }
    for(int i = m - 1;i >= 0;i--)
    {
        res += a[i] * pow(n,i);
    }
    printf("%lld\n",res);
    return 0;
}