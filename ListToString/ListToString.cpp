// ListToString.cpp : 定义控制台应用程序的入口点。
/*
2、实现函数 “string ListToString(const std::list<int>& lstValue)”
（1）将list中的元素合并，转换成string类型；
（2）每个list中的元素之间用中文顿号——”、”隔开;
（3）如果list中的元素小于或等于三个，则全部列出；如果大于三个，则列出其中的前三个，并在最后加上”等”字。
实例：std::list<int> lstTest1{ 1, 2, 8 }，转换为:  ”1、2、3”
Std::list<int> lstTest2{ 1,10,8,30,20 }，转换为: ”1、10、8等”
*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

string ListToString(const std::list<int>& lstValue)
{
	size_t len = lstValue.size();
	string ret;
	wstring r;
	if (len > 3)
	{
		int i = 0;
		for (std::list<int>::const_iterator it = lstValue.begin(); i<3 && it != lstValue.end(); i++,it++)
		{
			int temp = *it;
			ret.append(to_string(temp));
			if (i < 2)
			{
				ret.append("、");
			}	
		}
		ret.append("等");
	}
	else
	{
		for (std::list<int>::const_iterator it = lstValue.begin(); it != lstValue.end(); it++)
		{
			int temp= *it;
			ret.append(to_string(temp));
			ret.append("、");
		}
		ret.pop_back();
	}
	return ret;
}

int main()
{
	string ret;
	int a;
	
	list<int> lstValue;
	lstValue.push_back(1);
	lstValue.push_back(2);
	lstValue.push_back(3);
	lstValue.push_back(4);
	lstValue.push_back(5);
	ret=ListToString(lstValue);
	std::cout << "ret:" << ret << std::endl;
	list<int> lstValue2;
	lstValue2.push_back(11);
	lstValue2.push_back(12);

	ret = ListToString(lstValue2);
	std::cout << "ret:" << ret << std::endl;
    return 0;
}

