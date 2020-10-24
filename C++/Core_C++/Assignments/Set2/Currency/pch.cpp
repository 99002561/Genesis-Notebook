//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "pch.h"

using namespace std;
/*Currency();
	Currency(int, int);
	Currency(const Currency&);
	Currency operator + (const Currency&);
	Currency operator - (const Currency&);
	Currency operator + (int);
	Currency operator - (int);
	Currency operator ++ (); //pre
	Currency operator ++ (int); //post
	Currency operator == (const Currency&);
	Currency operator <(const Currency&);
	Currency operator <(const Currency&);
	int get_mrupees();
	int get_mpaise();
	void display();*/


Currency::Currency() : m_rupees(0), m_paise(0) {}
Currency::Currency(int rup, int ps) : m_rupees(rup), m_paise(ps) {}
Currency::Currency(const Currency& obj) : m_rupees(obj.m_rupees), m_paise(obj.m_paise) {}

Currency Currency:: operator + (const Currency& obj)
{
	Currency sum;
	int remain{0},div_res{0};
	if (obj.m_paise >= 100 || m_paise + obj.m_paise >= 100)
	{										//Currency c1(20, 90), c2(50, 60);
		int add = m_paise + obj.m_paise;				//150
		div_res = add / 100;				//1
		remain = add - div_res * 100;		// 150-100
		sum.m_rupees = m_rupees + obj.m_rupees + div_res;
		sum.m_paise = remain;
	}
	else
	{
		sum.m_rupees = m_rupees + obj.m_rupees;
		sum.m_paise = m_paise + obj.m_paise;
	}
	
	return sum;
}

Currency Currency:: operator - (const Currency& obj)
{
	Currency sub;
	int remain, div_res{ 0 };
	if (obj.m_paise >= 100 || m_paise - obj.m_paise >= 100)
	{
		int diff = 100 - m_paise;
		remain = obj.m_paise - diff;
		if (remain >= 100)
		{
			div_res = remain / 100;
			remain = remain - div_res * 100;
		}

		sub.m_rupees = m_rupees - div_res;
		sub.m_paise = m_paise - remain;
	}
	else
	{
		sub.m_rupees = m_rupees - obj.m_rupees;
		sub.m_paise = m_paise - obj.m_paise;
	}

	return sub;
}

Currency Currency:: operator + (int inc_paisa)
{
	Currency sum;
	int remain{ 0 }, div_res{ 0 };
	if (inc_paisa >= 100 || m_paise + inc_paisa >= 100)
	{										//Currency c1(20, 99);;
		int add = m_paise +inc_paisa ;				//99+5 = 104
		div_res = add / 100;				//1
		remain = add - div_res * 100;		// 104-100
		sum.m_rupees = m_rupees  + div_res;
		sum.m_paise = remain;
	}
	else
	{
		sum.m_rupees = m_rupees ;
		sum.m_paise = m_paise + inc_paisa ;
	}

	return sum;
}

Currency Currency:: operator - (int dec_paisa)
{
	Currency dec;
	if (dec_paisa >= 100 || m_paise + dec_paisa >= 100)
	{

		int diff = 100 - m_paise;
		dec_paisa = dec_paisa - diff;

		dec.m_rupees = m_rupees - 1;
		dec.m_paise = m_paise - dec_paisa;
	}
	else
	{
		dec.m_rupees = m_rupees;
		dec.m_paise = m_paise - dec_paisa;
	}
	return dec;
}


Currency& Currency:: operator ++ ()//pre
{
	Currency temp;				//Currency c(25, 30);
	if (m_paise+1 >= 100)
	{
		temp.m_rupees = ++m_rupees;
		temp.m_paise = 0;
	}
	else
	{
		temp.m_rupees = m_rupees;
		temp.m_paise = ++m_paise;
	}
	return temp;
}

Currency Currency:: operator ++ (int dummy)//post
{
	Currency temp(*this);
	if (m_paise+1 >= 100)
	{
		temp.m_rupees = ++m_rupees;
		temp.m_paise = m_paise;
	}
	else
	{
		temp.m_rupees = m_rupees;
		temp.m_paise = m_paise++;
	}
	return temp;
	
}

int Currency:: operator == (const Currency& obj)
{
	Currency temp;
	if (m_rupees == obj.m_rupees && m_paise == obj.m_paise)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int Currency:: operator > (const Currency& obj)
{
	Currency temp;
	if (m_rupees >= obj.m_rupees || m_paise > obj.m_paise)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int Currency:: operator < (const Currency& obj)
{
	Currency temp;
	if (m_rupees <= obj.m_rupees && m_paise < obj.m_paise)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void Currency::display()
{
	cout << "Rupees.Paise = " << m_rupees << ". " <<m_paise<< endl;
}

int Currency::get_mrupees()
{
	return m_rupees;
}
int Currency::get_mpaise()
{
	return m_paise;
}