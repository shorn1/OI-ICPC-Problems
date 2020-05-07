#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define ns namespace
#define lol long long
using ns std;

int n;
vector<lol> v;

int main(int argc,char** argv)
{
    while (scanf("%d",&n) > 0)
    {
        v.clear();
        for(int i = 1;i <= n;i++)
        {
            lol t;
            scanf("%lld",&t);
            v.push_back(t);
        }
        sort(v.begin(),v.end());
        for(auto &i:v)
        {
            printf("%lld ",i);
        }
        printf("\n");
    }
    
    return 0;
}