//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "pch.h"


using namespace std;
Fraction::Fraction() : m_numerator(0), m_denominator(0) {}
Fraction::Fraction(int num, int deno) : m_numerator(num), m_denominator(deno) {}
Fraction::Fraction(const Fraction& obj) : m_numerator(obj.m_numerator), m_denominator(obj.m_denominator) {}

Fraction Fraction:: operator + (const Fraction& obj)
{
	int gcd{ 0 };
	Fraction sum;
	if (m_denominator == obj.m_denominator)
	{
		sum.m_numerator = m_numerator + obj.m_numerator;
		sum.m_denominator = m_denominator;
	}
	else
	{
		sum.m_numerator = (m_numerator * obj.m_denominator) + (obj.m_numerator * m_denominator);
		sum.m_denominator = m_denominator * obj.m_denominator;
	}

	for (int i = 1; i <= sum.m_numerator && i <= sum.m_denominator; ++i)
	{
		if (sum.m_numerator % i == 0 && sum.m_denominator % i == 0)
			gcd = i;
	}

	sum.m_numerator = sum.m_numerator / gcd;
	sum.m_denominator = sum.m_denominator / gcd;

	return sum;

}

Fraction Fraction:: operator - (const Fraction& obj)
{
	Fraction diff;
	int gcd{ 0 };
	if (m_denominator == obj.m_denominator)
	{
		diff.m_numerator = m_numerator - obj.m_numerator;
		diff.m_denominator = m_denominator;
	}
	else
	{
		diff.m_numerator = (m_numerator * obj.m_denominator) - (obj.m_numerator * m_denominator);
		diff.m_denominator = m_denominator * obj.m_denominator;
	}

	for (int i = 1; i <= diff.m_numerator && i <= diff.m_denominator; ++i)
	{
		if (diff.m_numerator % i == 0 && diff.m_denominator % i == 0)
			gcd = i;
	}

	diff.m_numerator = diff.m_numerator / gcd;
	diff.m_denominator = diff.m_denominator / gcd;

	return diff;

}

Fraction Fraction:: operator*(const Fraction & obj)
{
	Fraction prod;
	prod.m_numerator = m_numerator * obj.m_numerator;
	prod.m_denominator = m_denominator * obj.m_denominator;
	return prod;
}

Fraction Fraction:: operator + (int incval)
{
	Fraction inc;
	inc.m_numerator = m_numerator + incval * m_denominator;
	inc.m_denominator = m_denominator;

	return inc;
}


Fraction Fraction:: operator - (int decval)
{
	Fraction dec;
	dec.m_numerator = m_numerator - decval * m_denominator;
	dec.m_denominator = m_denominator;

	return dec;
}

int Fraction:: operator == (const Fraction& obj)
{
	if (m_numerator == obj.m_numerator && m_denominator == obj.m_denominator)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int Fraction:: operator > (const Fraction& obj)
{
	int x;
	x= (m_numerator * obj.m_denominator) - (obj.m_numerator * m_denominator);
	if (x>0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int Fraction:: operator < (const Fraction& obj)
{
	int x;
	x = (m_numerator * obj.m_denominator) - (obj.m_numerator * m_denominator);
	if (x < 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void Fraction::display()
{
	cout << "Fraction is = " << m_numerator << "/" << m_denominator << endl;
}

int Fraction::get_mnumerator()
{
	return m_numerator;
}
int Fraction::get_mdenominator()
{
	return m_denominator;
}
Fraction Fraction::simplify()
{
	Fraction simp;
	int gcd{0};
	for (int i = 1; i <= m_numerator && i <= m_denominator; ++i)
	{
		if (m_numerator % i == 0 && m_denominator % i == 0)
			gcd = i;
	}

	simp.m_numerator = simp.m_numerator / gcd;
	simp.m_denominator = simp.m_denominator / gcd;
	return simp;

}
/*
bool Fraction::isSimplest()
{

}
*/