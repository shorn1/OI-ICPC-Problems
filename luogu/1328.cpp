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

int n,na,nb,ra,rb;
int a[2333],b[2333];

int chk(int x,int y)
{
    int k = 1;
    if(x == y) return 0;
    if(x > y) 
    {
        swap(x,y);
        k = -1;
    }
    switch(x)
    {
        case 0:
        {
            switch(y)
            {
                case 1: return -1 * k;
                case 2: return 1 * k;
                case 3: return 1 * k;
                case 4: return -1 * k;
            }
        }
        case 1:
        {
            switch(y)
            {
                case 2: return -1 * k;
                case 3: return 1 * k;
                case 4: return -1 * k;
            }
        }
        case 2:
        {
            switch(y)
            {
                case 3: return -1 * k;
                case 4: return 1 * k;
            }
        }
        default: return k;
    }
}

int main(int argc,char** argv)
{
    scanf("%d%d%d",&n,&na,&nb);
    for(int i = 0;i < na;i++)
        scanf("%d",&a[i]);
    for(int i = 0;i < nb;i++)
        scanf("%d",&b[i]);
    for(int i = 0;i < n;i++)
    {
        int t = chk(a[i % na],b[i % nb]);
        if(t > 0) ra++;
        else if(t < 0) rb++;
    }
    printf("%d %d",ra,rb);
    return 0;
}