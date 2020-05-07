#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

#define ns namespace
#define lol long long
using ns std;

map<string,int> m;
vector<int> v;
string s;

int main(int argc,char** argv)
{
    m["one"]=1;m["two"]=2;m["three"]=3;m["four"]=4;m["five"]=5;m["six"]=6;m["seven"]=7;m["eight"]=8;m["nine"]=9;m["ten"]=10;m["eleven"]=11;m["twelve"]=12;m["thirteen"]=13;m["fourteen"]=14;m["fifteen"]=15;m["sixteen"]=16;m["seventeen"]=17;m["eighteen"]=18;m["nineteen"]=19;m["twenty"]=20;m["a"]=1;m["both"]=2;m["another"]=1;m["first"]=1;m["second"]=2;m["third"]=3;
    for(int i = 1;i <= 6;i++)
    {
        cin >> s;
        for(int j = 0;j < s.length();j++)
        {
            if(s[j] == '.') s.resize(j);
        }
        if(m[s])
        {
            int t = m[s] * m[s] % 100;
            if(t) v.push_back(t);            
        }
    }
    if(!v.size()) 
    {
        printf("0");return 0;
    }
    sort(v.begin(),v.end());
    printf("%d",v[0]);
    for(int i = 1;i < v.size();i++)
    {
        if(v[i] < 10) printf("0");
        printf("%d",v[i]);
    }
    return 0;
}