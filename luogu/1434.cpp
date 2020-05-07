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
int r,c,ans,mp[M][M],a[M][M];
const int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};
int dfs(int x,int y)
{
    if(a[x][y]) return a[x][y];
    a[x][y] = 1;
    for(int i = 0;i < 4;i++)
    {
        int tx = x + dx[i],ty = y + dy[i];
        if(tx >= 1 && tx <= r && ty >= 1 && ty <= c && mp[x][y] > mp[tx][ty])
        {
            int t = dfs(tx,ty);
            a[x][y] = max(a[x][y],t + 1);
        }
    }
    return a[x][y];
}

int main(int argc,char** argv)
{
    scanf("%d%d",&r,&c);
    for(int i = 1;i <= r;i++)
    {
        for(int j = 1;j <= c;j++) 
            scanf("%d",&mp[i][j]);
    }
    for(int i = 1;i <= r;i++)
    {
        for(int j = 1;j <= c;j++) 
            ans = max(ans,dfs(i,j));
    }
    printf("%d\n",ans);
    return 0;
}