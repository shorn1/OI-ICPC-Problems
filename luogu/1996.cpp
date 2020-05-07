#include<bits/stdc++.h>

#define ns namespace
#define lol long long
using ns std;

int n,m,c;
int a[233],vis[233];

int main(int argc,char** argv)
{
    scanf("%d%d",&n,&m);
    c = 0;
    for(int i = 1;i <= n;i++) 
    {
        for(int j = 1;j <= m;j++)
        {
            c++;
            while(c > n) c -= n;
            while(vis[c])
            {
                c++;
                while(c > n) c -= n;
            }
            while(c > n) c -= n;
        }
        vis[c] = 1;
        printf("%d ",c);
    }
    return 0;
}