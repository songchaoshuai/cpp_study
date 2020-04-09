// smart_point.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename Object1>
class SmartPointer;

template < typename Object>
class Counter {
public:
	friend SmartPointer<Object>;
	Counter() {
		ptr = NULL;
		cnt = 0;
	}

	Counter(Object* p) {
		ptr = p;
		cnt = 1;
	}

	~Counter() {
		delete ptr;
	}
private:
	Object* ptr;
	int cnt;
};

template <typename Object1>
class SmartPointer{
public:
	SmartPointer(Object1* p) {
		ptr_counter = new Counter<Object1>(p);
		std::cout << __FUNCTION__ << ":" << __LINE__ << ":"<<ptr_counter->cnt << std::endl;
	}

	SmartPointer(const SmartPointer& sp) {
		ptr_counter = sp.ptr_counter;
		ptr_counter->cnt++;
		std::cout <<__FUNCTION__ << ":" << __LINE__ << ":"<<ptr_counter->cnt << std::endl;
	}

	~SmartPointer() {
		ptr_counter->cnt--;
		std::cout << __FUNCTION__ << ":" << __LINE__ << ":" << ptr_counter->cnt << std::endl;
		if (ptr_counter->cnt == 0) {
			delete ptr_counter;
		}
		
	}


	SmartPointer& operator=(const SmartPointer& sp) {   //别忘了const
		ptr_counter->cnt--;
		if (ptr_counter->cnt == 0) {
			delete ptr_counter;
		}
		ptr_counter = sp.ptr_counter;
		ptr_counter->cnt++;
		std::cout << __FUNCTION__ << ":" << __LINE__ << ":"<<ptr_counter->cnt << std::endl;
		return *this;  // 赋值运算符重载都要返回*this
	}
private:
	Counter<Object1>* ptr_counter;
};

class T
{
public:
	T();

};

T::T()
{

}

int main()
{
	SmartPointer<T> a=new T();
	SmartPointer<T> b = a;
	SmartPointer<T> c = new T();
	b = c;
    return 0;
}

