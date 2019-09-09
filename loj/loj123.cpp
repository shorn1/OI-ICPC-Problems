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

const int M = 666666;

int n,m;
int fa[M],size[M];
lol res;

struct Edge
{
    int u,v,w;
    Edge(int _u = 0,int _v = 0,int _w = 1000000007){u = _u;v = _v;w = _w;}
    const bool operator < (const Edge &a) const
    {
        return this->w < a.w;
    }
}e[M];

int getfa(int x)
{
	if(fa[x]==x) return x;
	return fa[x] = getfa(fa[x]);
}

void merge(int x,int y)
{
	int s1 = size[getfa(x)];
	int s2 = size[getfa(y)];
	if(s1>s2)
	{
		fa[getfa(y)] = getfa(x);
		size[getfa(x)] = s1+s2;
	}
	else
	{
		fa[getfa(x)]= getfa(y);
		size[getfa(y)] = s1+s2;
	}
}

void init()
{
    n = in();
    m = in();
    for(int i = 1;i <= m;i++)
    {
        e[i].u = in();
        e[i].v = in();
        e[i].w = in();
        
    }
    for(int i = 1;i <= n;i++)
    {
        fa[i] = i;
        size[i] = 1;
    }
}

int main()
{
	init();
    sort(e + 1,e + m + 1);
    int k = 0;
    for(int i = 1;i <= m && k < n;i++)
    {
        int uu = getfa(e[i].u);
        int vv = getfa(e[i].v);
        if(uu != vv)
        {
            res += static_cast<lol>(e[i].w);
            merge(uu,vv);
            k++;
        }
    }
    printf("%lld",res);
	return 0;
}
