#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>

#define ns namespace
#define lol long long
using ns std;

int n;
char s[233],c;
map<int,int> ls,rs;

void dfs(int k)
{
    if(k != '*')
    {
        printf("%c",k);
        dfs(ls[k]);
        dfs(rs[k]);
    }
}

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%s",s);
        if(i == 1) c = s[0];
        ls[s[0]] = s[1];
        rs[s[0]] = s[2];
    }
    dfs(c);
    return 0;
}