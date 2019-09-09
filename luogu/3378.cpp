#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>

#define ns namespace
#define lol long long
using ns std;

__gnu_pbds::priority_queue<int, greater<int> > q;
int n;

int main(int argc,char** argv)
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        int op;
        scanf("%d",&op);
        if(op == 1)
        {
            int x;
            scanf("%d",&x);
            q.push(x);
        }
        else if(op == 2)
        {
            printf("%d\n",q.top());
        }
        else
        {
            q.pop();
        }
    }
    return 0;
}