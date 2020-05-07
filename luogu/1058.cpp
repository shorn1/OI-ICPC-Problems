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

const int M = 55,N = 1111;
int m,n,a[M][M],mm,mn;
char s[N][N];
const char e[11][11] = {
"  +---+",
" /   /|",
"+---+ |",
"|   | +",
"|   |/",
"+---+",
};
const int st[] = {2,1,0,0,0,0};
const int ed[] = {6,6,6,6,5,4};

void f(int x,int y)
{
    for(int i = 0;i < 6;i++)
        for(int j = st[i];j <= ed[i];j++)
        {
            s[x + 5 - i][y + j] = e[i][j];
            mm = max(mm,x + 5 - i);
            mn = max(mn,y + j);
        }
}

int main(int argc,char** argv)
{
    scanf("%d%d",&m,&n);
    for(int i = 1;i <= m;i++)
        for(int j = 1;j <= n;j++)
            scanf("%d",&a[i][j]);
    for(int i = 1;i <= m;i++)
        for(int j = 1;j <= n;j++)
            for(int k = 1;k <= a[i][j];k++)
                f(2 * (m - i) + 3 * k + 1,4 * (j - 1) + 2 * (m - i) + 1);
    for(int i = mm;i >= 1;i--)
    {
        int bo = 0;
        for(int j = 1;j <= mn;j++)
        {
            if(s[i][j]) bo = 1;
        }
        if(!bo) break;
        for(int j = 1;j <= mn;j++)
        {
            printf("%c",s[i][j] ? s[i][j] : '.');
        }
        printf("\n");
    }
    return 0;
}