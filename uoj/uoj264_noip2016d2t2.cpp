#pragma GCC OPTIMIZE("Ofast")
#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

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

int n,m,qq,u,v,t,tt = 0,a[233333];
lol sq = 0LL,l1,l2,l3,ans;

queue<lol> q[4];

lol gmax(const lol &a,const lol &b,const lol &c)
{
    return max(max(a,b),c);
}

void cu(int qnum,lol len)
{
    //lol len = static_cast<lol>(q[qnum].front() + tim * qq);
    q[qnum].pop();
    ans = len + sq;
    lol ll1 = floor(ans * static_cast<lol>(u) / static_cast<lol>(v));
    lol ll2 = ans - ll1;
    q[2].push(ll1 - sq - qq);
    q[3].push(ll2 - sq - qq);
}

void pans(int qnum,lol len)
{
    if(tt % t == 0) printf("%lld ",len + sq);
    q[qnum].pop();
}

int main(int argc,char** argv)
{
    n = in();m = in();qq = in();u = in();v = in();t = in();
    for(int i = 0;i < n;i++)
        a[i] = in();
    sort(a,a + n,greater<int>());
    for(int i = 0;i < n;i++)
        q[1].push(static_cast<lol>(a[i]));
    for(int i = 1;i <= m;i++)
    {
        if(!q[1].empty())
        {
            l1 = q[1].front();
            if(!q[2].empty())
            {
                l2 = q[2].front();
                if(!q[3].empty())
                {
                    l3 = q[3].front();
                    if(gmax(l1,l2,l3) == l1) cu(1,l1);
                    else if(gmax(l1,l2,l3) == l2) cu(2,l2);
                    else if(gmax(l1,l2,l3) == l3) cu(3,l3);
                }
                else 
                {
                    if(max(l1,l2) == l1) cu(1,l1);
                    else if(max(l1,l2) == l2) cu(2,l2);
                }
            }
            else
            {
                if(!q[3].empty())
                {
                    l3 = q[3].front();
                    if(max(l1,l3) == l1) cu(1,l1);
                    else if(max(l1,l3) == l3) cu(3,l3);
                }
                else cu(1,l1);
            }
        }
        else
        {
            if(!q[2].empty())
            {
                l2 = q[2].front();
                if(!q[3].empty())
                {
                    l3 = q[3].front();
                    if(max(l3,l2) == l3) cu(3,l3);
                    else if(max(l3,l2) == l2) cu(2,l2);
                }
                else cu(2,l2);
            }
            else if(!q[3].empty())
            {
                l3 = q[3].front();
                cu(3,l3);
            }
        }       
        if(i % t == 0)
        {
            printf("%lld ",ans);
        }
        sq += qq;
    }
    puts("");
    while(!q[1].empty() || !q[2].empty() || !q[3].empty())
    {
        tt++;
        if(!q[1].empty())
        {
            l1 = q[1].front();
            if(!q[2].empty())
            {
                l2 = q[2].front();
                if(!q[3].empty())
                {
                    l3 = q[3].front();
                    if(gmax(l1,l2,l3) == l1) pans(1,l1);
                    else if(gmax(l1,l2,l3) == l2) pans(2,l2);
                    else if(gmax(l1,l2,l3) == l3) pans(3,l3);
                }
                else 
                {
                    if(max(l1,l2) == l1) pans(1,l1);
                    else if(max(l1,l2) == l2) pans(2,l2);
                }
            }
            else
            {
                if(!q[3].empty())
                {
                    l3 = q[3].front();
                    if(max(l1,l3) == l1) pans(1,l1);
                    else if(max(l1,l3) == l3) pans(3,l3);
                }
                else pans(1,l1);
            }
        }
        else
        {
            if(!q[2].empty())
            {
                l2 = q[2].front();
                if(!q[3].empty())
                {
                    l3 = q[3].front();
                    if(max(l2,l3) == l2) pans(2,l2);
                    else if(max(l2,l3) == l3) pans(3,l3);
                }
                else pans(2,l2);
            }
            else if(!q[3].empty())
            {
                l3 = q[3].front();
                pans(3,l3);
            }
        }       
    }
    return 0;
}