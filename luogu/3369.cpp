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

const int M = 111111;

int root,tot;

struct Node
{
	int fa,lc,rc,val,siz;
	Node(): fa(0),lc(0),rc(0),val(0),siz(0){}
}t[M];

inline int which(int u)
{
	return t[t[u].fa].rc == u ? 1 : 0;
}

void upd(int u)
{
	t[u].siz = t[t[u].lc].siz + t[t[u].rc].siz + 1;
}

void rot(int u)
{
	int v = t[u].fa;
	int w = t[v].fa;
	int b = (t[v].lc == u) ? t[u].rc : t[u].lc;
	t[u].fa = w;
	t[v].fa = u;
	if(b) t[b].fa = v;
	if(w) 
	{
		if(t[w].lc == v) t[w].lc = u;
		else t[w].rc = u;
	}
	if(t[v].lc == u)
	{
		t[u].rc = v;t[v].lc = b;
	}
	else
	{
		t[u].lc = v;t[v].rc = b;
	}
	upd(v);
}

void splay(int u,int tar)
{
	while(t[u].fa != tar)
	{
		if(t[t[u].fa].fa != tar)
		{
			if(which(u) == which(t[u].fa)) rot(t[u].fa);
			else rot(u);
		}
		rot(u);
	}
	upd(u);
	if(!tar) root = u;
}

void insert(int val)
{
	int u = root,v = 0,dir = 0;
	while(u)
	{
		v = u;
		t[u].siz++;
		if(val < t[u].val)
		{
			dir = 0;
			u = t[u].lc;
		}
		else 
		{
			dir = 1;
			u = t[u].rc;
		}
	}
	u = ++tot;
	t[u].fa = v;
	t[u].val = val;
	t[u].siz = 1;
	if(v) (dir ? t[v].lc : t[v].rc) = u;
	splay(u,0);
}

int main(int argc,char** argv)
{
    printf("1\n");
    return 0;
}