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

int n,k;
int f[233333];
const int mo = 100003;

int main(int argc,char** argv)
{
    cin >> n >> k;
    
    for(int i = 1;i <= k;i++) f[i] = 1;

    for(int i = 1;i < n;i++)
    {
        for(int j = i + 1;j <= n && j <= i + k;j++)
        {
            f[j] += f[i];
            f[j] %= mo;
        }
    }
    cout << f[n];
    return 0;
}