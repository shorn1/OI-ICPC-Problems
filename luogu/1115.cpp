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

int n;
int a,r[233333],res = -998244353;

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a);
        r[i] = max(a,r[i - 1] + a);
        res = max(res,r[i]);
    }
    printf("%d\n",res);
    return 0;
}