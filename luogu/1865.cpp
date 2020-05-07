#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define ns namespace
#define lol long long
using ns std;

int prime[1100000],pn[1100000], primesize,m,n;
int isprime[1100000];
void getlist(int listsize)
{
    isprime[1] = 0;
    for (int i = 2; i <= listsize; i++) isprime[i] = 1;
    for (int i = 2; i <= listsize; i++)
    {
        if (isprime[i])
            prime[++primesize] = i;
        for (int j = 1; j <= primesize && i * prime[j] <= listsize; j++)
        {
            isprime[i * prime[j]] = 0;
            if (i % prime[j] == 0)
                break;
        }
    }
    for (int i = 2; i <= listsize; i++)
    {
        pn[i] = pn[i - 1] + isprime[i];
    }
}

int main(int argc, char **argv)
{
    scanf("%d%d",&n,&m);
    getlist(m);
    for(int i = 1;i <= n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(l < 1 || l > m || r < 1 || r > m) puts("Crossing the line");
        else printf("%d\n",pn[r] - pn[l - 1]);
    }
    return 0;
}