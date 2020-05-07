#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define ns namespace
#define lol long long
using ns std;

int k, res;

int eu(int n)
{
    int ans = n;
    if (!n) return 0;
    if (!(n % 2))
    {
        while (!(n % 2))
            n /= 2;
        ans /= 2;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        if (!(n % i))
        {
            while (!(n % i))
                n /= i;
            ans = ans / i * (i - 1);
        }
    }
    if (n > 1)
        ans = ans / n * (n - 1);
    return ans;
}
int main(int argc, char **argv)
{
    cin >> k;
    if(k == 1) {cout << 0 << endl;return 0;}
    for (int i = 2; i < k; i++)
        res += eu(i);
    cout << res * 2 + 3 << endl;
    return 0;
}