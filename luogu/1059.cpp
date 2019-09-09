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
vector<int> v;

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        int t;
        scanf("%d",&t);
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    auto it = unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
    printf("%d\n",v.size());
    for(auto &i : v)
    {
        printf("%d ",i);
    }
    return 0;
}