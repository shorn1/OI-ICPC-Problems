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

int n,m;
int r = 1,s;

int main(int argc,char** argv)
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        int a;
        scanf("%d",&a);
        if(s + a > m)
        {
            r++;
            s = a;
        }
        else
        {
            s += a;
        }
    }
    cout << r;
    return 0;
}