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

const int M = 23333;
int T,L,ans,xv,yv,res,wa,s1;
int stk1[1111],stk2[1111],vis[233];
char x[233],y[233],v;

void init()
{
    char tmp;
    scanf("%d O(%c",&L,&tmp);
    if(tmp == '1') {ans = 0;scanf("%*c");}
    else scanf("^%d)",&ans);
    memset(stk1,0,sizeof(stk1));
    memset(stk2,0,sizeof(stk2));
    memset(vis,0,sizeof(vis));
    res = 0;wa = 0;s1 = 0;
}

int main(int argc,char** argv)
{
    cin >> T;
    while(T--)
    {
        init();
        char t1;
        for(int i = 1;i <= L;i++)
        {
            do{scanf("%c",&t1);} while(!isalpha(t1));
            if(t1 == 'F')
            {
                scanf(" %c %s %s",&v,x,y);
                if(wa) continue;
                if(x[0] == 'n') xv = M; else xv = atoi(x);
                if(y[0] == 'n') yv = M; else yv = atoi(y);
                if(vis[v]) wa = 1;
                if(xv > yv)
                {
                    stk1[++s1] = -M;    
                }
                else if(yv - xv < 99)
                {    
                    stk1[s1 + 1] = stk1[s1];
                    ++s1;
                }
                else
                {
                    stk1[s1 + 1] = stk1[s1] + 1;
                    ++s1;
                }
                stk2[s1] = v;
                ++vis[v];    
            }
            else
            {                
                if(s1 < 1) wa = 1;                
                if(wa) continue;
                res = max(res,stk1[s1]);
                --vis[stk2[s1]];
                stk1[s1] = 0;                
                stk2[s1] = 0;
                --s1;
            }
        }
        if(s1) wa = 1;
        if(wa) puts("ERR");
        else if(res == ans) puts("Yes");
        else puts("No");
    }
    return 0;
}