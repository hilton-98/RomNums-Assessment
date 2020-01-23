#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "RomanNumerals.h"

using namespace std;

//Returns the appropriate Roman Numerals for the ones place.
string OnesPlace(const char& o)
{
	string ones = "";
	switch (o)
	{
	case '1':
		ones = "I";
		break;
	case '2':
		ones = "II";
		break;
	case '3':
		ones = "III";
		break;
	case '4':
		ones = "IV";
		break;
	case '5':
		ones = "V";
		break;
	case '6':
		ones = "VI";
		break;
	case '7':
		ones = "VII";
		break;
	case '8':
		ones = "VIII";
		break;
	case '9':
		ones = "IX";
		break;
	}
	return ones;
}

//Returns the appropriate Roman Numerals for the tens place.
string TensPlace(const char& t)
{
	string tens = "";
	switch (t)
	{
	case '1':
		tens = "X";
		break;
	case '2':
		tens = "XX";
		break;
	case '3':
		tens = "XXX";
		break;
	case '4':
		tens = "XL";
		break;
	case '5':
		tens = "L";
		break;
	case '6':
		tens = "LX";
		break;
	case '7':
		tens = "LXX";
		break;
	case '8':
		tens = "LXX";
		break;
	case '9':
		tens = "XC";
		break;
	}
	return tens;
}

//Returns the appropriate Roman Numerals for the hundreds place.
string HundredsPlace(const char& h)
{
	string hundreds = "";
	switch (h)
	{
	case '1':
		hundreds = "C";
		break;
	case '2':
		hundreds = "CC";
		break;
	case '3':
		hundreds = "CCC";
		break;
	case '4':
		hundreds = "CD";
		break;
	case '5':
		hundreds = "D";
		break;
	case '6':
		hundreds = "DC";
		break;
	case '7':
		hundreds = "DCC";
		break;
	case '8':
		hundreds = "DCCC";
		break;
	case '9':
		hundreds = "CM";
		break;
	}
	return hundreds;
}

//Returns the appropriate Roman Numerals for the thousands place.
string ThousandsPlace(const char& th)
{
	string thousands = "";
	switch (th)
	{
	case '1':
		thousands = "M";
		break;
	case '2':
		thousands = "MM";
		break;
	case '3':
		thousands = "MMM";
		break;
	}
	return thousands;
}

//Populates the RomNums vector with all possible symbols in Roman Numeral system.
void populateRomNums(vector<RomanNumerals>& rn)
{
	RomanNumerals I('I', 1);
	RomanNumerals V('V', 5);
	RomanNumerals X('X', 10);
	RomanNumerals L('L', 50);
	RomanNumerals C('C', 100);
	RomanNumerals D('D', 500);
	RomanNumerals M('M', 1000);
	rn.push_back(I);
	rn.push_back(V);
	rn.push_back(X);
	rn.push_back(L);
	rn.push_back(C);
	rn.push_back(D);
	rn.push_back(M);
	return;
}

//Prints all the Roman Numeral symbols
const void printRomNums(vector<RomanNumerals>& rn)
{
	for (unsigned int i = 0; i < rn.size(); i++)
	{
		cout << rn.at(i).GetSymbol() << " " << rn.at(i).GetValue() << endl;
	}
}

//Checks that the user's input symbols are all roman numeral symbols.
bool isValid(vector<RomanNumerals>& rn, string t)
{
	bool val = false;
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < rn.size(); j++)
		{
			if (t.at(i) == rn.at(j).GetSymbol())
			{
				val = true;
			}
		}
		if (!val) {
			return false;
		}
		val = false;
	}
	return true;
}

//Prints off the values of the Roman Numeral symbols.
void printValues(vector<int>& v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << endl;
	}
}

//Returns an integer equal to the order of magnitude of any integer x.
const unsigned int orderOfMagnitude(unsigned int x)
{
	unsigned int order = 1;
	const int MAX_SIZE_ROMNUM = 4;
	for (unsigned int i = 0; i < MAX_SIZE_ROMNUM; i++) 
	{
		if (order * 10 > x)
		{
			return i + 1;
		}
		else
		{
			order *= 10;
		}
	}
}

