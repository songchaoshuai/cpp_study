// FractionClass.cpp : 定义控制台应用程序的入口点。
/*
3、设计并实现分数类，要求：
（1）实现” >> ”与” << ”的标准输入输出；
（2）实现加法运算；
（3）实现获取其对应小数的接口；
（4）实现拷贝构造及赋值运算；
（5）构造时可指定分子分母也可以不指定，不指定则分子分母均为1。
*/
#include "stdafx.h"
#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
	std::cout <<"1.默认分数:"<< std::endl;
	fraction f1;
	std::cout << f1 <<":" << f1.decimal() << std::endl;
	std::cout << "2.分数加法:" << std::endl;
	fraction f2(2,3);
	fraction f3(3,4);
	std::cout <<f2<<"+"<<f3<<"="<<f2+f3<< std::endl;
	std::cout << "3.拷贝构造函数 :" << std::endl;
	fraction f5(f2);
	std::cout << f5 << ":" << f5.decimal() << std::endl;
	std::cout << "4.赋值操作 :" << std::endl;
	f5 = f3;
	std::cout << f5 << ":" << f5.decimal() << std::endl;
	std::cout << "5.验证输入（输入格式：分子 分母）:" << std::endl;
	fraction f4;
	std::cin >> f4;
	std::cout << f4<< ":"<<f4.decimal()<<std::endl;

    return 0;
}

