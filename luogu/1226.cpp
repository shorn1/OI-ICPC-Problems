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

lol b,p,k;

lol fpow(lol x,lol y)
{
    if(!y) return 1LL;
    if(y == 1) return x % k;
    lol t = x % k * x % k;
    if(y & 1) return fpow(t % k,y >> 1) % k * x % k;
    else return fpow(t % k,y >> 1) % k;
}

int main(int argc,char** argv)
{
    cin >> b >> p >> k;
    printf("%lld^%lld mod %lld=%lld",b,p,k,fpow(b,p) % k);
    return 0;
}