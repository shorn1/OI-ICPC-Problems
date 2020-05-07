#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int n,a[1000111],t[1000111];
long long ans = 0;
void msort(int x,int y)
{
	if(x==y) return;
	int mid = (x + y) >> 1;
	msort(x,mid);
	msort(mid+1,y);
	int l = x, r = mid+1, j = x;
	while(l<=mid && r<=y)
	{
		if(a[l]<=a[r])
		{
			t[j] = a[l]; j++;l++;
		}
		else
		{
			t[j] = a[r]; r++;j++;			
			ans += mid-l+1;
		}
		
	}
	while(l<=mid)
	{
		t[j] = a[l]; j++;l++;
	}
	while(r<=y)
	{
		t[j] = a[r]; r++;j++;
	}
	for(int i=x;i<=y;i++)
		a[i] = t[i];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	msort(1,n);
	printf("%lld",ans);
	return 0;
}

