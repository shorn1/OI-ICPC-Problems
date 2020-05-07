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

char c,s[111111];
int n,w,l;

int main(int argc,char** argv)
{
    while(1)
    {
        c = getchar();
        if(!isalpha(c)) continue;
        if(c == 'E') break;
        if(c == 'W') ++w;
        else ++l;
        if((w >= 11 && w - l >= 2) || (l >= 11 && l - w >= 2))
        {
            printf("%d:%d\n",w,l);
            w = l = 0;
        }
        s[n++] = c;
    }
    printf("%d:%d\n",w,l);
    w = l = 0;
    puts("");
    for(int i = 0;i < n;i++)
    {
        if(s[i] == 'W') ++w;
        else ++l;
        if((w >= 21 && w - l >= 2) || (l >= 21 && l - w >= 2))
        {
            printf("%d:%d\n",w,l);
            w = l = 0;
        }
    }
    printf("%d:%d\n",w,l);
    return 0;
}