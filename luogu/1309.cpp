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

const int M = 233333;
int n,r,q;

struct pl
{
    int s,w,num;
    pl(int _s = 0,int _w = 0,int _num = 0){s = _s;w = _w;num = _num;}
    bool operator < (const pl& a) const
    {
        return s != a.s ? s > a.s : num < a.num;
    }
};
pl p[M],wi[M],lo[M];

int main(int argc,char** argv)
{
    scanf("%d%d%d",&n,&r,&q);
    for(int i = 1;i <= 2 * n;i++)
    {
        scanf("%d",&p[i].s);
        p[i].num = i;
    }
    for(int i = 1;i <= 2 * n;i++)
    {
        scanf("%d",&p[i].w);
    }
    sort(p + 1,p + 1 + n * 2);

    //for(int j = 1;j <= 2 * n;j++) printf("No%d:%d ",p[j].num,p[j].s);

    for(int i = 1;i <= r;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            int p1 = j * 2 - 1, p2 = j * 2;
            if(p[p1].w > p[p2].w) 
            {
                p[p1].s++;
                wi[j] = p[p1];
                lo[j] = p[p2];
            }
            else
            {
                p[p2].s++;
                wi[j] = p[p2];
                lo[j] = p[p1];
            }
        }
        int i1 = 1,i2 = 1;
        for(int j = 1;j <= 2 * n;j++)
        {            
            if(i1 > n)
            {
                p[j] = lo[i2];
                ++i2;
            }
            else if(i2 > n)
            {
                p[j] = wi[i1];
                ++i1;
            }
            else if(wi[i1] < lo[i2])
            {
                p[j] = wi[i1];
                ++i1;
            }
            else if(lo[i2] < wi[i1])
            {
                p[j] = lo[i2];
                ++i2;
            }
            //printf("No%d:%d ",p[j].num,p[j].s);
        }
        //puts("");
    }
    printf("%d\n",p[q].num);
    return 0;
}