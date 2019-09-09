#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>

#define ns namespace
#define lol long long
using ns std;

const int M = 233333;

int n;
int a[M];
set<int> s;
int res;

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }
    res = a[1];
    s.insert(a[1]);
    for(int i = 2;i <= n;i++)
    {
        int t = 998244353;
        if(s.find(a[i]) != s.end()) continue;
        auto it = s.insert(a[i]).first;
        if(it != s.begin())
        {
            t = a[i] - *(--it);
            ++it;
        }
        if(++it != s.end())
        {
            t = min(t,(*it) - a[i]);
        }
        res += t;
    }
    printf("%d",res);
    return 0;
}