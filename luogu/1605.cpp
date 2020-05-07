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

const int M = 11;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
int res,n,m,t,sx,sy,fx,fy;
int vis[M][M],mp[M][M];

void dfs(int x,int y)
{
    if(x == fx && y == fy)
    {
        ++res;
        return;
    }
    vis[x][y] = 1;
    for(int i = 0;i < 4;i++)
    {
        if(x + dx[i] <= n && x + dx[i] >= 1 && y + dy[i] <= n && y + dy[i] >= 1 && !vis[x + dx[i]][y + dy[i]] && !mp[x + dx[i]][y + dy[i]])        
        {
            dfs(x + dx[i],y + dy[i]);
        }
    }
    vis[x][y] = 0;
}

int main(int argc,char** argv)
{
    scanf("%d%d%d%d%d%d%d",&n,&m,&t,&sx,&sy,&fx,&fy);
    for(int i = 1;i <= t;i++)
    {
        int dx,dy;
        scanf("%d%d",&dx,&dy);
        mp[dx][dy] = 1;
    }
    dfs(sx,sy);
    printf("%d\n",res);
    return 0;
}