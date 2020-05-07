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

int n,a;
set<int> v;
multiset<int> s;
char buf[111];

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%s%d",buf,&a);
        if(buf[1] == 'd')
        {
            v.insert(a);
            s.insert(a);
            printf("%d\n",s.count(a));
        }
        if(buf[1] == 'e')
        {
            printf("%d\n",s.count(a));
            while(s.count(a) > 0) s.erase(a);
        }
        if(buf[1] == 's')
        {
            printf("%d %d\n",v.count(a) ? 1 : 0,s.count(a));

        }
    }
    return 0;
}