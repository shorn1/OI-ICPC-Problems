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

int n,k,res;

inline int lowbit(int x){return x & -x;}

int main(int argc,char** argv)
{
    cin >> n >> k;
    while(__builtin_popcount(n) > k)
    {
        res += lowbit(n);
        n += lowbit(n);
    }
    cout << res << endl;
    return 0;
}