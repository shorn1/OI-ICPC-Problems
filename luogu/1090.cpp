#include<bits/stdc++.h>

#define ns namespace
#define lol long long
using ns std;

int n;
int a[23333];
lol r;
priority_queue<int, vector<int>, greater<int> > q;

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        q.push(a[i]);
    }
    while(q.size() > 1)
    {
        int t = q.top(); q.pop();
        t += q.top(); q.pop();
        r += t;
        q.push(t);
    }
    cout << r;
    return 0;
}