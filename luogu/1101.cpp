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
const char st[M] = "yizhong\0";
const int dx[9] = {0,1,-1,0,0,1,-1,1,-1};
const int dy[9] = {0,0,0,1,-1,1,-1,-1,1};
char s[M][M],tmp[M];
int mp[M][M],vis[M][M];
int n;

int dfs(int x,int y,int l,int ty)
{    
    tmp[l] = s[x][y];
    if(l >= 6)
    {    
        if(!strcmp(tmp,st))
        {
            mp[x][y] = 1;
            return 1;
        }
        else return 0;
    }
    int flg = 0;
    if(ty)
    {
        if(x + dx[ty] <= n && x + dx[ty] >= 1 && y + dy[ty] <= n && y + dy[ty] >= 1)
        {
            vis[x][y] = 1;
            int t = dfs(x + dx[ty],y + dy[ty],l + 1,ty);
            vis[x][y] = 0;
            if(t) 
            {
                mp[x][y] = 1;
                flg = 1;
            }    
        }
    }
    else
    {
        for(int i = 1;i <= 8;i++)
        {    
            if(x + dx[i] <= n && x + dx[i] >= 1 && y + dy[i] <= n && y + dy[i] >= 1)
            {
                vis[x][y] = 1;
                int t = dfs(x + dx[i],y + dy[i],l + 1,i);
                vis[x][y] = 0;
                if(t) 
                {
                    mp[x][y] = 1;
                    flg = 1;
                }    
            }
        }
    }
    if(flg) return 1;
    return 0;
}

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%s",s[i] + 1);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            dfs(i,j,0,0);
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(mp[i][j]) printf("%c",s[i][j]);
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}