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
	int operator()()
	{
		int ans = 0;
		char ch = gc();
		while (ch < '0' || ch > '9')
			ch = gc();
		while (ch >= '0' && ch <= '9')
		{
			ans *= 10;
			ans += ch - '0';
			ch = gc();
		}
		return ans;
	}
} in;

const int M = 233333;
int n;
int a[M];
lol res = 0LL;

int main(int argc,char** argv)
{
    n = in();
    for(int i = 0;i < n;i++)
    {
        a[i] = in();
    }
    res = a[0];
    for(int i = 1;i < n;i++)
    {
        res = a[i] > a[i-1] ? (res + (a[i] - a[i - 1])) : res;
    }
    printf("%lld\n",res);
    return 0;
}