int main() {

	cout << "Welcome to the Roman Numeral Translator!" << endl << endl;

	unsigned int whichWay = 0;
	string translateThis = "";
	vector<RomanNumerals> RomNums;

	populateRomNums(RomNums);
	//printRomNums(RomNums);

	while (translateThis != "STOP")
	{

		cout << "Enter a 0 to translate an Arabic Number to Roman Numerals. Enter 1 to translate a Roman Numeral to Arabic Numbers." << endl;
		cin >> whichWay;
		if (cin.fail() || whichWay > 1)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input." << endl;
			continue;
		}

		if (whichWay == 0) //translates from Arabic to Roman
		{
			unsigned int myNum = 0;
			string romans = "";
			cout << "Which Arabic Number would you like to translate?  Your number must be less than 4000. (Enter STOP to finish)" << endl;
			cin >> translateThis;

			if (translateThis == "STOP") //Stopping condition
			{
				cout << "Finished!  Have a nice day!" << endl;
				break;
			}

			istringstream tT(translateThis);
			tT >> myNum;

			if (myNum > 3999)
			{
				cout << "Too big of a number!" << endl;
				continue;
			}

			for (unsigned int i = 0; i < translateThis.size(); i++)
			{
				if (translateThis.size() == i + 4)
				{
					romans += ThousandsPlace(translateThis.at(i));
					continue;
				}
				if (translateThis.size() == i + 3)
				{
					romans += HundredsPlace(translateThis.at(i));
					continue;
				}
				if (translateThis.size() == i + 2)
				{
					romans += TensPlace(translateThis.at(i));
					continue;
				}
				if (translateThis.size() == i + 1)
				{
					romans += OnesPlace(translateThis.at(i));
					continue;
				}
			}

			if (romans == "")
			{
				cout << "Must be a number!" << endl;
				continue;
			}

			cout << "This is the Roman Numeral for your number: " << romans << endl;
		}


		if (whichWay == 1) //translates from Roman to Arabic
		{
			unsigned int total = 0;
			bool found = false;
			bool orderMag = true;

			cout << "Which Roman Numeral would you like to translate? (Enter STOP to finish)" << endl;
			cin >> translateThis;

			if (translateThis == "STOP") //Stopping condition
			{
				cout << "Finished!  Have a nice day!" << endl;
				break;
			}


			if (!isValid(RomNums, translateThis)) //Checks that a user's input contains valid symbols
			{
				cout << "Does not exist." << endl;
				continue;
			}

			vector<int> values; //Populates a values vector with the value of each symbol
			for (unsigned int i = 0; i < translateThis.size(); i++) 
			{
				for (unsigned int j = 0; j < RomNums.size(); j++)
				{
					if (translateThis.at(i) == RomNums.at(j).GetSymbol())
					{
						values.push_back(RomNums.at(j).GetValue());
					}
				}
			}

			//printValues(values);

			for (unsigned int i = 0; i < values.size(); i++)
			{
				if ((values.size() - 1) == i) //Last number case, adds to total
				{
					total += values.at(i);
				}
				else if (values.at(i) < values.at(i + 1)) //Case of subtraction, checks for order of magnitude and then adds appropriate value of both to the total.
				{
					if (orderOfMagnitude(values.at(i + 1)) - orderOfMagnitude(values.at(i)) > 1)
					{
						orderMag = false;
						continue;
					}
					total += values.at(i + 1) - values.at(i);
					i++;
				}
				else
				{
					total += values.at(i); //Normal number case, adds to total.
				}
			}
			if (!orderMag)
			{
				cout << "Does not exist, check your orders of magnitude!" << endl;
				continue;
			}
			cout << "Value of the Roman Numeral is: " << total << endl;
		}
	}
	return 0;
}