#pragma once
#ifndef __FRACTION_H__
#define __FRACTION_H__
#include <istream>
class fraction
{
public:
	fraction(float top=1.0, float bottom=1.0);
	fraction(fraction & f1);
	fraction operator +(fraction f1);
	void operator=(fraction f1);
	friend std::ostream & operator <<(std::ostream & out, const fraction f1);
	friend std::istream & operator >>(std::istream & in,fraction &f1);
	float decimal();
private:
	float bottomCom(float a, float b);

private:
	float top;
	float bottom;
	
};
#endif // !__FRACTION_H__
