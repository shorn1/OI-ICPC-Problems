#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

const int M = 1111111;
struct Edge
{
    int tow,nxt,dat;
};
Edge e[2 * M];
int n,m,s,sume = 0,dis[2 * M],vis[2 * M],hea[2 * M];
queue <int>q;
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

void spfa(int s)
{
    dis[s] = 0;
    vis[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for(int now = hea[x];now;now = e[now].nxt)
        {
            int y = e[now].tow,z = e[now].dat;
            if(dis[y] > dis[x] + z)
            {
                dis[y] = dis[x]+z;
                if(!vis[y])
                {
                    vis[y] = 1;
                    q.push(y);
                }
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
    scanf("%d%d%d",&n,&m,&s);
    init();
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        //add(b,a,c);
    }
    spfa(s);
    pans();
    return 0;
}
