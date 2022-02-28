#pragma once

class hyperbolaCalc
{
public:



private:

	int num = 0; // numerator whole number
	bool numVa = false; // numerator variable
	int numEx = 0; // exponent of variable in numerator if numerator has variable

	int denom = 0; // denominator whole number
	bool denomVa = false; // denominator variable
	int denomEx = 0; // exponent of variable in denominator if denominator has variable

	int k = 0; // k value if present

	bool denomFactor = false; // is denomonator a factor?
	int a; // factor a value
	int b; // factor b value
	int c; // factor c value


};