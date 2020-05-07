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

const int M = 23;
int n,c[M][M],a[M],sum;

int main(int argc,char** argv)
{
    scanf("%d%d",&n,&sum);
    for(int i = 0;i <= n;i++) c[i][0] = c[i][i] = 1;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= (i + 1) / 2;j++)
        {
            c[i][j]  = c[i][i - j]= c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    /*for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j <= i;j++)
        {
            printf("%d ",c[i][j]);
        }
        puts("");
    }*/
    for(int i = 0;i < n;i++) a[i] = i + 1;
    do
    {
        int t = 0;
        for(int i = 0;i < n;i++) t += a[i] * c[n - 1][i];
        if(t == sum)
        {
            for(int i = 0;i < n;i++) printf("%d ",a[i]);
            return 0;
        }
        //printf("t = %d\n",t);
    }while(next_permutation(a,a + n));
    return 0;
}