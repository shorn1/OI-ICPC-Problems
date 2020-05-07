#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

#define ns namespace
#define lol long long
using ns std;

const int M = 450;
int n,m,mp[M][M],sx,sy,vis[M][M];
const int dx[] = {1,1,-1,-1,2,2,-2,-2};
const int dy[] = {2,-2,2,-2,1,-1,1,-1};

struct Point
{
    int x,y,stp;
    Point(int _x = 0,int _y = 0,int _stp = 0)
    {
        x = _x;y = _y;stp = _stp;
    }
}p;

queue<Point> q;

int main(int argc,char** argv)
{
    scanf("%d%d%d%d",&n,&m,&p.x,&p.y);
    p.stp = 0;
    q.push(p);
    while(!q.empty())
    {
        p = q.front();
        vis[p.x][p.y] = 1;
        mp[p.x][p.y] = p.stp;
        q.pop();
        for(int i = 0;i < 8;i++)
        {
            int tx = p.x + dx[i],ty = p.y + dy[i];
            if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && !vis[tx][ty])
            {
                vis[tx][ty] = 1;
                Point tp(tx,ty,p.stp + 1);
                q.push(tp);
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            printf("%-5d",vis[i][j] ? mp[i][j] : -1);
        }
        printf("\n");
    }
    return 0;
}