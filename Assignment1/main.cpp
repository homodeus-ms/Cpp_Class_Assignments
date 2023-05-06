#include "MyString.h"
#include <iostream>


using namespace std;
using namespace assignment1;


int main()
{
    MyString a("1111");

    MyString b("");

    a.Interleave("abcd");

    
    //cout << a.GetCString() << " " << b.GetCString() << " " << bBool << endl;

    //cout << a.GetLength() << " " << a.GetCString() << "||" << endl;
    
    
    cout << "Length : " << a.GetLength() << " string : " << a.GetCString() << endl;
    //cout << "Length : " << b.GetLength() << " string : " << b.GetCString() << endl;
    //cout << "Length : " << c.GetLength() << " string : " << c.GetCString() << endl;

    

    return 0;
}