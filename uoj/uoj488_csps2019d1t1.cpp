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

#define u64 unsigned long long

u64 n,k;

int main(int argc,char** argv)
{
    cin >> n >> k;
    k ^= k >> 1;
    for(u64 i = n;i > 0;i--)
        cout << (k >> (i - 1) & 1);
    cout << endl;
    return 0;
}