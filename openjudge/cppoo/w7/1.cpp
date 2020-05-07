#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(

// 在此处补充你的代码
    T* be,T* ed)
{
    T k = *be;
    for(T* i = be + 1;i != ed;++i)
    {
        k += *i;
    }
    return k;
}
int main()
{
    string array[4] = {"Tom", "Jack", "Mary", "John"};
    cout << SumArray(array, array + 4) << endl;
    int a[4] = {1, 2, 3, 4}; //提示：1+2+3+4 = 10
    cout << SumArray(a, a + 4) << endl;
    return 0;
}