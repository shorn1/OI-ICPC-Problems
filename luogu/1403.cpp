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

lol res,n;

int main(int argc,char** argv)
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        res += n / i;
    }
    cout << res;
    return 0;
}