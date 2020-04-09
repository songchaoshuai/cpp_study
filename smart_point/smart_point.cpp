// smart_point.cpp : �������̨Ӧ�ó������ڵ㡣
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


	SmartPointer& operator=(const SmartPointer& sp) {   //������const
		ptr_counter->cnt--;
		if (ptr_counter->cnt == 0) {
			delete ptr_counter;
		}
		ptr_counter = sp.ptr_counter;
		ptr_counter->cnt++;
		std::cout << __FUNCTION__ << ":" << __LINE__ << ":"<<ptr_counter->cnt << std::endl;
		return *this;  // ��ֵ��������ض�Ҫ����*this
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

