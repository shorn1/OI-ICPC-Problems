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

int n,r[111111],res;

int main(int argc,char** argv)
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 2 * i;j <= n;j += i)
            r[j]++;
    }
    for(int i = 1;i <= n;i++) res += r[i];
    //for(int i = 1;i <= n;i++) cout << r[i] << ' ';
    cout << res + n;
    return 0;
}