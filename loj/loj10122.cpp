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

const lol M = 1000111;
lol tree[4*M],a[M],n,m;
using namespace std;

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
		int sgn = 1;
		if(ch == '-') sgn = -1;
		while (ch < '0' || ch > '9')
		{
			ch = gc();
			if(ch == '-') sgn = -1;
		}
		while (ch >= '0' && ch <= '9')
		{
			ans *= 10LL;
			ans += ch - '0';
			ch = gc();
		}
		return ans * sgn;
	}
} in;

void build(lol n,lol b,lol e)
{
	if(b==e)
	{
		tree[n] = a[b];
		return;
	}
	lol mid = (b+e) >> 1;
	build(2 * n,b,mid);
	build(2 * n + 1,mid+1,e);
	tree[n] = max(tree[2 * n],tree[2 * n + 1]);
}

lol query(lol n,lol b,lol e,lol l,lol r)
{
	lol p1,p2;
	//p1 = p2 = -998244353000000LL;
	if(l>e || r<b)
	{
		return -998244353000000LL;
	}
	if(b >= l && e <= r)
	{
		return tree[n];
	}
	lol mid = (b+e) >> 1;
	p1 = query(2 * n,b,mid,l,r);
	p2 = query(2 * n + 1,mid+1,e,l,r);
	return max(p1,p2);
}

int main()
{
	//scanf("%d",&n);
    n = in();
	for(lol i=1;i<=n;i++)
	{
		//scanf("%d",&a[i]);
        a[i] = in();
	}
	m = in();
	build(1,1,n);
    for(lol i=1;i<=m;i++)
    {
        lol x = in();
        lol y = in();
        printf("%lld\n",query(1,1,n,x,y));
    }
	return 0;
}

