#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
public:
    int x,y;
    int *p;

    Array2():x(0),y(0),p(nullptr){}
    Array2(int a,int b):x(a),y(b)
    {
        p = new int[a * b];
    }

    int* operator [](int i)
    {
        return p + y * i;
    }

    int& operator ()(int i,int j)
    {
        return p[i * y + j];
    }

    Array2& operator = (const Array2& a)
    {
        if(a.p == nullptr) 
        {
            p = nullptr;
            return *this;
        }
        if(p) delete []p;
        x = a.x;
        y = a.y;
        p = new int [x * y];
        memcpy(p,a.p,sizeof(a.p[0]) * x * y);
    }

};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}