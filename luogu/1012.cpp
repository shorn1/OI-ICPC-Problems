#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>

#define ns namespace
#define lol long long
using ns std;

int n;
string s[23];

bool cmp(const string &a,const string &b) 
{
    return a + b > b + a;
}

int main(int argc,char** argv)
{
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> s[i];
    }
    sort(s,s + n,cmp);
    for(int i = 0;i < n;i++)
    {
        cout << s[i];
    }
    return 0;
}