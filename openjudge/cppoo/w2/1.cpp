#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {

    char name[233];
    int age,num;
    double gr[4],avg;

public:

    void input()
    {
        scanf("%[^,]%*c",name);
        scanf("%d,%d,%lf,%lf,%lf,%lf",&age,&num,&gr[0],&gr[1],&gr[2],&gr[3]);
    }

    void calculate()
    {
        avg = 0;
        for(int i = 0;i < 4;i++)
        {
            avg += gr[i];
        }
        avg /= 4;
    }

    void output()
    {
        printf("%s,%d,%d,",name,age,num);
        cout << avg;
    }

};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}