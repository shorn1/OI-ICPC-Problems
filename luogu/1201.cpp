#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>

#define ns namespace
#define lol long long
using ns std;

int n,a,g;
string s[111],t,tar;
map<string,int> m;

int main(int argc,char** argv)
{
    cin >> n;
    for(int i = 1;i <= n;i++) 
    {
        cin >> s[i];
        m[s[i]] = 0;
    }
    for(int i = 1;i <= n;i++) 
    {
        cin >> t >> a >> g;
        m[t] += a;
        int sum = a;
        for(int j = 1;j <= g;j++)
        {
            cin >> tar;
            m[tar] += a / g;
            sum += a / g;
        }
        m[t] -= sum;
    }
    for(int i = 1;i <= n;i++) 
    {
        cout << s[i] << ' ' << m[s[i]] << endl;
    }
    return 0;
}