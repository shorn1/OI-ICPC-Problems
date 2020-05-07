#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<list>

#define ns namespace
#define lol long long
using ns std;

int n;
list<int> l[11111];
char buf[111];

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%s",buf);
        int a,b;
        if(buf[0] == 'n')
        {
            scanf("%d",&a);
        }
        if(buf[0] == 'a')
        {
            scanf("%d%d",&a,&b);
            l[a].push_back(b);
        }
        if(buf[0] == 'm')
        {
            scanf("%d%d",&a,&b);
            l[a].merge(l[b]);
        }
        if(buf[0] == 'u')
        {
            scanf("%d",&a);
            l[a].sort();
            l[a].unique();
        }
        if(buf[0] == 'o')
        {
            scanf("%d",&a);
            l[a].sort();
            for(auto &t:l[a])
            {
                printf("%d ",t);
            }
            printf("\n");
        }
    }
    return 0;
}