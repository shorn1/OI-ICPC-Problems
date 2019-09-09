#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#define ns namespace
#define lol long long
using ns std;

const lol mo = 998244353;
unordered_set<lol> s;
int n,m;


int main(int argc,char** argv)
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        lol tmp,hs = 0;
        for(int j = 1;j <= m;j++)
        {
            scanf("%lld",&tmp);
            hs = (hs * 10 % mo + tmp % mo) % mo;
        }
        if(s.find(hs) == s.end())
        {
            puts("YES");
            s.insert(hs);
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}