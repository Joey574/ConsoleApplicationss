#pragma once

class hyperbolaCalc
{
public:
	void setNum(int n);
	void setNumVa(bool n);
	void setNumEx(int n);

	void setDenom(int d);
	void setDenomVa(bool d);
	void setDenomEx(int d);

	void setK(int k);

private:

	int num = 0; // numerator whole number
	bool numVa = false; // numerator variable
	int numEx = 0; // exponent of variable in numerator if numerator has variable

	int denom = 0; // denominator whole number
	bool denomVa = false; // denominator variable
	int denomEx = 0; // exponent of variable in denominator if denominator has variable

	int k = 0; // k value if present

	bool numFactor = false; // is numerator a factor?
	bool denomFactor = false; // is denomonator a factor?

	int numA; // num a value
	int numB; // num b value
	int numC; // num c value

	int 

};

void hyperbolaCalc::setNum(int n)
{
	num = n;
}

void hyperbolaCalc::setNumVa(bool n)
{
	numVa = n;
}

void hyperbolaCalc::setNumEx(int n)
{
	numEx = n;
}