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

int m;

int main(int argc,char** argv)
{
    cin >> m;
    for(int i = 1; i <= m / 2;i++)
    {
        lol s = 0LL;
        for(int j = i;j <= m;j++)
        {
            s += j;
            if(s == m)
            {
                printf("%d %d\n",i,j);
            }
            if(s > m) break; 
        }
    }
    return 0;
}