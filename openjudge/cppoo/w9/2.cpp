#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>

#define ns namespace
#define lol long long
using ns std;

int n,id,p;
map<int,int> mp;

int main(int argc,char** argv)
{
    scanf("%d",&n);
    mp.insert(make_pair(1000000000,1));
    for(int i = 0;i < n;i++)
    {
        int d1,d2;
        d1 = d2 = 2111111111;
        scanf("%d%d",&id,&p);
        auto it1 = mp.insert(make_pair(p,id)).first;
        auto it2 = it1;
        if(it1 != mp.begin())
        {
            --it1;
            d1 = p - it1->first;
        }
        ++it2;
        if(it2 != mp.end())
        {
            d2 = it2->first - p;
        }
        if(d1 <= d2)
        {
            printf("%d %d\n",id,it1->second);
        }
        else
        {
            printf("%d %d\n",id,it2->second);
        }
    }
    return 0;
}