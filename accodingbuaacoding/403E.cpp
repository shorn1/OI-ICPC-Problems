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

lol k;

lol com(lol n, lol r)
{
    if(n - r > r ) r = n - r; 
    lol i, j, s = 1;
    for( i = 0, j = 1; i < r; ++i )
    {
        s *= (n - i);
        for( ; j <= r && s % j == 0; ++j ) s /= j;
    }
    return s;
}

int main(int argc,char** argv)
{
    cin >> k;
    cout << com(2 * k ,k) / (k + 1);
    return 0;
}