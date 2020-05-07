#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define lol long long

lol n,m;

int main(int argc,char** argv)
{
    scanf("%lld%lld",&n,&m);
    printf("%lld",n % m);
    return 0;
}