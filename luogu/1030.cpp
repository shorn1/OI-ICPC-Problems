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

int len;
char s1[23],s2[23];

void dfs(int l1,int r1,int l2,int r2)
{
    if(r1 - l1 >= 0)
    {
        for(int i = 0;i < len;i++)
        {
            if(s1[i] == s2[r2])
            {
                printf("%c",s2[r2]);
                dfs(l1,i - 1,l2,l2 + i - l1 - 1);
                dfs(i + 1,r1,l2 + i - l1,r2 - 1);
            }
        }
    }
}

int main(int argc,char** argv)
{
    scanf("%s%s",s1,s2);
    len = strlen(s1);
    dfs(0,len - 1,0,len - 1);
    return 0;
}