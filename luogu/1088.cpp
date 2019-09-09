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

int n,m;
int a[23333];

int main(int argc,char** argv)
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 1;i <= m;i++)
        next_permutation(a + 1,a + 1 + n);
    for(int i = 1;i <= n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}