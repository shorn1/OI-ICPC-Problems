#include<bits/stdc++.h>

#define ns namespace
#define lol long long
using ns std;

int n,q,sum;

struct Node
{
    int l,r;
    mutable int v;
    Node(int _l = 0,int _r = -1,int _v = 0):l(_l),r(_r),v(_v){}
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
    auto bk = itl;
    for(;itl != itr;++itl)
    {
        if(v) sum += ((!itl->v) * (itl->r - itl->l + 1));
        else sum -= (itl->v * (itl->r - itl->l + 1));
    }
    s.erase(bk,itr);
    s.insert(Node(l,r,v));
}

int main(int argc,char** argv)
{
    scanf("%d%d",&n,&q);
    s.insert(Node(1,n,1));
    sum = n;
    for(int i = 1;i <= q;i++)
    {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k); 
        assign(l,r,k-1);
        printf("%d\n",sum);
    }
    return 0;
}