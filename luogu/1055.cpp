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

char s1[233],s2[233];
int r = 0;

int main(int argc,char** argv)
{
    scanf("%s",s1);
    int l1 = 13,l2 = 10,j = 0;
    for(int i = 0;i < l1;i++)
    {
        if(isdigit(s1[i]) || s1[i] == 'X') s2[j++] = s1[i];
    }
    for(int i = 0;i < l2 - 1;i++)
    {
        r += (s2[i] - '0') * (i + 1);
    }
    r %= 11;
    
    if(r == s2[9] - '0' || (r == 10 && s2[9] == 'X'))
    {
        puts("Right");
    }
    else
    {
        for(int i = 0;i < l1 - 1;i++) putchar(s1[i]);
        if(r != 10) putchar(r + '0');
        else putchar('X');
    }
    return 0;
}