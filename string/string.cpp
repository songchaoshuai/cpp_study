// string.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class String {
public:
	String();
	String(const char * str="");
	String(const String & str);
	~String();
	void swap(String & str);
	const char * c_str();
	void Expand(int n);
	void pushbach(char ch);

	////////operator
	String & operator =(const String &str);
	////////operator  + 
	bool operator ==(const String &str);
	bool operator >(const String &str);
	bool operator >=(const String &str);
	bool operator <(const String &str);
	bool operator <=(const String &str);
	bool operator !=(const String &str);

private:
	char * content;
	int length;
};

String::String()
{
	content = nullptr;
	length = 0;
}

String::String(const char * str)
{
	length = strlen(str);
	content = new char[length];

}

String::String(const String & str)
{

}

String::~String()
{
	if (content)
	{
		delete content;
	}
	content = nullptr;
	length = 0;
}

void String::swap(String & str)
{
}

const char * String::c_str()
{
	return nullptr;
}

void String::Expand(int n)
{
}

void String::pushbach(char ch)
{
}

String & String::operator=(const String & str)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

bool String::operator==(const String & str)
{
	return false;
}

bool String::operator>(const String & str)
{
	return false;
}

bool String::operator>=(const String & str)
{
	return false;
}

bool String::operator<(const String & str)
{
	return false;
}

bool String::operator<=(const String & str)
{
	return false;
}

bool String::operator!=(const String & str)
{
	return false;
}

int main()
{
    return 0;
}

