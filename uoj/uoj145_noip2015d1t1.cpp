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

int n,lx,ly;
const int M = 55;
int a[M][M];

int main(int argc,char** argv)
{
    cin >> n;
    a[1][n / 2 + 1] = 1;
    lx = 1;ly = n / 2 + 1;
    for(int i = 2;i <= n * n;i++)
    {
        if(lx == 1 && ly != n)
        {
            a[n][ly + 1] = i;
            lx = n;ly = ly + 1;
        }
        else if(lx != 1 && ly == n)
        {
            a[lx - 1][1] = i;
            lx = lx - 1;ly = 1;
        }
        else if(lx == 1 && ly == n)
        {
            a[lx + 1][ly] = i;
            lx++;
        }
        else
        {
            if(!a[lx - 1][ly + 1])
            {
                a[lx - 1][ly + 1] = i;
                lx = lx - 1;ly = ly + 1;
            }
            else
            {
                a[lx + 1][ly] = i;
                lx++;
            }
        }
    }  
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++) printf("%d ",a[i][j]);
        puts("");
    }
    return 0;
}