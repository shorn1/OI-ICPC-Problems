#include<bits/stdc++.h>

#define ns namespace
#define lol long long
using ns std;

constexpr int M = 233333;
int n,m;
char bf[M];
int res;

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

int query(int l,int r,int v)
{
    auto itr = split(r + 1),itl = split(l);
    int res= 0;
    for(;itl != itr;++itl)
    {
        if(itl->v == v) res += (itl->r - itl->l + 1);
    }
    return res;
}

void s_sort(int l,int r)
{
    auto itr = split(r + 1),itl = split(l);
    int cnt[30];
    memset(cnt,0,sizeof(cnt));
    auto itl2 = itl;
    for(;itl != itr;++itl)
    {
        cnt[itl->v - 'A'] += (itl->r - itl->l + 1);
    }
    s.erase(itl2,itr);
    for(int i = 0; i < 26;i++)
    {
        if(cnt[i])
        {
            s.insert(Node(l,l + cnt[i] - 1,i + 'A'));
            l += cnt[i];
        }
    }

}

int main(int argc,char** argv)
{
    scanf("%d%d",&n,&m);
    scanf("%s",bf+1);
    for(int i = 1;i <= n;i++)
    {
        if(islower(bf[i])) bf[i] = toupper(bf[i]);
        s.insert(Node(i,i,bf[i]));
    }
    for(int i = 0;i < m;i++)
    {
        int op,l,r;
        char k;
        scanf("%d",&op);
        if(op == 1)
        {
            scanf("%d%d %c",&l,&r,&k);
            if(islower(k)) k = toupper(k);
            printf("%d\n",query(l,r,k));
        }
        else if(op == 2)
        {
            scanf("%d%d %c",&l,&r,&k);
            if(islower(k)) k = toupper(k);
            assign(l,r,k);
        }
        else
        {
            scanf("%d%d",&l,&r);
            s_sort(l,r);
        }
    }
    return 0;
}