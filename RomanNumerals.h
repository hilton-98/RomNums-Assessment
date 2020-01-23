#ifndef ROMAN_NUMERALS_H
#define ROMAN_NUMERALS_H

class RomanNumerals 
{
private:
	char symbol;
	unsigned int value;
public:
	RomanNumerals(const char s, const unsigned int v)
	{
		symbol = s;
		value = v;
	}
	const char GetSymbol() 
	{
		return symbol;
	}
	const unsigned int GetValue() 
	{
		return value;
	}
};




#endif //already defined