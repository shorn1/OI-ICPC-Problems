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

const int M = 555;
const lol mo = 1000000007LL;
int n,p,m;
lol a[M][M],b[M][M],c[M][M];

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
        lol sg = 1;
		char ch = gc();
        if(ch == '-') sg = -1;
		while (ch < '0' || ch > '9')
		{
            ch = gc();
            if(ch == '-') sg = -1;
        }
		while (ch >= '0' && ch <= '9')
		{
			ans *= 10LL;
			ans += ch - '0';
			ch = gc();
		}
		return ans * sg;
	}
} in;

int main(int argc,char** argv)
{
    n = in(); p = in();m = in();
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= p;j++)
            a[i][j] = in();
    for(int i = 1;i <= p;i++)
        for(int j = 1;j <= m;j++)
            b[i][j] = in();
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            for(int k = 1;k <= p;k++)
                c[i][j] += a[i][k] * b[k][j] % mo;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)      
            printf("%lld%c",(c[i][j] + 233 * mo) % mo,j == m ? '\n' : ' ');  
    return 0;
}