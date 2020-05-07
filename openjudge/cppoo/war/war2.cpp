#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
/*
#define ns namespace
#define lol long long
using ns std;
*/
int T;

/*const char weap_n[3][11] = {"sword","bomb","arrow"};
const char warr_n[5][11] = {"iceman","lion","wolf","ninja","dragon"};
const int warr_seq[2][5] = {{0,1,2,3,4},{1,4,3,0,2}};*/

static constexpr char sidec[11][11] = {"red","blue"};
static constexpr char weap_n[11][11] = {"sword","bomb","arrow","ERRORWP"};
static constexpr char warr_n[11][11] = {"dragon","ninja","iceman","lion","wolf","ERRORWAR"};
static constexpr int warr_seq[11][11] = {{2,3,4,1,0},{3,0,1,2,4}};

struct war
{
    int ti;
    int wlif[11];
    int wced[11];
    

    struct weap
    {
        int ty;
        weap(int t = 3)
        {
            ty = t;
        }
    };

    struct warrior
    {
        int ty,num,st;
        double mor;
        int loy;
        weap wp[2];
        warrior(int tii,int t = 5,int li = -1,int cli = -1,int sid = -1,int cnum = -1)
        {
            ty = t;
            num = tii;
            st = cli;
            mor = -1.0;
            loy = -1;
            if(t == 0) 
            {
                wp[0].ty = tii % 3;
                mor = 1.0 * li / cli;
            }
            else if(t == 1)
            {
                wp[0].ty = tii % 3;
                wp[1].ty = (tii + 1) % 3;
            }
            else if(t == 2)
                wp[0].ty = tii % 3;
            else if(t == 3)
                loy = li;
            printc(tii,sid,cnum);
        }
        void printc(int ti,int sid,int cnum)
        {
            printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",ti - 1,sidec[sid],warr_n[ty],ti,st,cnum,warr_n[ty],sidec[sid]);
            if(ty == 0)            
                printf("It has a %s,and it's morale is %.2f\n",weap_n[wp[0].ty],mor);
            else if(ty == 1)            
                printf("It has a %s and a %s\n",weap_n[wp[0].ty],weap_n[wp[1].ty]);
            else if(ty == 2)
                printf("It has a %s\n",weap_n[wp[0].ty]);
            else if(ty == 3) 
                printf("It's loyalty is %d\n",loy);
        }
    };

    struct bas
    {
        int col;
        int lif;
        int wn[5];
        int lstc;
        std::vector<warrior> w;
        bas(int c,int l = 0)
        {
            col = c;
            lif = l;
            for(int i = 0;i < 5;i++) wn[i] = 0;
            lstc = -1;
        }

    };
    bas b[2] = {{0},{1}};

    war()
    {
        ti = 0;
        memset(wlif,0,sizeof(wlif));
        memset(wced,0,sizeof(wced));    
    }

    int create_warrior(bas &ba)
    {
        int wcd = 0;
        //for(int i = ti;i <= ti + 4;i++)
        for(int i = ba.lstc + 1;i <= ba.lstc + 5;i++)
        {
            int ty = warr_seq[ba.col][i % 5];
            if(ba.lif >= wlif[ty]) 
            {
                ba.lif -= wlif[ty];
                ba.wn[ty]++;
                warrior tmp(ti + 1,ty,ba.lif,wlif[ty],ba.col,ba.wn[ty]);
                ba.w.push_back(tmp);
                wcd = ty + 1;
                ba.lstc = i;
                break;
            }
        }
        if(!wcd) printf("%03d %s headquarter stops making warriors\n",ti,sidec[ba.col]);
        return wcd;
    }

    void gamest(int cas,int m)
    {
        printf("Case:%d\n",cas);
        b[0].col = 0;b[1].col = 1;
        b[0].lif = b[1].lif = m;
        ti = 0;
        wced[0] = wced[1] = 5;
        while(1)
        {
            if(wced[0]) wced[0] = create_warrior(b[0]);
            if(wced[1]) wced[1] = create_warrior(b[1]);
            if(wced[0] == 0 && wced[1] == 0) break;
            ti++;
        }
    }

    void debbg_p()
    {
        for(int j = 0;j < 5;j++) 
            printf("%d ",wlif[j]);
    }
};


int main(int argc,char** argv)
{
    scanf("%d",&T);
    for(int i = 1;i <= T;i++)
    {
        int m;
        war g;
        scanf("%d",&m);
        for(int j = 0;j < 5;j++) scanf("%d",&g.wlif[j]);
        g.gamest(i,m);
    }
    return 0;
}