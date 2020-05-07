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

const int M = 233333;
struct Edge
{
    int tow,nxt,dat;
};
Edge e[2 * M];
int n, m, s, a, b, c, sume = 0, vis[2 * M],hea[2 * M],dis[2 * M];

void add(int u, int v, int w)
{
    sume++;
    e[sume].nxt = hea[u];
    hea[u] = sume;
    e[sume].tow = v;
    e[sume].dat = w;
}

int prim(int st)
{
    int cur = st;
    long long res = 0LL;
    for(int i = 1;i <= n;i++)
    {
        dis[i] = 2147483647;
    }
    memset(vis, 0, sizeof(vis));
    for(int now = hea[st];now;now = e[now].nxt)
    {
        int t = e[now].tow;
        dis[t] = min(dis[t],e[now].dat);
    }
    for(int i = 1;i < n;i++)
    {
        int mi = 2147483647;
        vis[cur] = 1;
        for(int j = 1;j <= n;j++)
        {
            if(!vis[j] && mi > dis[j])
            {
                mi = dis[j];
                cur = j;
            }
        }
        res += mi;
        for(int now = hea[cur];now;now = e[now].nxt)
        {
            int t = e[now].tow;
            if(dis[t] > e[now].dat && !vis[t])
            {
                dis[t] = e[now].dat;
            }
        }
    }
    return res >= 2147483647 ? -1 : res;
}

int main(int argc,char** argv)
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    int r;
    r = prim(1);
    if(r == -1) printf("orz\n");
    else printf("%d\n",r);
    return 0;
}