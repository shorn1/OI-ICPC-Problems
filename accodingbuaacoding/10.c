#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define lol long long
#define mo 100007LL

lol n,t = 2LL;
lol a,b;
lol r[111111] = {1LL,2LL,3LL};

void init()
{
    while(1)
    {
        r[t] = (r[t - 1] + r[t - 2]) % mo;
        if(r[t] == r[1])
        {
            --t;
            break;
        }
        ++t;
    }
}

int main(int argc,char** argv)
{
    init();
    while(scanf("%lld",&n) > 0)
    {
        printf("%lld\n",r[n % t ? n % t : t]);
    }
    return 0;
}