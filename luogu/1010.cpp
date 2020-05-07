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

void print(int x)
{
    if(!x) return;
    if(x == 2)
    {
        printf("2");
        return;
    }
    if(x == 1)
    {
        printf("2(0)");
        return;
    }
    for(int i = 16;i >= 0;i--)
    {
        if(x & (1 << i))
        {
            if(i == 1) 
            {
                printf("2");
                if(x != (1 << i)) printf("+");
            }
            else if(i == 0) 
            {
                printf("2(0)");
            }
            else 
            {
                printf("2(");
                print(i);
                printf(")");
                if(x != (1 << i)) printf("+");
            }
            x -= (1 << i);
        }
    }
}

int main(int argc,char** argv)
{
    scanf("%d",&n);
    print(n);
    return 0;
}