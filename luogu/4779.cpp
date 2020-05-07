#include <bits/stdc++.h>

#define ns namespace
#define lol long long
using ns std;

const int M = 533333;

struct Edge
{
    int tow,nxt,dat;
};
Edge e[2 * M];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > q;
int n, m, s, a, b, c, sume = 0, vis[2 * M],hea[2 * M],dis[2 * M];

void add(int u, int v, int w)
{
    sume++;
    e[sume].nxt = hea[u];
    hea[u] = sume;
    e[sume].tow = v;
    e[sume].dat = w;
}

void init()
{
    for (int i = 0; i <= 2 * m + 1; i++)
    {
        e[i].dat = dis[i] = 2147483647;
    }
    memset(vis, 0, sizeof(vis));
}

void dij(int s)
{
    dis[s] = 0;
    q.push(make_pair(0,s));
    while (!q.empty())
    {
        pii x = q.top();
        q.pop();
        int u = x.second;
        if (vis[u])
            continue;
        vis[u] = 1;
        //printf("%d\n",u);
        for (int now = hea[u]; now; now = e[now].nxt)
        {
            int t = e[now].tow;
            if (!vis[t])
                if (dis[u] + e[now].dat < dis[t])
                {
                    dis[t] = dis[u] + e[now].dat;
                    q.push(make_pair(dis[t], t));
                }
        }
    }
}

void pans()
{
    for(int i = 1;i <= n;i++)
        printf("%d ", dis[i]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    init();
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        //add(b, a, c);
    }
    dij(s);
    pans();
    return 0;
}
