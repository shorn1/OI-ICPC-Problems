#include<bits/stdc++.h>

#define ns namespace
#define lol long long
using ns std;

int n,m;
int op,a,b;

struct Node
{
    int l,r;
    mutable int v;
    Node(int _l = 0,int _r = -1,int _v = 0LL):l(_l),r(_r),v(_v){}
    bool operator < (const Node &a) const
    {
        return l < a.l;
    }
};

set<Node> s;

auto split(int pos) -> set<Node>::iterator
{
    auto it = s.lower_bound(pos);
    if(it != s.end() && it->l == pos) return it;
    --it;
    int l = it->l, r = it->r;
    int v = it->v;
    s.erase(it);
    s.insert(Node(l, pos - 1,v));
    return s.insert(Node(pos,r,v)).first;
}

void assign(int l,int r,int v)
{
    auto itr = split(r + 1),itl = split(l);
    s.erase(itl,itr);
    s.insert(Node(l,r,v));
}

void rev(int l,int r)
{
    auto itr = split(r + 1),itl = split(l);
    for(;itl != itr;++itl)
    {
        itl->v ^= 1;
    }
}

int sum(int l,int r)
{
    int su = 0;
    auto itr = split(r + 1),itl = split(l);
    for(;itl != itr;++itl)
    {
        su += itl->v * (itl->r - itl->l + 1);
    }
    return su;
}

int co(int l,int r)
{
    int co = 0,mx = 0;
    auto itr = split(r + 1),itl = split(l);
    for(;itl != itr;++itl)
    {
        if(itl->v)
        {
            co += (itl->r - itl->l + 1);
        }
        else
        {
            mx = max(mx,co);
            co = 0;
        }
    }
    mx = max(mx,co);
    return mx;
}

int main(int argc,char** argv)
{
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++)
    {
        int t;
        scanf("%d",&t);
        s.insert(Node(i,i,t));
    }
    for(int i = 0;i < m;i++)
    {
        scanf("%d%d%d",&op,&a,&b);
        if(!op) assign(a,b,0);
        else if(op == 1) assign(a,b,1);
        else if(op == 2) rev(a,b);
        else if(op == 3) printf("%d\n",sum(a,b));
        else if(op == 4) printf("%d\n",co(a,b));
    }
    return 0;
}