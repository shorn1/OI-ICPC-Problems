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
    if(n % 3 == 0)
    {
        printf("YES\n1 1 %d",n - 2);
    }
    else if(n % 3 == 1)
    {
        printf("YES\n1 1 %d",n - 2);
    }
    else if(n % 3 == 2)
    {
        printf("YES\n1 2 %d",n - 3);
    }
    return 0;
}