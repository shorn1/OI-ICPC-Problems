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

lol a,b;

int main(int argc,char** argv)
{
    cin >> a >> b;
    cout << a * b - a - b;
    return 0;
}