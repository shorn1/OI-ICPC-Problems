#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cctype>
#define lol long long
#define ns namespace
using namespace std;
int n, m, curc;
char cd[233333];
bool rr = false;
struct Pig
{
    char h[23333]; // cards
    int jmp;       // jump to a side
    int wp;        // weapon
    int ty;        // type
    int lc;        //  l pos of the last card available
    int rc;        //  r pos of the last card
    int ded;       // whether dead
    int usek;      // use a kill
    int hp;        // hp
} p[23];
void dcard(int, int); // draw card
void ucard(int, int); // use card
void roundst(int);    // start a round
void pans();          // print answer
bool chkr();          // check if game ends
int chksd1(int, int); //check side
int chkde(int);       // check dead
void dea(int, int);   // dead
void jmpp(int, int);  // jump
int jd(int, int);     // jue dou
int chknw(int, char); // check nmrq/wjqf
void sread()
{
    scanf("%d%d\n", &n, &m);
    char tmp[6][6];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            scanf("%s", tmp[j]);
            if (j == 1)
            {
                if (tmp[j][0] == 'M')
                    p[i].ty = 1;
                else if (tmp[j][0] == 'Z')
                    p[i].ty = 2;
                else
                    p[i].ty = 3;
            }
            else
                p[i].h[j - 1] = (tmp[j][0] == ' ' || tmp[j][0] == '\n') ? tmp[j][1] : tmp[j][0];
        }
        p[i].hp = p[i].rc = 4;
        p[i].lc = 1;
        p[i].ded = p[i].jmp = p[i].wp = 0;
    }
    p[1].jmp = 1;
    for (int i = 1; i <= m; i++)
    {
        char c = getchar();
        while (!isalpha(c))
            c = getchar();
        cd[i] = c;
    }
    for (int i = m + 1; i <= 200000; i++)
        cd[i] = cd[m];
}
ns wx
{
    void jmp2(int pl, int tar, int ty)
    {
        if (p[tar].jmp == 1 || p[tar].ty == 1)
            p[pl].jmp = ty ? 1 : 3;
        if (p[tar].jmp == 3)
            p[pl].jmp = ty ? 3 : 1;
    }
    int chksd(int pl, int tar, int ty)
    {
        if (ty)
        {
            if (p[tar].jmp == 3 && p[pl].ty == 3)
                return 1;
            if (p[tar].jmp == 1 && p[pl].ty <= 2)
                return 1;
        }
        else
        {
            if (p[tar].jmp >= 2 && p[pl].ty == 1)
                return 1;
            if (p[tar].jmp == 3 && p[pl].ty <= 2)
                return 1;
            if (p[tar].jmp == 1 && p[pl].ty == 3)
                return 1;
        }
        return 0;
    }
    int askw(int tar, int beg, int ty)
    {
        int r = 0;
        for (int i = beg; i < beg + n; i++)
        {
            int usr = i > n ? i - n : i;
            if (p[usr].ded)
                continue;
            if (chksd(usr, tar, ty))
            {
                for (int j = p[usr].lc; j <= p[usr].rc; j++)
                {
                    if (p[usr].h[j] == 'J')
                    {
                        p[usr].h[j] = 'u';
                        if (!p[usr].jmp || p[usr].jmp == 2)
                            jmp2(usr, tar, ty);
                        r = askw(usr, usr, 0);
                        return !r;
                    }
                }
            }
        }
        return r;
    }
}
int chksd1(int pl, int tar)
{
    if (p[pl].ty == 3 && (p[tar].ty == 1 || p[tar].jmp == 1))
        return 1;
    if (p[pl].ty == 1 && (p[tar].jmp == 3 || p[tar].jmp == 2))
        return 1;
    if ((p[pl].ty == 1 || p[pl].ty == 2) && p[tar].jmp == 3)
        return 1;
    return 0;
}
int chkde(int pl)
{
    for (int i = p[pl].lc; i <= p[pl].rc; i++)
        if (p[pl].h[i] == 'P')
        {
            p[pl].h[i] = 'u';
            ++p[pl].hp;
            return 0;
        }
    p[pl].ded = 1;
    return 1;
}
void dea(int pl, int tar)
{
    for (int j = p[tar].lc; j <= p[tar].rc; j++)
        p[tar].h[j] = 'u';
    p[tar].wp = 0;
    if (p[pl].ty == 1 && p[tar].ty == 2)
    {
        for (int j = p[pl].lc; j <= p[pl].rc; j++)
        {
            p[pl].h[j] = 'u';
        }
        p[pl].wp = 0;
    }
    else if (p[tar].ty == 3)
        dcard(pl, 3);
}
void dcard(int pl, int tim)
{
    for (int i = 1; i <= tim; i++)
        p[pl].h[++p[pl].rc] = cd[++curc];
}
void jmpp(int pl, int tar)
{
    if (p[tar].ty == 1)
        p[pl].jmp = 3;
    else if (p[tar].jmp == 3)
        p[pl].jmp = 1;
    else if (p[tar].jmp == 1)
        p[pl].jmp = 3;
}
void ucard(int pl, int hvk)
{
    p[pl].usek = hvk;
    for (int j = p[pl].lc; j <= p[pl].rc; j++)
    {
        if (p[pl].hp < 4 && p[pl].h[j] == 'P') // peach
        {
            p[pl].h[j] = 'u';
            ++p[pl].hp;
        }
        else if (p[pl].h[j] == 'Z') // zg
        {
            p[pl].wp = 1;
            p[pl].h[j] = 'u';
            j = 1;
        }
        else if (p[pl].h[j] == 'K') // kill
        {
            int dst = 0;
            for (int i = pl + 1; i < pl + n; i++)
            {
                int tar = i > n ? i - n : i;
                if (p[tar].ded)
                    continue;
                ++dst;
                if (dst <= 1 && ((p[pl].usek == 0) || p[pl].wp))
                {
                    if (chksd1(pl, tar))
                    {
                        bool hvd = false;
                        p[pl].h[j] = 'u';
                        if (!p[pl].jmp || p[pl].jmp == 2)
                            jmpp(pl, tar);
                        p[pl].usek = p[pl].wp ? 0 : 1;
                        for (int k = p[tar].lc; k <= p[tar].rc; k++)
                            if (p[tar].h[k] == 'D')
                            {
                                p[tar].h[k] = 'u';
                                hvd = true;
                                break;
                            }
                        if (!hvd)
                        {
                            if (--p[tar].hp < 1)
                            {
                                if (chkde(tar))
                                {
                                    if (chkr())
                                    {
                                        pans();
                                        exit(0);
                                    }
                                    else
                                        dea(pl, tar);
                                    --dst;
                                }
                            }
                        }
                        p[pl].usek = p[pl].wp ? 0 : 1;
                        ucard(pl, p[pl].usek);
                        break;
                    }
                }
            }
        }
        else if (p[pl].h[j] == 'F') // jd
        {
            int tar = 0;
            for (int i = pl + 1; i < pl + n; i++)
            {
                int t = i > n ? i - n : i;
                if (p[t].ded)
                    continue;
                if (chksd1(pl, t))
                {
                    tar = t;
                    break;
                }
            }
            if (p[pl].ty == 3)
                tar = 1;
            if (!tar)
                continue;
            p[pl].h[j] = 'u';
            if (!p[pl].jmp || p[pl].jmp == 2)
                jmpp(pl, tar);
            if (wx::askw(tar, pl, 1))
                continue;
            int pll = pl;
            if (!jd(pl, tar))
                swap(pll, tar);
            if (--p[tar].hp < 1)
            {
                if (chkde(tar))
                {
                    if (chkr())
                    {
                        pans();
                        exit(0);
                    }
                    else
                        dea(pll, tar);
                    if (p[pl].ded)
                        break; //player dead
                }
            }
            ucard(pl, hvk);
            return;
        }
        else if (p[pl].h[j] == 'N') // nmrq
        {
            p[pl].h[j] = 'u';
            for (int i = pl + 1; i < pl + n; i++)
            {
                int tar = i > n ? i - n : i;
                if (p[tar].ded)
                    continue;
                if (wx::askw(tar, pl, 1))
                    continue;
                if (chknw(tar, 'K'))
                {
                    if ((!p[pl].jmp) && tar == 1)
                        p[pl].jmp = 2;
                    if (--p[tar].hp < 1)
                    {
                        if (chkde(tar))
                        {
                            if (chkr())
                            {
                                pans();
                                exit(0);
                            }
                            else
                                dea(pl, tar);
                        }
                    }
                }
            }
            ucard(pl, hvk);
            return;
        }
        else if (p[pl].h[j] == 'W') // wjqf
        {
            p[pl].h[j] = 'u';
            for (int i = pl + 1; i < pl + n; i++)
            {
                int tar = i > n ? i - n : i;
                if (p[tar].ded)
                    continue;
                if (wx::askw(tar, pl, 1))
                    continue;
                if (chknw(tar, 'D'))
                {
                    if ((!p[pl].jmp) && tar == 1)
                        p[pl].jmp = 2;
                    if (--p[tar].hp < 1)
                    {
                        if (chkde(tar))
                        {
                            if (chkr())
                            {
                                pans();
                                exit(0);
                            }
                            else
                                dea(pl, tar);
                        }
                    }
                }
            }
            ucard(pl, hvk);
            return;
        }
    }
}
int chknw(int pl, char t)
{
    for (int i = 1; i <= p[pl].rc; i++)
        if (p[pl].h[i] == t)
            return p[pl].h[i] = 'u', 0;
    return 1;
}
int jd(int pl, int tar)
{
    if (p[pl].ty == 1 && p[tar].ty == 2)
        return 1;
    while (1)
    {
        bool fil = true;
        for (int i = p[tar].lc; i <= p[tar].rc; i++)
        {
            if (p[tar].h[i] == 'K')
            {
                fil = false;
                p[tar].h[i] = 'u';
                break;
            }
        }
        if (fil)
            return 1;
        fil = true;
        for (int i = p[pl].lc; i <= p[pl].rc; i++)
        {
            if (p[pl].h[i] == 'K')
            {
                fil = false;
                p[pl].h[i] = 'u';
                break;
            }
        }
        if (fil)
            return 0;
    }
}
void roundst(int pl)
{
    dcard(pl, 2);
    ucard(pl, 0);
}
void pans()
{
    if (p[1].ded)
        puts("FP");
    else
        puts("MP");
    for (int i = 1; i <= n; i++)
    {
        if (p[i].ded)
            puts("DEAD");
        else
        {
            char res[2333];
            int rp = 0;
            for (int j = p[i].lc; j <= p[i].rc; j++)
                if (p[i].h[j] != 'u')
                    res[++rp] = p[i].h[j];
            if (!rp)
                puts("");
            else
                for (int j = 1; j <= rp; j++)
                    printf("%c%c", res[j], j == rp ? '\n' : ' ');
        }
    }
}
bool chkr()
{
    if (p[1].ded)
        return rr = true;
    for (int i = 2; i <= n; i++)
        if (p[i].ty == 3 && (!p[i].ded))
            return rr = false;
    return rr = true;
}
int main()
{
    sread();
    while (!rr)
    {
        for (int i = 1; i <= n; i++)
        {
            if (!p[i].ded)
                roundst(i);
            if (rr)
                return pans(), 0;
        }
    }
    return pans(), 0;
}