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

struct fastin
{
	static const int bs = 10000;
	char buf[bs];
	int p;
	fastin() : p(bs) {}
	void flush()
	{
		fread(buf, 1, bs, stdin);
		p = 0;
	}
	char gc()
	{
		if (p >= bs)
			flush();
		return buf[p++];
	}
	lol operator()()
	{
		lol ans = 0LL;
		char ch = gc();
		while (ch < '0' || ch > '9')
			ch = gc();
		while (ch >= '0' && ch <= '9')
		{
			ans *= 10LL;
			ans += ch - '0';
			ch = gc();
		}
		return ans;
	}
} in;

lol res,t;

int main(int argc,char** argv)
{
#ifdef shorn
    freopen("loj7-1.in","r",stdin);
#else

#endif
    res = in();
    for(int i = 1;i < 3000000;i++)
    {
        res ^= in();
    }
    printf("%lld",res);
    return 0;
}