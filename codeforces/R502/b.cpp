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

const int M = 111111;

int n;
int a[M],b[M];
lol c1,c2,c3,c4;
char s[M];

int main(int argc,char** argv)
{
    cin >> n;
    scanf("%s",s);
    for(int i=1;i<=n;i++)
    {
        a[i] = s[i-1] - '0'; 
    }
    scanf("%s",s);
    for(int i=1;i<=n;i++)
    {
        b[i] = s[i-1] - '0'; 
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i] && !(b[i])) c1++;
        if(!(a[i]) && !(b[i])) c3++;
        if(!a[i]) c2++;
        if(a[i]) c4++;
    }
    cout << (c1 * (c2 - c3) + c3 * c4);
    return 0;
}