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
const int M = 1022222;
int n,m;
lol tre[M<<1],lz[M<<1],a[M];

void psd(int k,int l,int r)
{
	if(lz[k])
	{
		lz[lson] += lz[k];
		lz[rson] += lz[k];
		tre[lson] += lz[k] * (mid - l + 1);
		tre[rson] += lz[k] * (r - mid);
		lz[k] = 0;
	}
}

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

void upd(int k,int l,int r,int x,int y,lol v)
{
	if(l > y || r < x) return;
	if(l >=x && r <= y)
	{
		tre[k] += (lol)(r - l + 1) * v;
		lz[k] += v;
		return;
	}
	psd(k,l,r);
	if(x <= mid) upd(lson,l,mid,x,y,v);
	if(y > mid) upd(rson,mid+1,r,x,y,v);
	tre[k] = tre[lson] + tre[rson];
}

lol squery(int k,int l,int r,int x)
{
	if(l == r)
	{
		return tre[k];
	}
	psd(k,l,r);
	lol res = 0LL;
	if(x <= mid) res += squery(lson,l,mid,x);
	else res += squery(rson,mid+1,r,x);
	return res;
}


int main(int argc,char** argv)
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
    build(1,1,n);
    for(int i = 1;i <= m;i++)
    {
        int ty,x,y;
        lol k;
        scanf("%d",&ty);
        if(ty == 1)
        {
            scanf("%d%d%lld",&x,&y,&k);
            upd(1,1,n,x,y,k);
        }
        else 
        {
            scanf("%d",&x);
            printf("%lld\n",squery(1,1,n,x));
        }
    }
    return 0;
}