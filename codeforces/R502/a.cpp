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

struct stu
{
    int sc,id;
    bool operator < (const stu a) const
    {
        return (this -> sc == a.sc ?  this -> id < a.id : this -> sc > a.sc);
    }
}s[2333];

int n;

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int t = 0,sum = 0;
        for(int j=1;j<=4;j++)
        {
            scanf("%d",&t);
            sum += t;
        }
        s[i].id = i;
        s[i].sc = sum;
    }
    sort(s + 1,s + 1 + n);
    for(int i=1;i<=n;i++)
    {
        if(s[i].id == 1)
        {
            printf("%d",i);
            return 0;
        }
    }
    return 0;
}