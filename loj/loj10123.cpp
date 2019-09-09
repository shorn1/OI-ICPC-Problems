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
const lol inf = 21474836470000LL;
lol ma[4*M],a[M],n,m,mi[4 * M];
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
		lol sgn = 1;
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
		ma[n] = a[b];
		mi[n] = a[b];
		return;
	}
	lol mid = (b+e) >> 1;
	build(2 * n,b,mid);
	build(2 * n + 1,mid+1,e);
	ma[n] = max(ma[2 * n],ma[2 * n + 1]);
	mi[n] = min(mi[2 * n],mi[2 * n + 1]);
}

lol queryma(lol n,lol b,lol e,lol l,lol r)
{
	lol p1,p2;
	if(l>e || r<b)
	{
		return -inf;
	}
	if(b >=l && e<=r)
	{
		return ma[n];
	}
	lol mid = (b+e) >> 1;
	p1 = queryma(2 * n,b,mid,l,r);
	p2 = queryma(2 * n + 1,mid+1,e,l,r);
	return max(p1,p2);
}

lol querymi(lol n,lol b,lol e,lol l,lol r)
{
	lol p1,p2;
	if(l>e || r<b)
	{
		return inf;
	}
	if(b >=l && e<=r)
	{
		return mi[n];
	}
	lol mid = (b+e) >> 1;
	p1 = querymi(2 * n,b,mid,l,r);
	p2 = querymi(2 * n + 1,mid+1,e,l,r);
	return min(p1,p2);
}

int main()
{
#ifdef shorn
	freopen("robot1.in","r",stdin);
	freopen("rrr1.out","w",stdout);
#endif
	//scanf("%d",&n);
    n = in();m = in();
	for(lol i=1;i<=n;i++)
	{
		//scanf("%d",&a[i]);
        a[i] = in();
	}
	build(1,1,n);
    for(lol i=1;i<= m ;i++)
    {
		lol ll = in();
		lol rr = in();
        printf("%lld\n",queryma(1,1,n,ll,rr)-querymi(1,1,n,ll,rr));
    }
	return 0;
}

