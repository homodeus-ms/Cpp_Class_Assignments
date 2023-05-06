#include "MyString.h"

using namespace std;

namespace assignment1
{
    MyString::MyString(const char* s)
        : mLength(strlen(s))
    {
        mStr = new char[mLength + 1];
        memcpy(mStr, s, mLength + 1);
    }

    MyString::MyString(const MyString& other)
        : mLength(other.mLength)
    {
        mStr = new char[mLength + 1];
        memcpy(mStr, other.mStr, mLength + 1);
    }

    MyString::~MyString()
    {
        delete[] mStr;
    }

    unsigned int MyString::GetLength() const
    {
        return mLength;
    }

    const char* MyString::GetCString() const
    {
        return mStr;
    }

    void MyString::Append(const char* s)
    {
        if (*s == '\0')
        {
            return;
        }
        char* p = mStr;
        size_t oldLength = mLength;
        size_t sLength = strlen(s);

        mLength += sLength;
        mStr = new char[mLength + 1];
        memcpy(mStr, p, oldLength);
        delete[] p;

        p = mStr + oldLength;
        memcpy(p, s, sLength + 1);
    }

    MyString MyString::operator+(const MyString& other) const
    {
        MyString result(*this);
        result.Append(other.GetCString());

        return result;
    }

    int MyString::IndexOf(const char* s)
    {
        if (*s == '\0')
        {
            return 0;
        }

        char* p = mStr;
        const char* q = s;
        bool bSame = false;
        int result = -1;

        while (*p != '\0')
        {
            char* temp = p;
            
            while (*q != '\0')
            {
                if (*p == *q)
                {
                    p++;
                    q++;
                    bSame = true;
                }
                else
                {
                    bSame = false;
                    q = s;
                    p = temp + 1;
                    break;
                }
            }

            if (*q == '\0' && bSame)
            {
                size_t length = strlen(s);
                result = (p - mStr) - length;
                return result;
            }
            else if (*q == '\0')
            {
                q = s;
                p++;
            }
        }

        return result;
    }

    int MyString::LastIndexOf(const char* s)
    {
        if (*s == '\0')
        {
            return mLength;
        }

        char* p = mStr + mLength - 1;
        size_t sLength = strlen(s);
        const char* q = s + sLength - 1;

        bool bSame = false;
        int result = -1;

        while (p >= mStr)
        {
            char* temp = p;

            while (q >= s)
            {
                if (*p == *q)
                {
                    p--;
                    q--;
                    bSame = true;
                }
                else
                {
                    bSame = false;
                    q = s + sLength - 1;
                    p = temp - 1;
                    break;
                }
            }

            if (q < s && bSame)
            {
                result = (p - mStr) + 1;
                return result;
            }
            else if (q < s)
            {
                q = s + sLength - 1;
                p--;
            }
        }

        return result;
    }

    void MyString::Interleave(const char* s)
    {
        if (*s == '\0')
        {
            return;
        }
        size_t sLength = strlen(s);
        size_t oldLength = mLength;
        mLength += sLength;

        char* newStr = new char[mLength + 1];
        char* p = mStr;
        const char* q = s;
        char* r = newStr;

        while (*p != '\0' || *q != '\0')
        {
            if (*p != '\0')
            {
                *r++ = *p++;
            }
            if (*q != '\0')
            {
                *r++ = *q++;
            }
        }
        *r = '\0';

        delete[] mStr;
        mStr = newStr;
    }

    bool MyString::RemoveAt(unsigned int i)
    {
        if (i >= mLength)
        {
            return false;
        }

        char* newStr = new char[mLength];

        char* p = mStr;
        char* q = newStr;
        q[mLength - 1] = '\0';

        while (*q != '\0')
        {
            if ((p - mStr) == i)
            {
                p++;
                continue;
            }
            *q++ = *p++;
        }

        delete[] mStr;
        mStr = newStr;
        mLength--;

        return true;
    }

