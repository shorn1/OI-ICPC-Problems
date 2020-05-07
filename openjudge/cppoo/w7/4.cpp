#include <iostream>
using namespace std;
class MyCin
{
// 在此处补充你的代码
public:
    bool b;
    MyCin():b(1){}

    operator bool(){return b;}

    friend MyCin& operator >> (MyCin& bb,int &k)
    {
        cin >> k;
        if(!bb.b) return bb;
        bb.b = (k == -1) ? 0 : 1;
        return bb;
    } 

};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}