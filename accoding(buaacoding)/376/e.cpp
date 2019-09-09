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
lol a[233333],d,bo;

int main(int argc,char** argv)
{
    cin >> n;
    for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
    lol d = a[2] - a[1];
    for(int i = 3;i <= n;i++)
    {
        if(a[i] - a[i-1] != d) 
        {
            bo = 1;
            break;
        }
    }
    if(bo)
    {
        printf("%lld 1",a[1]);
    }
    else
    {
        printf("%lld %lld", a[1],d);
    }
    return 0;
}