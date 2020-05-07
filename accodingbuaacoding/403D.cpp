#include<bits/stdc++.h>

#define ns namespace
#define lol long long
using ns std;

int n,m;

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
    s.erase(itl,itr);
    s.insert(Node(l,r,v));
}

int que()
{   
    int r = 0;
    for(auto it = s.begin();it != s.end();++it)
    {
        r += (it->r - it->l + 1) * it->v; 
    }
    return r;
}


int main(int argc,char** argv)
{
    scanf("%d%d",&n,&m);
    s.insert(Node(1,n,0));
    for(int i = 1;i <= m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        assign(l,r,1);
        printf("%d\n",n - que());
    }
    return 0;
}