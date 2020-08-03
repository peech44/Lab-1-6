#pragma once
#include <iostream>
#ifndef FRACTION_H
#define FRACTION_H


using namespace std;

class fraction
{
public:
	fraction();  //constructor

	fraction(int newnum, int newdenom);

	void setnum(int newnum); // mutators

	void setdenom(int newdenom);

	//set lower fraction
	friend fraction setlower(fraction& f);

	int getnum();    //accessors

	int getdenom();

	//show out put fraction
	void show(int i);

	friend bool operator ==(fraction f1, fraction f2);
	friend bool operator !=(fraction f1, fraction f2);
	friend bool operator >(fraction f1, fraction f2);
	friend bool operator <(fraction f1, fraction f2);
	friend bool operator >=(fraction f1, fraction f2);
	friend bool operator <=(fraction f1, fraction f2);
	friend fraction operator +(fraction f1, fraction f2);
	friend fraction operator -(fraction f1, fraction f2);
	friend fraction operator *(fraction f1, fraction f2);
	friend fraction operator /(fraction f1, fraction f2);
	friend fraction operator ++(fraction& f1);
	friend fraction operator --(fraction& f1);

private:
	int num;
	int denom;

};

#endif // !FRACTION_H
