// ReverseStr.cpp : 定义控制台应用程序的入口点。
/*
1、实现函数 “void ReverseStr(std::string& strValue)”，要求：
（1）将strValue字符串反转，例如：”1abc5”转换为”5cba1”，“abcd”转换为”dcba”；
（2）不允许使用库函数”strrev”及”reverse”；
（3）尽最大可能优化时间复杂度。
*/










#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
void ReverseStr(std::string& strValue)
{
	char * cValue;
	size_t len=strValue.length();
	cValue = new char[len+1];
	const char * ccValue;
    ccValue=strValue.c_str();
	for (int i = 0; i <= len / 2; i++)
	{
		cValue[i] = ccValue[len -1 - i];
		cValue[len-1-i] = ccValue[i];
	}
	cValue[len] = 0x00;
	string str(cValue);
	strValue = str;
	delete[]cValue;
}

int main()
{
	string str("abcdefg 1234567890");
	std::cout << "Before:" <<str.length() << " " << str << std::endl;
	ReverseStr(str);
	std::cout << "After:" << str.length() << " " << str << std::endl;
	str="abcdefg1234567890";
	std::cout << "Before:" << str.length() << " " << str << std::endl;
	ReverseStr(str);
	std::cout << "After:" << str.length() << " " << str << std::endl;
    return 0;
}

