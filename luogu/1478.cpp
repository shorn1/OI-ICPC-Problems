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

const int M = 6666;
int n,s,a,b,res;

struct ap
{
    int x,y;
    bool operator <(const ap &c) const
    {
        return y < c.y;
    }
}aa[M];

int main(int argc,char** argv)
{
    scanf("%d%d%d%d",&n,&s,&a,&b);
    for(int i = 1;i <= n;i++) scanf("%d%d",&aa[i].x,&aa[i].y);
    sort(aa + 1, aa + 1 + n);
    for(int i = 1;i <= n;i++) 
    {
        if(a + b >= aa[i].x && s >= aa[i].y)
        {
            res++;
            s -= aa[i].y;
        }
    }
    printf("%d\n",res);
    return 0;
}