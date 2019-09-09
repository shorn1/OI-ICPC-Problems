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

int n;
char s[233];

int main(int argc,char** argv)
{
    scanf("%d",&n);
    scanf("%s",s);
    int len = strlen(s);
    for(int i = 0;i < len;i++)
    {
        s[i] += n;
        if(!islower(s[i])) s[i] -= 26;
    }
    puts(s);
    return 0;
}