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

const int M = 33;
int n,res,r[M],a[M],b[M],c[M];

void print()
{
    ++res;
    if(res <= 3)
    {
        for(int i = 1;i <= n;i++)
        {
            printf("%d ",r[i]);
        }
        puts("");
    }
}

void dfs(int k)
{
    if(k > n)
    {
        print();
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        if(!a[i] && !b[i + k] && !c[i - k + n])
        {
            r[k] = i;
            ++a[i];
            ++b[i + k];
            ++c[i - k + n];
            dfs(k + 1);
            --a[i];
            --b[i + k];
            --c[i - k + n];
        }
    }
}

int main(int argc,char** argv)
{
    scanf("%d",&n);
    dfs(1);
    printf("%d\n",res);
    return 0;
}