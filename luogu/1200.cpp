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

int x = 1,y = 1;
char a[233],b[233];

int main(int argc,char** argv)
{
    scanf("%s",a);
    scanf("%s",b);
    int l1 = strlen(a);
    int l2 = strlen(b);
    for(int i = 0;i < l1;i++) 
    {
        x *= a[i] - 'A' + 1;
        x %= 47;
    }
    for(int i = 0;i < l2;i++) 
    {
        y *= b[i] - 'A' + 1;
        y %= 47;
    }
    if(x == y) puts("GO");
    else puts("STAY");
    return 0;
}