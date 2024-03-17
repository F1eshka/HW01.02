#include "Fraction.h"
#include <string>
class Date
{
        unsigned short day;
        unsigned short month;
        long long year;
        unsigned short oneday = 1;
    public:

        Date();

        Date(unsigned short day, unsigned short month, long long year);
        Date(unsigned short day, unsigned short month) : Date(day, month, 2006) {};

        void PrintDate() const;
        void SetDay(unsigned short day);
        unsigned short GetDay() const;
        void SetMonth(unsigned short month);
        unsigned short GetMonth() const;
        void SetYear(long long year);
        long long GetYear() const;

        Date& operator ++ ()
        {
            this->day += this->oneday;
            return *this;
        }

        Date operator ++ (int a)
        {
            Date copy = *this;
            this->day += this->oneday;
            return copy;
        }

        Date& operator -- ()
        {
            this->day -= this->oneday;
            return *this;
        }

        Date operator -- (int a)
        {
            Date copy = *this;
            this->day -= this->oneday;
            return copy;
        }

        Date operator += (int a)
        { 
            Date copy = *this;
            this->day += a;
            return copy;
        }
    }; 



