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

const int M = 1000111;
int tree[4*M],a[M],n,m;
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

void build(int n,int b,int e)
{
	if(b==e)
	{
		tree[n] = a[b];
		return;
	}
	int mid = (b+e) >> 1;
	build(2 * n,b,mid);
	build(2 * n + 1,mid+1,e);
	tree[n] = max(tree[2 * n],tree[2 * n + 1]);
}

int query(int n,int b,int e,int l,int r)
{
	int p1,p2;
	if(l>e || r<b)
	{
		return 0;
	}
	if(b >=l && e<=r)
	{
		return tree[n];
	}
	int mid = (b+e) >> 1;
	p1 = query(2 * n,b,mid,l,r);
	p2 = query(2 * n + 1,mid+1,e,l,r);
	return max(p1,p2);
}

void supdate(int n,int b,int e,int ind,int ad)
{
	if(b==e)
	{
		tree[b] = ad;
		return;
	}
	int mid = (b+e) >>1;
	if(ind <=mid) supdate(2 * n,b,mid,ind,ad);
	else supdate(2 * n + 1,mid+1,e,ind,ad);
	tree[n] = max(tree[2 * n],tree[2 * n + 1]);
}

int main()
{
	//scanf("%d",&n);
    n = in();m = in();
	for(int i=1;i<=n;i++)
	{
		//scanf("%d",&a[i]);
        a[i] = in();
	}
	build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int x = in();
        int y = in();
        printf("%d\n",query(1,1,n,x,y));
    }
	return 0;
}

