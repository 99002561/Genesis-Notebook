

#include "gtest/gtest.h"
class Fraction
{
private:
	int m_numerator, m_denominator;
public:
	Fraction();
	Fraction(int, int);
	Fraction(const Fraction&);
	Fraction operator + (const Fraction&);
	Fraction operator - (const Fraction&);
	Fraction operator * (const Fraction&);
	Fraction operator + (int);
	Fraction operator - (int);
	int operator == (const Fraction&);
	int operator < (const Fraction&);
	int operator > (const Fraction&);
	int get_mnumerator();
	int get_mdenominator();
	Fraction simplify();
	bool isSimplest();
	void display();


};
