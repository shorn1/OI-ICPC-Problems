#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<deque>

#define ns namespace
#define lol long long
using ns std;


deque<int> q;
int m;

int main(int argc,char** argv)
{
    scanf("%d",&m);
    for(int i = 1;i <= m;i++)
    {
        int op,x;
        scanf("%d",&op);
        if(op == 1)
        {
            scanf("%d",&x);
            q.push_back(x);
        }
        else if(op == 2)
        {
            scanf("%d",&x);
            q.push_front(x);
        }
        else if(op == 3)
        {
            if(q.empty())
            {
                puts("error");
            }
            else
            {
                printf("%d\n",q.front());
                q.pop_front();
            }
        }
        else if(op == 4)
        {
            scanf("%d",&x);
            int bo = 0;
            for(auto it = q.begin();it != q.end();++it)
            {
                if(*it == x)
                {
                    q.erase(it);
                    bo = 1;
                    break;
                }
            }
            if(!bo)
            {
                puts("error");
            }
        }
        else
        {
            printf("%d\n",q.size());
        }
    }
    if(!q.size())
    {
        puts("null");
    }
    else
    {
        for(auto &i : q)
            printf("%d ",i);
    }
    return 0;
}