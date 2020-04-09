// lamada_function.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include<functional>
using namespace std;

double eval(std::function<double(double)> f, double x = 2.0) { return f(x); }
int main()
{
	std::vector<int> some_list;
	int total = 0;
	for (int i = 0; i<5; ++i) some_list.push_back(i);
	std::for_each(begin(some_list), end(some_list), [&total](int x)
	{
		total += x;
	});
	std::cout << "the total  num:" << total << std::endl;

	std::function<double(double)> f0 = [](double x) {return 1; };
	auto                          f1 = [](double x) {return x; };
	decltype(f0)                  fa[3] = { f0,f1,[](double x) {return x*x; } };
	std::vector<decltype(f0)>     fv = { f0,f1 };
	fv.push_back([](double x) {return x*x; });
	for (int i = 0; i<fv.size(); i++)  std::cout << fv[i](2.0) << "\n";
	for (int i = 0; i<3; i++)          std::cout << fa[i](2.0) << "\n";
	for (auto &f : fv)             std::cout << f(2.0) << "\n";
	for (auto &f : fa)             std::cout << f(2.0) << "\n";
	std::cout << eval(f0) << "\n";
	std::cout << eval(f1) << "\n";
	return 0;
}