    void MyString::PadLeft(unsigned int totalLength)
    {
        if (totalLength <= mLength)
        {
            return;
        }
        size_t padLength = totalLength - mLength;
        mLength = totalLength;

        char* newStr = new char[mLength + 1];
        char* p = mStr;
        char* q = newStr;

        size_t i;

        for (i = 0; i < padLength; ++i)
        {
            *q++ = ' ';
        }
        for (i; i < totalLength; ++i)
        {
            *q++ = *p++;
        }
        *q = '\0';

        delete[] mStr;
        mStr = newStr;
    }

    void MyString::PadLeft(unsigned int totalLength, const char c)
    {
        if (totalLength <= mLength)
        {
            return;
        }
        size_t padLength = totalLength - mLength;
        mLength = totalLength;

        char* newStr = new char[mLength + 1];
        char* p = mStr;
        char* q = newStr;

        size_t i;

        for (i = 0; i < padLength; ++i)
        {
            *q++ = c;
        }
        for (i; i < totalLength; ++i)
        {
            *q++ = *p++;
        }
        *q = '\0';

        delete[] mStr;
        mStr = newStr;
    }

    void MyString::PadRight(unsigned int totalLength)
    {
        if (totalLength <= mLength)
        {
            return;
        }
        
        char* newStr = new char[totalLength + 1];
        char* p = mStr;
        char* q = newStr;

        size_t i;
        for (i = 0; i < mLength; ++i)
        {
            *q++ = *p++;
        }
        for (i; i < totalLength; ++i)
        {
            *q++ = ' ';
        }
        *q = '\0';
        mLength = totalLength;

        delete[] mStr;
        mStr = newStr;
    }

    void MyString::PadRight(unsigned int totalLength, const char c)
    {
        if (totalLength <= mLength)
        {
            return;
        }

        char* newStr = new char[totalLength + 1];
        char* p = mStr;
        char* q = newStr;

        size_t i;
        for (i = 0; i < mLength; ++i)
        {
            *q++ = *p++;
        }
        for (i; i < totalLength; ++i)
        {
            *q++ = c;
        }
        *q = '\0';
        mLength = totalLength;

        delete[] mStr;
        mStr = newStr;
    }

    void MyString::Reverse()
    {
        char* p = mStr;
        char* q = mStr + mLength - 1;

        while (p < q)
        {
            char temp = *p;
            *p = *q;
            *q = temp;
            p++;
            q--;
        }
    }

    bool MyString::operator==(const MyString& rhs) const
    {
        char* p = mStr;
        char* q = rhs.mStr;

        while (*p != '\0')
        {
            if (*p++ != *q++)
            {
                return false;
            }
        }

        return *q == '\0' ? true : false;
    }
    
    MyString& MyString::operator=(const MyString& rhs)
    {
        mLength = rhs.mLength;

        char* newStr = new char[mLength + 1];
        memcpy(newStr, rhs.mStr, mLength + 1);
        delete[] mStr;
        mStr = newStr;

        return *this;
    }
    
    void MyString::ToLower()
    {
        char* p = mStr;

        while (*p != '\0')
        {
            char c = *p;

            if (c >= 'A' && c <= 'Z')
            {
                *p = c ^ 0b100000;
            }
            p++;
        }
    }

    void MyString::ToUpper()
    {
        char* p = mStr;

        while (*p != '\0')
        {
            char c = *p;
            if (c >= 'a' && c <= 'z')
            {
                *p = c ^ 0b100000;
            }
            p++;
        }
    }

    size_t MyString::strlen(const char* str)
    {
        const char* p = str;
        while (*p++ != '\0')
        {
        }
        return p - str - 1;
    }
    void MyString::memcpy(char* dest, const char* origin, size_t length)
    {
        char* p = dest;
        const char* q = origin;

        for (size_t i = 0; i < length; ++i)
        {
            *p++ = *q++;
        }
    }
}