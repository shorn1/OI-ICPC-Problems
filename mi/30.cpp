#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ns namespace
#define lol long long
#define u32 unsigned int
using ns std;
u32 a,b;
u32 bi[66];
int main()
{
    scanf("%u",&a);
    bi[0] = 1;
    for(int i=1;i<=32;i++)
    {
        bi[i] = bi[i-1] << 1;
    }
    for(int i=0;i<32;i++)
    {
        b += (((a & bi[i]) == bi[i]) * bi[31-i]); 
        //printf("%u\n",b);
    }
    printf("%u\n",b);
    return 0;
}