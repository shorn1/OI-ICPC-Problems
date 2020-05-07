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

const int M = 211111;

struct Edge
{
    int u,v,w;
    bool operator < (const Edge &a) const
    {
        return w < a.w;
    }
};
Edge e[M];
int n,m;
int fa[M],size[M];
long long res,sumed;

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
		size[getfa(x)] = s1 + s2;
	}
	else
	{
		fa[getfa(x)]= getfa(y);
		size[getfa(y)] = s1 + s2;
	}
}

void kruskal()
{
    sort(e + 1,e + 1 + m);
    for(int i = 1;i <= m && sumed < n;i++)
    {
        if(getfa(e[i].u) != getfa(e[i].v))
        {
            res += e[i].w;
            sumed++;
            merge(e[i].u,e[i].v);
        }
    }
}

void init()
{
    for(int i = 1;i <= n;i++)
    {
        fa[i] = i;
        size[i] = 1;
    }
    for(int i = 1;i <= m;i++)
    {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
}

int main(int argc,char** argv)
{
    scanf("%d%d",&n,&m);
    init();    
    kruskal();    
    printf("%lld",sumed == n - 1 ? res : -1LL);
    return 0;
}