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

const int M = 23333;

struct pe
{
    int a,b,d;
    bool operator <(const pe &x) const
    {
        if(d != x.d) return d < x.d;
        if(d <= 0) return a < x.a;
        return b > x.b;
    }
}p[M];

int n,T;
lol res,sum;

int main(int argc,char** argv)
{
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--)
    {
        cin >> n;
        res = sum = 0LL;
        for(int i = 1;i <= n;i++)
        {
            cin >> p[i].a >> p[i].b;
            if(p[i].a > p[i].b) p[i].d = 1;
            else if(p[i].a == p[i].b) p[i].d = 0;
            else p[i].d = -1;
        }
        sort(p + 1,p + 1 + n);
        for(int i = 1;i <= n;i++)
        {
            sum += p[i].a;
            res = max(res,sum) + p[i].b;
        }
        cout << res << endl;
    }
    return 0;
}