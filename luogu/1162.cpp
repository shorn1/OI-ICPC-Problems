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

const int M = 111;
int n;
int mp[M][M],vis[M][M];
const int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};

void dfs(int x,int y)
{
    vis[x][y] = 1;
    for(int i = 0;i < 4;i++)
    {
        int tx = x + dx[i],ty = y + dy[i];
        if(tx >= 0 && tx <= n + 1 && ty >= 0 && ty <= n + 1 && !vis[tx][ty] && !mp[tx][ty])
        dfs(tx,ty);
    }
}

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= n;j++)
            scanf("%d",&mp[i][j]);
    dfs(0,0);
    for(int i = 1;i <= n;i++) 
    {
        for(int j = 1;j <= n;j++)
        {
            if(!vis[i][j] && !mp[i][j]) printf("2 ");
            else printf("%d ",mp[i][j]);
        }
        printf("\n");
    }
    return 0;
}