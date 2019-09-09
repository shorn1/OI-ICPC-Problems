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
int a[100],t,k;
int main()
{
    while(scanf("%d",&a[k]) > 0)
    {
        ++k;


    }
    sort(a,a+k);
    for(int i=0;i<k;i++)
    {
        t = i%2 ? t-a[i] : t+a[i];

    }
    cout << t << endl;
    return 0;
}