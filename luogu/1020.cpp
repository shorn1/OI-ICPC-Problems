#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int k;
vector<int> a,d1,d2;

int main(int argc,char** argv)
{
    while(scanf("%d",&k) > 0) a.pb(k);
    d1.pb(a[0]);d2.pb(a[0]);
    for(int i = 1;i < a.size();i++)
        if(a[i] <= d1.back()) d1.pb(a[i]);
        else d1[upper_bound(d1.begin(),d1.end(),a[i],greater<int>()) - d1.begin()] = a[i];
    for(int i = 1;i < a.size();i++)
        if(a[i] > d2.back()) d2.pb(a[i]);
        else d2[lower_bound(d2.begin(),d2.end(),a[i]) - d2.begin()] = a[i];
    printf("%d\n%d\n",d1.size(),d2.size());
    return 0;
}