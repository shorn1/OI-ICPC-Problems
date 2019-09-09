#include <bits/stdc++.h>

#define ns namespace
#define lol long long
using ns std;

const int M = 533333;

struct ty
{
    int x, u;
};
struct gr
{
    int tow, hea, nxt, dis, da;
};
bool operator <(const ty &x, const ty &y)
{
    return x.x > y.x;
}
gr g[2 * M];
priority_queue<ty> q;
int n, m, s, a, b, c, sume = 0, v[2 * M];

void add(int u, int v, int d)
{
    sume++;
    g[sume].nxt = g[u].hea;
    g[u].hea = sume;
    g[sume].tow = v;
    g[sume].da = d;
}

void pre()
{
    for (int i = 0; i <= 2 * m + 1; i++)
    {
        g[i].nxt = g[i].tow = g[i].hea = 0;
        g[i].da = g[i].dis = 2147483647;
    }
    memset(v, 0, sizeof(v));
}

void dij(int s)
{
    g[s].dis = 0;
    q.push((ty){
        0, s});
    while (!q.empty())
    {
        ty x = q.top();
        q.pop();
        int u = x.u;
        if (v[u])
            continue;
        v[u] = 1;
        //printf("%d\n",u);
        for (int now = g[u].hea; now; now = g[now].nxt)
        {
            int t = g[now].tow;
            if (!v[t])
                if (g[u].dis + g[now].da < g[t].dis)
                {
                    g[t].dis = g[u].dis + g[now].da;
                    q.push((ty){
                        g[t].dis, t});
                }
        }
    }
}

void prin()
{
    for(int i = 1;i <= n;i++)
        printf("%d ", g[i].dis);
}

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    pre();
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        //add(b, a, c);
    }
    dij(s);
    prin();
    return 0;
}
