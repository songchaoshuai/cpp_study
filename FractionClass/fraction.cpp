#include "fraction.h"
fraction::fraction(float top,float bottom)
{
	this->top = top;
	this->bottom = bottom;
}

fraction::fraction(fraction & f1)
{
	this->top = f1.top;
	this->bottom = f1.bottom;
}


fraction fraction::operator +(fraction f1)
{
	fraction temp;
	float mixMut;
	mixMut = bottomCom(this->bottom,f1.bottom);
    temp.bottom = mixMut;
	temp.top = (mixMut)/(this->bottom)*(this->top)+ (mixMut) / (f1.bottom)*(f1.top);
	return temp;
}

void fraction::operator=(fraction f1)
{
	this->top = f1.top;
	this->bottom = f1.bottom;
}

std::ostream & operator <<(std::ostream & out,const fraction f1)
{
	out << f1.top << "/" << f1.bottom ;
	return out;
}

std::istream & operator >> (std::istream & in, fraction &f1)
{
	in >> f1.top >> f1.bottom;
	return in;
}

float fraction::decimal()
{
	return top / bottom;
}

float fraction::bottomCom(float a, float b)
{
	int a1, b1, t;
	float  mut;
	if (a > b)
	{
		a1 = (int)a;
		b1 = (int)b;
	}
	else
	{
		b1 = (int)a;
		a1 = (int)b;
	}

	mut = a1*b1;
	t = a1%b1;
	while (t != 0)
	{
		a1 = b1;
		b1 = t;
		t = a1%b1;
	}
	return mut / b1;
}