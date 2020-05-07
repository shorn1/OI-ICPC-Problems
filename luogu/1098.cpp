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

int p1,p2,p3,len;
char s[2333];

void prt(int st,int ed)
{
    if(p3 == 1)
    {
        for(int i = st + 1;i <= ed - 1;i++)
        {
            for(int j = 1;j <= p2;j++)
            {
                if(p1 == 1) putchar(i);
                else if(p1 == 2)
                {
                    if(isalpha(i)) putchar(toupper(i));
                    else putchar(i);
                }
                else putchar('*');
            }
        }
    }
    else
    {
        for(int i = ed - 1;i >= st + 1;i--)
        {
            for(int j = 1;j <= p2;j++)
            {
                if(p1 == 1) putchar(i);
                else if(p1 == 2)
                {
                    if(isalpha(i)) putchar(toupper(i));
                    else putchar(i);
                }
                else putchar('*');
            }
        }
    }
}

int main(int argc,char** argv)
{
    cin >> p1 >> p2 >> p3;
    scanf("%s",s);
    len = strlen(s);
    putchar(s[0]);
    for(int i = 1;i < len - 1;i++)
    {
        if(s[i] == '-')
        {
            if(s[i-1] + 1 == s[i+1]) continue;
            else if(s[i-1] < s[i+1] && ((isdigit(s[i-1]) && isdigit(s[i+1])) || (isalpha(s[i-1]) && isalpha(s[i+1]))))
            {
                prt(s[i-1],s[i+1]);
            }
            else putchar(s[i]);
        }
        else putchar(s[i]);
    }
    putchar(s[len - 1]);
    return 0;
}