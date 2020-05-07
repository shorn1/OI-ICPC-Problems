#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d,const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
		
}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{
// 在此处补充你的代码
public:
    char s[23333];
    MyString()
    {
        for(int i = 0;i < 23333;i++) s[i] = 0;
    }
    MyString(char *s1)
    {
        strcpy(s,s1);
    }
    MyString(const MyString &s1)
    {
        strcpy(s,s1.s);
    }
    bool operator < (const MyString &a) const
    {
        return strcmp(s,a.s) < 0;
    }
    bool operator > (const MyString &a) const
    {
        return strcmp(s,a.s) > 0;
    }
    bool operator == (const MyString &a) const
    {
        return !strcmp(s,a.s);
    }
    friend ostream& operator << (ostream& o, const MyString &a)
    {
        o << a.s;
        return o;
    }
    char & operator [] (int i)
    {
        return s[i];
    }
    MyString operator ()(int a,int b)
    {
        MyString t;
        for(int i = 0; i < b;i++)
        {
            t.s[i] = s[i + a];
        }
        t.s[b] = 0;
        return t;
    }
    friend MyString operator + (const MyString &a,const MyString &b)
    {
        MyString c;
        strcpy(c.s,a.s);
        strcat(c.s,b.s);
        return c;
    }
    friend MyString& operator += (MyString &a,const MyString &b)
    {
        MyString c;
        c = a + b;
        a = c;
        return a;
    }
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}