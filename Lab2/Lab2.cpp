#include "Lab2.h"

void lab2::PrintIntegers(istream& in, ostream& out)
{
	out << setw(12) << "oct" << setw(11) << "dec" << setw(9) << "hex" << endl << setfill('-') << setw(13) << ' ' << setw(11) << ' ' << setw(9) << '\n' << setfill(' ');

	int input;
	string trash;

	while (!in.eof())
	{
		in >> input;

		if (!in.fail())
		{
			out << setw(12) << oct << input << setw(11) << dec << input << setw(9) << hex << uppercase << input << endl;
		}
		else
		{
			in.clear();
			in >> trash;
		}
	}
}

void lab2::PrintMaxFloat(istream& in, ostream& out)
{
	float input;
	float max = LLONG_MIN;
	string trash;

	out << fixed << setprecision(3);

	while (!in.eof())
	{
		in >> input;

		if (max < input)
		{

			max = input;

		}

		if (!in.fail())
		{
			if (input < 0)
			{
				out << setw(6) << '-';
			}
			else
			{
				out << setw(6) << '+';
			}
			out << setw(14) << abs(input) << endl;
		}
		else
		{
			in.clear();
			in >> trash;
		}
	}

	if (max < 0)
	{
		out << "max:" << setw(2) << '-';
	}
	else
	{
		out << "max:" << setw(2) << '+';
	}
	out << setw(14) << abs(max) << endl;
}