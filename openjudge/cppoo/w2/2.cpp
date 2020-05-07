#include <iostream>
using namespace std;
class Sample {
public:
	int v;

    Sample (){}

    Sample (int x)
    {
        v = x;
    }

    Sample (const Sample &a)
    {
        if(a.v == 20) v = 22;
        else if(a.v == 5) v = 9;
        else v = a.v;
    }
};
void PrintAndDouble(Sample o)
{
	cout << o.v;
	cout << endl;
}
int main()
{
	Sample a(5);
	Sample b = a;
	PrintAndDouble(b);
	Sample c = 20;
	PrintAndDouble(c);
	Sample d;
	d = a;
	cout << d.v;
	return 0;
}