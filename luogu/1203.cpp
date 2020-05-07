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

const int M = 1111;
const char s1[] = "rrbb";
const char s2[] = "brrb";
int n,res,r;
char s[M];

int main(int argc,char** argv)
{
    scanf("%d%s",&n,s);
    strncpy(s + n,s,n);
    for(int i = 0;i < n;i++)
    {
        for(int k = 0;k < 4;k++)
        {
            r = 0;
            for(int j = i;j < i + n;j++)
            {
                if(s[j] == s1[k] || s[j] == 'w') r++;
                else break;
            }
            for(int j = i + n - 1;j >= i;j--)
            {
                if(s[j] == s2[k] || s[j] == 'w') r++;
                else break;
            }
            res = max(res,r);    
        }
    }
    res = min(res,n);
    printf("%d\n",res);
    return 0;
}