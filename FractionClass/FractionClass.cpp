// FractionClass.cpp : �������̨Ӧ�ó������ڵ㡣
/*
3����Ʋ�ʵ�ַ����࣬Ҫ��
��1��ʵ�֡� >> ���롱 << ���ı�׼���������
��2��ʵ�ּӷ����㣻
��3��ʵ�ֻ�ȡ���ӦС���Ľӿڣ�
��4��ʵ�ֿ������켰��ֵ���㣻
��5������ʱ��ָ�����ӷ�ĸҲ���Բ�ָ������ָ������ӷ�ĸ��Ϊ1��
*/
#include "stdafx.h"
#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
	std::cout <<"1.Ĭ�Ϸ���:"<< std::endl;
	fraction f1;
	std::cout << f1 <<":" << f1.decimal() << std::endl;
	std::cout << "2.�����ӷ�:" << std::endl;
	fraction f2(2,3);
	fraction f3(3,4);
	std::cout <<f2<<"+"<<f3<<"="<<f2+f3<< std::endl;
	std::cout << "3.�������캯�� :" << std::endl;
	fraction f5(f2);
	std::cout << f5 << ":" << f5.decimal() << std::endl;
	std::cout << "4.��ֵ���� :" << std::endl;
	f5 = f3;
	std::cout << f5 << ":" << f5.decimal() << std::endl;
	std::cout << "5.��֤���루�����ʽ������ ��ĸ��:" << std::endl;
	fraction f4;
	std::cin >> f4;
	std::cout << f4<< ":"<<f4.decimal()<<std::endl;

    return 0;
}

