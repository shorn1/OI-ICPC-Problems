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

int main(int argc,char** argv)
{
    cin >> n;
    if(n & 1) puts("NO");
    else puts("YES");
    return 0;
}