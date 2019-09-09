#include<bits/stdc++.h>

#define ns namespace
#define lol long long
using ns std;

int n;
lol res;

struct Node
{
    lol l,r;
    mutable int v;
    Node(lol _l = 0,lol _r = -1,int _v = 0):l(_l),r(_r),v(_v){}
    bool operator < (const Node &a) const
    {
        return l < a.l;
    }
};

set<Node> s;

auto split(lol pos) -> set<Node>::iterator
{
    auto it = s.lower_bound(pos);
    if(it != s.end() && it->l == pos) return it;
    --it;
    lol l = it->l, r = it->r;
    int v = it->v;
    s.erase(it);
    s.insert(Node(l, pos - 1,v));
    return s.insert(Node(pos,r,v)).first;
}

void assign(lol l,lol r,int v)
{
    auto itr = split(r + 1),itl = split(l);
    s.erase(itl,itr);
    s.insert(Node(l,r,v));
}

int main(int argc,char** argv)
{
    scanf("%d",&n);
    s.insert(Node(0,1e17,0));
    for(int i = 1;i <= n;i++)
    {
        lol l,r;
        scanf("%lld%lld",&l,&r); 
        assign(l,r,1);
    }
    for(auto &i : s)
    {
        res += (i.r - i.l + 1) * (i.v);
    }
    printf("%lld",res);
    return 0;
}