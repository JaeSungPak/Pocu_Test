#include "Lab2.h"

using namespace std;

namespace lab2
{
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
        cout << setw(12) << "oct" << setw(11) << "dec" << setw(9) << "hex" << endl << 
            setfill('-') << setw(13) << ' ' << setw(12) << ' ' << setw(10) << '\n' << setfill(' ');

        int input;
        string trash;

        while (!in.eof()) {

            in >> input;

            if (!in.fail())
            {
                cout << setw(12) << oct << input << setw(11) << dec << input << setw(9) << hex << uppercase << input << endl;
            }
            else
            {
                in.clear();
                in >> trash;
            }
        }
    }


    void PrintMaxFloat(std::istream& in, std::ostream& out)
    {
        float input;
        float max = LLONG_MIN;
        string trash;

        cout << fixed << setprecision(3);

        while (!in.eof()) {

            in >> input;

            if (!in.fail())
            {
                if (input < 0) 
                {
                    cout << setw(6) << '-';
                    input = -input;
                }
                else
                {
                    cout << setw(6) << '+';
                }

                cout << setw(14) << input << endl;

                if (max < input)
                {

                    max = input;

                }
            }
            else
            {
                in.clear();
                in >> trash;
            }

        }

        if (max < 0)
        {
            cout << "max:" << setw(2) << '-';
            max = -max;
        }
        else
        {
            cout << "max:" << setw(2) << '+';
        }

        cout << setw(14) << max << endl;

    }
}