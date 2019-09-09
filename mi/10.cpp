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
lol ans;
lol geta(int t)
{
    if(t < 1) return 0LL;
    if(t==1) return 1LL;
    if(t==2) return 2LL;
    return geta(t-1) + geta(t - 2); 

}

int main()
{
    scanf("%d",&n);
    ans = geta(n);
    cout << ans << endl;
    return 0;
}