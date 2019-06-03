// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;

class CFeet
{
	int feet;
	int inches;
	int check();
public:
	CFeet();
	CFeet(int a, int b);
	int setFeet(int a, int b);
	void disPlay();
	int addFeet(int a, int b);
	CFeet CFeet::operator+(CFeet &oa);
	CFeet CFeet::operator+(const int&ob);
};
CFeet::CFeet()
{
	feet = 1;
	inches = 1;
}
CFeet::CFeet(int a, int b)
{
	feet = a;
	inches = b;
	check();
}
int CFeet::setFeet(int a, int b)
{
	feet = a;
	inches = b;
	check();
	return 0;
}
void CFeet::disPlay()
{
	cout << feet << "英尺" << inches << "英寸" << endl;
}
int CFeet::addFeet(int a, int b)
{
	feet = feet + a;
	inches = inches + b;
	if (inches>12)
	{
		inches = inches % 12;
		feet = inches / 12;
	}
	return 0;
}
int CFeet::check()
{
	if (inches>12)
	{
		inches = inches % 12;
		feet = inches / 12;
	}
	return 0;
}
CFeet CFeet::operator+(CFeet &oa)
{
	CFeet anotherfeet;
	anotherfeet.setFeet(feet + oa.feet, inches + oa.inches);
	return anotherfeet;
}
/*
CFeet CFeet::add(CFeet & oc)
{
CFeet temp;
temp.setvalue(feet + oc.feet, inches + oc.inches);
return temp;
}
执行方法a.add(b)*/
CFeet CFeet::operator+(const int&ob)
{
	CFeet anotherfeet;
	anotherfeet.setFeet(feet, inches + ob);
	return anotherfeet;
}
int main()
{
	CFeet feet1(10, 1), feet2(10, 6), feet3, feet4;
	feet1.disPlay();
	feet3 = feet1 + 10;
	feet3.disPlay();
	feet4 = feet1 + feet2;
	feet4.disPlay();
	return 0;
}

