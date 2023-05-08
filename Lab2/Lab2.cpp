#include "Lab2.h"

using namespace std;

namespace lab2
{
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
        const char* name1 = "oct";
        const char* name2 = "dec";
        const char* name3 = "hex";

        const size_t widthOct = 12;
        const size_t widthDec = 10;
        const size_t widthHex = 8;

        out << right << uppercase;
        out << setw(widthOct) << name1 << " " << setw(widthDec) << name2  << " " << setw(widthHex) << name3 << endl;
        out << setfill('-');
        out << setw(widthOct) << "" << " " << setw(widthDec) << '-' << " " << setw(widthHex) << '-' << endl << setfill(' ');

        int number;
        std::string trash;

        while (!in.eof())
        {
            in >> number;
            if (!in.fail())
            {
                out << setw(widthOct) << oct << number << " "
                    << setw(widthDec) << dec << number << " "
                    << setw(widthHex) << hex << number << endl;
                continue;
            }
            else if (in.eof())
            {
                break;
            }
            in.clear();
            in >> trash;
        }

    }

    void PrintMaxFloat(std::istream& in, std::ostream& out)
    {
        const size_t width1 = 5;
        const size_t width2 = 15;

        float number;
        float maxNum;
        bool bWritten = false;
        string trash;

        while (!in.eof())
        {
            in >> number;

            if (!in.fail())
            {
                if (bWritten == false)
                {
                    bWritten = true;
                    maxNum = number;
                }
                else
                {
                    maxNum = maxNum > number ? maxNum : number;
                }
                
                out << showpos << showpoint << fixed << internal << setprecision(3);
                out << setw(width1) << "" << setw(width2) << number << endl;
                continue;
            }
            else if (in.eof())
            {
                break;
            }
            in.clear();
            in >> trash;
        }
        if (bWritten == true)
        {
            out << "max: " << setw(width2) << maxNum << endl;
        }

    }
}