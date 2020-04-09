// c11std_move.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
std::move���������Էǳ��򵥵ķ�ʽ����ֵ����ת��Ϊ��ֵ���á�
����ֵ����ֵ���á���ֵ����ֵ���� �μ���http ://www.cnblogs.com/SZxiaochun/p/8017475.html��

ͨ��std::move�����Ա��ⲻ��Ҫ�Ŀ���������

std::move��Ϊ���ܶ�����

std::move�ǽ������״̬��������Ȩ��һ������ת�Ƶ���һ������ֻ��ת�ƣ�û���ڴ�İ�Ǩ�����ڴ濽����
*/
/*
1����ֵ����ֵ�ĸ���
��ֵ�ǿ��Է��ڸ�ֵ����߿��Ա���ֵ��ֵ����ֵ����Ҫ���ڴ�����ʵ�壻
��ֵ���ڸ�ֵ���ұ�ȡ��ֵ��������������ֵ����ֵ�������ڴ�Ҳ������CPU�Ĵ�����
һ������������ֵʱ��ʹ�õ�����������(ֵ)����������ֵʱ��ʹ�õ������ĵ�ַ��

2������
������C++�﷨�����Ż������õı��ʻ��ǿ�ָ����ʵ�ֵġ������൱�ڱ����ı�����

���ÿ��Ըı�ָ���ָ�򣬻����Ըı�ָ����ָ���ֵ��

���õĻ�������

�������õ�ʱ������ʼ������һ���󶨣����ɰ����ð󶨵��������󣻼����ñ����ʼ�������ܶ������ض��壻
�����õ�һ�в��������൱�ڶ�ԭ����Ĳ�����
3����ֵ���ú���ֵ����
3.1 ��ֵ����
��ֵ���õĻ����﷨��
type &������ = ��ֵ����ʽ��

3.2 ��ֵ����

��ֵ���õĻ����﷨
type &&������ = ��ֵ����ʽ��

��ֵ��������ҵ������Ա�ڴ����Ż�����ᾭ���õ���

��ֵ���õġ�&&���м䲻�����пո�
*/
#include "stdafx.h"
#include <iostream>
#include <utility>
#include <vector>
#include <string>
int main()
{
	std::string str = "Hello";
	std::vector<std::string> v;
	//���ó���Ŀ������캯�����½��ַ����飬��������
	v.push_back(str);
	std::cout << "After copy, str is \"" << str << "\"\n";
	//�����ƶ����캯�����Ϳ�str���Ϳպ���ò�Ҫʹ��str
	v.push_back(std::move(str));
	std::cout << "After move, str is \"" << str << "\"\n";
	std::cout << "The contents of the vector are \"" << v[0]
		<< "\", \"" << v[1] << "\"\n";
    return 0;
}

