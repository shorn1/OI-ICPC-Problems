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

lol n,cnt,tmp;

int main(int argc,char** argv)
{
    cin >> n;
    while(n / 5 > 0)
    {        
        cnt += n / 5;
        n /= 5;
    }
    cout << cnt;
    return 0;
}