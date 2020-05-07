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

int cd[4][22];

int chk()
{
    
    for(int i = 1;i <= 3;i++)
    {
        int b1 = 1,b2 = 0;
        for(int j = 2;j <= 8;j++)
        {
            if(cd[i][j] < 1) b1 = 0;
        }
        if(cd[i][1] < 3 || cd[i][9] < 3) b1 = 0;
        for(int j = 2;j <= 8;j++)
        {
            if(cd[i][j] > 1) b2 = 1;
        }
        if(cd[i][1] > 3 || cd[i][9] > 3) b2 = 1;
        if(b1 && b2) return 1;
    }
    return 0;
}

int main(int argc,char** argv)
{
    for(int i = 1;i <= 13;i++)
    {
        int k;
        char t;
        scanf("%1d%c",&k,&t);
        switch(t)
        {
            case 'm': cd[1][k]++;break;
            case 's': cd[2][k]++;break;
            case 'p': cd[3][k]++;break;
        }
    }
    while(getchar() != '\n');
    for(int i = 1;i <= 17;i++)
    {
        int k;
        char t;
        scanf("%1d%c",&k,&t);
        switch(t)
        {
            case 'm': cd[1][k]++;break;
            case 's': cd[2][k]++;break;
            case 'p': cd[3][k]++;break;
        }
        if(chk()) 
        {
            printf("%d\n",i);
            return 0;
        }
    }
    puts("Stop Your Daydream!");
    return 0;
}