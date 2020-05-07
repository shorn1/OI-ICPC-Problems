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
int r,a[M][M],dp[M][M];

int main(int argc,char** argv)
{
    scanf("%d",&r);
    for(int i = 1;i <= r;i++) 
        for(int j = 1;j <= i;j++)
            scanf("%d",&a[i][j]);
    for(int i = 1;i <= r;i++) dp[r][i] = a[r][i];
    for(int i = r - 1;i >= 1;i--)
        for(int j = 1;j <= i;j++)
            dp[i][j] = max(dp[i + 1][j],dp[i + 1][j + 1]) + a[i][j];
    printf("%d\n",dp[1][1]);
    return 0;
}