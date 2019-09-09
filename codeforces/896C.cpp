#include<bits/stdc++.h>

#define ns namespace
#define lol long long
using ns std;

int n,m;
lol seed,vmax;

struct Node
{
    int l,r;
    mutable lol v;
    Node(int _l = 0,int _r = -1,lol _v = 0LL):l(_l),r(_r),v(_v){}
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
    lol v = it->v;
    s.erase(it);
    s.insert(Node(l, pos - 1,v));
    return s.insert(Node(pos,r,v)).first;
}

void assign(int l,int r,lol v)
{
    auto itr = split(r + 1),itl = split(l);
    s.erase(itl,itr);
    s.insert(Node(l,r,v));
}

void plu(int l,int r,lol x)
{
    auto itr = split(r + 1),itl = split(l);
    for(;itl != itr;++itl)
    {
        itl->v += x;
    }
}

lol rk(int l,int r,int k)
{
    vector<pair<lol,int> > vec;
    auto itr = split(r + 1),itl = split(l);
    vec.clear();
    for(;itl != itr;++itl)
    {
        vec.push_back(make_pair(itl->v,itl->r - itl->l + 1));
    }
    sort(vec.begin(),vec.end());
    for(auto &i : vec)
    {
        k -= i.second;
        if(k <= 0) return i.first;
    }
    return -1;
}

lol fpow(lol x,lol y,lol mo)
{
    if(!y) return 1LL;
    if(y == 1) return x % mo;
    lol t = x % mo * x % mo;
    if(y & 1) return fpow(t, y >> 1,mo) % mo * x % mo;
    return fpow(t, y >> 1,mo) % mo;
}

lol psum(int l,int r,lol k,lol mo)
{
    auto itr = split(r + 1),itl = split(l);
    lol sum = 0LL;
    for(;itl != itr;++itl)
    {
        sum += fpow(itl->v,k,mo) % mo * (itl->r - itl->l + 1) % mo;
        sum %= mo;
    }
    return sum;
}

lol rnd()
{
    lol ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}

int main(int argc,char** argv)
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> seed >> vmax;
    for(int i = 1;i <= n;i++)
    {
        s.insert(Node(i,i,(rnd() % vmax) + 1));
    }
    for(int i = 1;i <= m;i++)
    {
        int op = (rnd() % 4) + 1;
        int l = (rnd() % n) + 1;
        int r = (rnd() % n) + 1;
        if(l > r) swap(l,r);
        lol x,y;
        if(op == 3)
            x = rnd() % (r - l + 1) + 1;
        else 
            x = rnd() % vmax + 1;
        if(op == 4)
            y = rnd() % vmax + 1;
        if(op == 1)
        {
            plu(l,r,x);
        }
        else if(op == 2)
        {
            assign(l,r,x);
        }
        else if(op == 3)
        {
            cout << rk(l,r,x) << endl;
        }
        else if(op == 4)
        {
            cout << psum(l,r,x,y) << endl;
        }
    }
    return 0;
}