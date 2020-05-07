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

const int M = 1011;
int n,m,sum;
int mp[M][M],ans[M][M],vis[M][M];
const int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};

int dfs1(int x,int y)
{
    ans[x][y] = max(ans[x][y],sum);
    for(int i = 0;i < 4;i++)
    {
        int tx = x + dx[i],ty = y + dy[i];
        if(tx >= 1 && tx <= n && ty >= 1 && ty <= n && mp[tx][ty] != mp[x][y] && !ans[tx][ty])
        {
            ++sum;
            int t = dfs1(tx,ty);
            ans[x][y] = max(ans[x][y],sum);
        }
    }
    return sum;
}

void dfs2(int x,int y,int r)
{
    ans[x][y] = max(ans[x][y],r);
    vis[x][y] = 1;
    for(int i = 0;i < 4;i++)
    {
        int tx = x + dx[i],ty = y + dy[i];
        if(tx >= 1 && tx <= n && ty >= 1 && ty <= n && mp[tx][ty] != mp[x][y] && !vis[tx][ty])
        {
            dfs2(tx,ty,r);
        }
    }
}

int main(int argc,char** argv)
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= n;j++)
            scanf("%1d",&mp[i][j]);
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= n;j++)
        {
            if(!ans[i][j]) 
            {
                sum = 1;
                dfs1(i,j);
                dfs2(i,j,ans[i][j]);
            }
        }
    for(int i = 1;i <= m;i++) 
    {
        int qx,qy;
        scanf("%d%d",&qx,&qy);
        printf("%d\n",ans[qx][qy]);
    }
    return 0;
}