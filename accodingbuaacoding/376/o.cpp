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
double a[23333],l,r;

int main(int argc,char** argv)
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) scanf("%lf",&a[i]);
    l = 0.0;r = 998244353.0;
    while(r - l > 1e-8)
    {
        int cnt = 0;
        double mid = (l + r) / 2;
        for(int i = 1;i <= n;i++)
        {
            cnt += (int)(a[i] / mid);
        }
        if(cnt >= m + 1) l = mid;
        else r = mid;
    }
    printf("%f",l);
    return 0;
}