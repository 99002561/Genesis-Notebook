//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "pch.h"
#include<iostream>
mytime::mytime():h(12),m(0),s(0){ }

mytime::mytime(int a, int b, int c):h(a),m(b),s(c){ }
mytime::mytime(int a, int b):h(a),m(b),s(0){ }
mytime mytime::operator+(const mytime& t1)
{
	mytime temp;
	int hrs,min, sec,rem,rem1;
	sec = t1.s + s+t1.m*60+m*60+t1.h*3600+h*3600;
	hrs = sec / 3600;
	rem = sec-(3600*hrs);
	min = rem / 60;
	rem1 = rem - (60 * min);
	temp.h = hrs;
	temp.m = min;
	temp.s = rem1;
	return temp;


}
mytime mytime::operator-(const mytime& t2)
{
	mytime temp;
	int hrs = 0, min = 0, sec1 = 0,sec2 = 0,sec = 0,diff = 0,rem = 0,rem1 = 0;
	sec1 = h * 3600 + m * 60 + s;
	sec2 = t2.h * 3600 + t2.m * 60 + t2.s;
	if (sec1 > sec2)
		diff = sec1 - sec2;
	else
		diff=sec2 - sec1;
	sec = diff;
	hrs = sec / 3600;
	rem = sec - (3600 * hrs);
	min = rem / 60;
	rem1 = rem - (60 * min);
	temp.h = hrs;
	temp.m = min;
	temp.s = rem1;
	return temp;

}

mytime mytime::operator+(int d)
{
	mytime temp;
	int hrs=h, min = m, sec1 = 0, sec2 = 0, sec = 0, diff = 0, rem = 0, rem1 = 0;
	sec = s + d;
	if (sec >= 60)
	{
		min = min + 1;
		sec = sec%60;
		if (min >= 60)
		{
			hrs = hrs + 1;
			min = min%60;
		}
	}
	temp.h = hrs;
	temp.m = min;
	temp.s = sec;
	return temp;


}
mytime mytime::operator-(int d)
{
	mytime temp;
	int hrs=h, min=m, sec1, sec2, sec=s, diff, rem, rem1;
	if (sec == 0)
	{
		sec = 60 - d;
		min = min - 1;
		if (min <= 0)
		{
			min = 60 - 1;
			hrs = hrs - 1;
		}
	}
	temp.h = hrs;
	temp.m = min;
	temp.s = sec;
	return temp;
}
mytime mytime::operator++(int dummy)
{
	mytime temp;
	int hrs, min, sec, rem, rem1;
	temp.h = h;
	temp.m = m;
	temp.s = s;
	sec =  s +  m * 60 + h * 3600+1;
	hrs = sec / 3600;
	rem = sec - (3600 * hrs);
	min = rem / 60;
	rem1 = rem - (60 * min);
	if (rem1 >= 60)
	{
		min = min + 1;
		sec = sec % 60;
		if (min >= 60)
		{
			hrs = hrs + 1;
			min = min % 60;
		}
	}
	h = hrs;
	m = min;
	s = rem1;
	//rem1 = rem1 + 1;
	return temp;

}
mytime mytime::operator++()
{
	mytime temp;
	//int hrs=h, min=m, sec=s, rem, rem1;
	s= s + 1;
	if (s >= 60)
	{
		m = m + 1;
		s = s % 60;
		if (m >= 60)
		{
			h = h + 1;
			m = m % 60;
		}
	}
		temp.h = h;
		temp.m = m;
		temp.s = s;
		//rem1 = rem1 + 1;
		return temp;
	
}
	bool mytime::operator==(const mytime& p)
	{
		if (h == p.h && m == p.m && s == p.s)
			return true;
		else
			return false;
	}
	bool mytime::operator<(const mytime& p)
	{
		if (h < p.h)

			return true;
		else
			if (m < p.m)
				return true;
			else
				if (s < p.s)
					return true;
				else
					return false;
		

}
	bool mytime::operator>(const mytime& p)
	{
		if (h > p.h)

			return true;
		else
			if (m > p.m)
				return true;
			else
				if (s > p.s)
					return true;
				else
					return false;
}
	void mytime::display()
	{
		std::cout<<"time is " << geth() << ":" << getm() << ":" << getsec();
}
	int mytime::geth()
	{
		return h;
}
	int mytime::getm()
	{
		return m;
	}
	int mytime::getsec()
	{
		return s;
	}