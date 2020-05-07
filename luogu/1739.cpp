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

char s[2333];
int k,l;

int main(int argc,char** argv)
{
    scanf("%s",s);
    l = strlen(s);
    for(int i = 0;i < l;i++)
    {
        if(s[i] == '(') k++;
        if(s[i] == ')')
        {
            if(k > 0) k--;
            else 
            {
                puts("NO");
                return 0;
            }
        }
    }
    if(k) puts("NO");
    else puts("YES");
    return 0;
}