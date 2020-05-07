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

const int M = 41;
int n,m,dp[M][M][M][M],p[366],cd[5];

int main(int argc,char** argv)
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)
        scanf("%d",&p[i]);
    for(int i = 1;i <= m;i++)    
    {
        int t;
        scanf("%d",&t);
        cd[t]++;
    }
    dp[0][0][0][0] = p[1];
    for(int i = 1;i <= m;i++)
        for(int a = 0;a <= cd[1];a++)
            for(int b = 0;b <= cd[2];b++)
                for(int c = 0;c <= cd[3];c++)
                    for(int d = 0;d <= cd[4];d++)
                    {
                        int t = a + 2 * b + 3 * c + 4 * d + 1;
                        if(a > 0) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a - 1][b][c][d] + p[t]);
                        if(b > 0) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a][b - 1][c][d] + p[t]);
                        if(c > 0) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a][b][c - 1][d] + p[t]);
                        if(d > 0) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a][b][c][d - 1] + p[t]);
                    }
    printf("%d\n",dp[cd[1]][cd[2]][cd[3]][cd[4]]);
    return 0;
}