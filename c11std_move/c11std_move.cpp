// c11std_move.cpp : 定义控制台应用程序的入口点。
//
/*
std::move函数可以以非常简单的方式将左值引用转换为右值引用。
（左值、左值引用、右值、右值引用 参见：http ://www.cnblogs.com/SZxiaochun/p/8017475.html）

通过std::move，可以避免不必要的拷贝操作。

std::move是为性能而生。

std::move是将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存的搬迁或者内存拷贝。
*/
/*
1、左值和右值的概念
左值是可以放在赋值号左边可以被赋值的值；左值必须要在内存中有实体；
右值当在赋值号右边取出值赋给其他变量的值；右值可以在内存也可以在CPU寄存器。
一个对象被用作右值时，使用的是它的内容(值)，被当作左值时，使用的是它的地址。

2、引用
引用是C++语法做的优化，引用的本质还是靠指针来实现的。引用相当于变量的别名。

引用可以改变指针的指向，还可以改变指针所指向的值。

引用的基本规则：

声明引用的时候必须初始化，且一旦绑定，不可把引用绑定到其他对象；即引用必须初始化，不能对引用重定义；
对引用的一切操作，就相当于对原对象的操作。
3、左值引用和右值引用
3.1 左值引用
左值引用的基本语法：
type &引用名 = 左值表达式；

3.2 右值引用

右值引用的基本语法
type &&引用名 = 右值表达式；

右值引用在企业开发人员在代码优化方面会经常用到。

右值引用的“&&”中间不可以有空格。
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
	//调用常规的拷贝构造函数，新建字符数组，拷贝数据
	v.push_back(str);
	std::cout << "After copy, str is \"" << str << "\"\n";
	//调用移动构造函数，掏空str，掏空后，最好不要使用str
	v.push_back(std::move(str));
	std::cout << "After move, str is \"" << str << "\"\n";
	std::cout << "The contents of the vector are \"" << v[0]
		<< "\", \"" << v[1] << "\"\n";
    return 0;
}


