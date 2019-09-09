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

int prime[11000000], primesize;
bool isprime[11000000];
void getlist(int listsize)
{
    memset(isprime, 1, sizeof(isprime));
    isprime[1] = false;
    for (int i = 2; i <= listsize; i++)
    {
        if (isprime[i])
            prime[++primesize] = i;
        for (int j = 1; j <= primesize && i * prime[j] <= listsize; j++)
        {
            isprime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int n,m;

int main(int argc, char **argv)
{
    cin >> n >> m;
    getlist(n);
    for(int i = 1;i <= m;i++)
    {
        int a;
        scanf("%d",&a);
        if(isprime[a]) puts("Yes");
        else puts("No");
    }
    return 0;
}