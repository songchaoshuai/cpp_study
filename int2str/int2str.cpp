// int2str.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
using namespace std;

#define LOG __FUNCTION__<<":"<<__LINE__<<":"
void int2str1()
{
	int a = 10;
	char intStr[10] = { 0 };
	_itoa_s(a,intStr,10);
	string str = string(intStr);
	std::cout << LOG << str << std::endl;
}


//sstringstream 
void int2str2()
{
	int a = 10;
	stringstream ss;
	ss << a;
	string str = ss.str();  //ss>>str;
	std::cout << LOG << str << std::endl;
}

void str2int2()
{
	string str("101");;
	stringstream ss;
	int a;
	ss << str;
	ss >> a;
	std::cout << LOG << a << std::endl;
}

void int2str3()
{
	int a = 10;
	string str = to_string(a);
	std::cout << LOG << str << std::endl;
}

//sprintf() sscanf()
void int2str4()
{
	char str[10];
	int a = 1234321;
	//将整数转化为字符串
	sprintf(str, "%d", a);
	int len = strlen(str);
	std::cout << LOG << "字符串" << str << endl;
	std::cout << LOG << "长度" << len << endl;

	char str1[10];
	double b = 123.321;

	sprintf(str1, "%.3lf", b);
	int len1 = strlen(str1);
	std::cout << LOG << "字符串" << str1 << endl;
	std::cout << LOG << "长度" << len1 << endl;
}
void str2int4()
{
	char str[] = "1234321";
	int a;
	sscanf(str, "%d", &a);
	std::cout << LOG << a << endl;

	char str1[] = "123.321";
	double b;
	sscanf(str1, "%lf", &b);
	std::cout << LOG << b << endl;
}
int main()
{
	int2str1();
	int2str2();
	str2int2();
	int2str3();
	int2str4();
	str2int4();
    return 0;
}

