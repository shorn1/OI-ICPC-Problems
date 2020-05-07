#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAX = 110;
class CHugeInt
{
public:
    char s[505];
    CHugeInt()
    {
        memset(s, 0, sizeof(s));
    }
    CHugeInt(char w[])
    {
        memcpy(s, w, sizeof(s));
    }
    CHugeInt(int a)
    {
        memset(s, 0, sizeof(s));
        int i, j = 0;
        char ch;
        while (a)
        {
            s[j++] = a % 10 + '0';
            a /= 10;
        }
        for (i = 0, --j; i < j; ++i, --j)
        {
            ch = s[i];
            s[i] = s[j];
            s[j] = ch;
        }
    }

    friend ostream &operator<<(ostream &o, CHugeInt a)
    {
        o << a.s;
        return o;
    }

    friend CHugeInt operator+(const CHugeInt &a, const CHugeInt &b)
    {
        CHugeInt c;
        int i, j, i1, i2, tmp, carry;
        int len1 = strlen(a.s), len2 = strlen(b.s);
        char ch;
        i1 = len1 - 1;
        i2 = len2 - 1;
        j = carry = 0;
        for (; i1 >= 0 && i2 >= 0; ++j, --i1, --i2)
        {
            tmp = a.s[i1] - '0' + b.s[i2] - '0' + carry;
            carry = tmp / 10;
            c.s[j] = tmp % 10 + '0';
        }
        while (i1 >= 0)
        {
            tmp = a.s[i1--] - '0' + carry;
            carry = tmp / 10;
            c.s[j++] = tmp % 10 + '0';
        }
        while (i2 >= 0)
        {
            tmp = b.s[i2--] - '0' + carry;
            carry = tmp / 10;
            c.s[j++] = tmp % 10 + '0';
        }
        if (carry)
            c.s[j++] = carry + '0';
        c.s[j] = '\0';
        for (i = 0, --j; i < j; ++i, --j)
        {
            ch = c.s[i];
            c.s[i] = c.s[j];
            c.s[j] = ch;
        }
        return c;
    }

    friend CHugeInt& operator+=(CHugeInt &a, const CHugeInt &b)
    {
        CHugeInt c = a + b;
        a = c;
        return a;
    }

    friend CHugeInt& operator++(CHugeInt &a)
    {
        CHugeInt c = a + 1;
        a = c;
        return a;
    }

    friend CHugeInt operator++(CHugeInt &a,int)
    {
        CHugeInt c = a;
        a = c + 1;
        return c;
    }
   
};

int main()
{
    char s[210];
    int n;

    while (cin >> s >> n)
    {
        CHugeInt a(s);
        CHugeInt b(n);
        //printf("%s\n",b.s);
        cout << a + b << endl;
        cout << n + a << endl;
        cout << a + n << endl;
        b += n;     
        cout << ++b << endl;        
        cout << b++ << endl;
        cout << b << endl;
        
    }

    return 0;
}