// ListToString.cpp : �������̨Ӧ�ó������ڵ㡣
/*
2��ʵ�ֺ��� ��string ListToString(const std::list<int>& lstValue)��
��1����list�е�Ԫ�غϲ���ת����string���ͣ�
��2��ÿ��list�е�Ԫ��֮�������Ķٺš�������������;
��3�����list�е�Ԫ��С�ڻ������������ȫ���г�������������������г����е�ǰ���������������ϡ��ȡ��֡�
ʵ����std::list<int> lstTest1{ 1, 2, 8 }��ת��Ϊ:  ��1��2��3��
Std::list<int> lstTest2{ 1,10,8,30,20 }��ת��Ϊ: ��1��10��8�ȡ�
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
				ret.append("��");
			}	
		}
		ret.append("��");
	}
	else
	{
		for (std::list<int>::const_iterator it = lstValue.begin(); it != lstValue.end(); it++)
		{
			int temp= *it;
			ret.append(to_string(temp));
			ret.append("��");
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

