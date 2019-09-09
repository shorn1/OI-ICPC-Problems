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

const int M = 233333;
int n,m,fa[M],size[M];

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

int main(int argc,char** argv)
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) 
    {
        size[i] = 1;
        fa[i] = i;
    }
    for(int i = 1;i <= m;i++)
    {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op == 1)
        {
            merge(x,y);
        }
        else
        {
            if(getfa(x) == getfa(y)) puts("Y");
            else puts("N");
        }
    }
    return 0;
}