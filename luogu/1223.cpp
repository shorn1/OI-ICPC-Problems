#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<utility>

#define ns namespace
#define lol long long
using ns std;

pair<int,int> a[2333];
int n;
double sum;

int main(int argc,char** argv)
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i].first);
        a[i].second = i;
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;i++)
    {
        sum += a[i].first * (n - i);
        printf("%d ",a[i].second);
    }
    printf("\n%.2f",sum / n);
    return 0;
}