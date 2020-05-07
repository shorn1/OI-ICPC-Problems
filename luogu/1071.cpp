#include<bits/stdc++.h>

#define ns namespace
#define lol long long
using ns std;

string s1,s2,s3;
map<char,char> m1,m2;

int main(int argc,char** argv)
{
    cin >> s1 >> s2 >> s3;
    for(int i = 0;i < s1.length();i++)
    {
        if((m1[s1[i]] && m1[s1[i]] != s2[i]) || (m2[s2[i]] && m2[s2[i]] != s1[i])) {cout << "Failed" << endl; return 0;}
        else 
        {
            m1[s1[i]] = s2[i];
            m2[s2[i]] = s1[i];
        }
    }
    for(int i = 0;i < 26;i++)
    {
        if(!m1[s1[i]]) {cout << "Failed" << endl; return 0;}
    }
    for(int i = 0;i < s3.length();i++)
    {
        cout << m1[s3[i]];
    }
    return 0;
}