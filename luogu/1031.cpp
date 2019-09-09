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

int n,ave,ans;
int a[2333];

int main(int argc,char** argv)
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        ave += a[i];
    }
    ave /= n;
    for(int i = 1;i < n;i++)
    {
        if(a[i] > ave) 
        {
            a[i+1] += (a[i] - ave);
            ans ++;
        }
        else if(a[i] < ave) 
        {
            a[i+1] -= (ave - a[i]);
            ans ++;
        }
    }
    cout << ans;
    return 0;
}