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

const lol mo = 1000007;

int n;
lol x,a,y;
const int M = 5111111;
lol po[M] = {1LL};

void init()
{
	for(int i = 1;i <= n;i++)
	{
		po[i] = po[i - 1] * x % mo;
	}
}

int main(int argc, char **argv)
{
	while(scanf("%d",&n) > 0)
	{
		scanf("%lld",&x);
		lol res = 0LL;
		init();
		for(int i = 0;i <= n;i++)
		{
			scanf("%lld",&y);
			res += y * po[i] % mo;
		}
		printf("%lld\n",res % mo);
	}
	return 0;
}