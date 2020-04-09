// ReverseStr.cpp : �������̨Ӧ�ó������ڵ㡣
/*
1��ʵ�ֺ��� ��void ReverseStr(std::string& strValue)����Ҫ��
��1����strValue�ַ�����ת�����磺��1abc5��ת��Ϊ��5cba1������abcd��ת��Ϊ��dcba����
��2��������ʹ�ÿ⺯����strrev������reverse����
��3�����������Ż�ʱ�临�Ӷȡ�
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

