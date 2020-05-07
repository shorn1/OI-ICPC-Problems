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

const int M = 6666;

int n;
vector<int> v;

struct wd
{
    int l,w;
    bool operator < (const wd &a) const
    {
        return l == a.l ? w > a.w : l > a.l;
    }
}a[M];

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d%d",&a[i].l,&a[i].w);
    }
    sort(a,a + n);
    v.push_back(a[0].w);
    for(int i = 1;i < n;i++)
    {
        if(a[i].w > v.back()) v.push_back(a[i].w);
        else
        {
            v[lower_bound(v.begin(),v.end(),a[i].w) - v.begin()] = a[i].w;
        }
    }
    printf("%d\n",v.size());
    return 0;
}