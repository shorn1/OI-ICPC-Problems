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

#define lson (k << 1)
#define rson ((k << 1) + 1)
#define mid ((l + r) >> 1)
const int M = 500111;
int n,m;
lol tre[4*M],a[M];

void build(int k,int l,int r)
{
	if(l==r)
	{
		tre[k] = (lol)a[l];
		return;
	}
	build(lson,l,mid);
	build(rson,mid+1,r);
	tre[k] = tre[lson] + tre[rson];
}

void upd(int k,int l,int r,int x,lol v)
{
	if(l == r)
	{
		tre[k] += v;
		return;
	}
	if(x <= mid) upd(lson,l,mid,x,v);
	else upd(rson,mid+1,r,x,v);
	tre[k] = tre[lson] + tre[rson];
}

lol query(int k,int l,int r,int x,int y)
{
	if(l >= x && r <= y)
	{
		return tre[k];
	}
	lol res = 0LL;
	if(x <= mid) res += query(lson,l,mid,x,y);
	if(y > mid) res += query(rson,mid+1,r,x,y);
	return res;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	build(1,1,n);
    for(int i = 1;i <= m;i++)
    {
        int ty,x,y;
        lol k;
        scanf("%d",&ty);
        if(ty == 1)
        {
            scanf("%d%lld",&x,&k);
            upd(1,1,n,x,k);
        }
        else 
        {
            scanf("%d%d",&x,&y);
            printf("%lld\n",query(1,1,n,x,y));
        }
    }
	return 0;
}
