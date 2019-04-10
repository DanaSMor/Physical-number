#include <iostream>

#include "PhysicalNumber.h"
using namespace ariel;
using namespace std;

//global arrays
char units[9][5] = {"cm", "m", "km", "sec", "min", "hour", "g", "kg", "ton"};
int arr[9]={1,100,100000,1,60,3600,1,1000,1000000};

PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &num2) const
{
    if (!sameUnit(num2))
    {throw std::runtime_error("not the same units");}
    //same unit different type
    double fin=num+num2.num*arr[num2.unit]/arr[unit];
    return PhysicalNumber(fin, unit);
}

PhysicalNumber &PhysicalNumber::operator+()
{
    return *this;
}
PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &num2)
{
    PhysicalNumber a = *this + num2;
    num = a.getNum();
    return *this;
}
PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &num2) const
{
    return *this + PhysicalNumber((-1 * num2.num), num2.unit);
}
PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber &num2)
{
    PhysicalNumber a = *this - num2;
    num = a.getNum();
    return *this;
}
PhysicalNumber PhysicalNumber::operator-() const
{
    return PhysicalNumber(num * -1, unit);
}
PhysicalNumber& PhysicalNumber::operator++()
{
    num++;
    return *this;
}
PhysicalNumber PhysicalNumber::operator++(int)
{
    PhysicalNumber pn(*this);
    num++;
    return pn;
}
PhysicalNumber& PhysicalNumber::operator--()
{
    num--;
    return *this;
}
PhysicalNumber PhysicalNumber::operator--(int)
{

    PhysicalNumber pn(*this);
    num--;
    return pn;
}

bool PhysicalNumber::operator<(const PhysicalNumber &num2) const
{
    if (!sameUnit(num2))
    {
        throw std::runtime_error("not the same units");
    }
    double fin=num2.num*arr[num2.unit]/arr[unit];
    return num < fin;
}
bool PhysicalNumber::operator<=(const PhysicalNumber &num2) const
{
    return (*this == num2 || *this < num2);
}
bool PhysicalNumber::operator>(const PhysicalNumber &num2) const
{
    return (num2 < *this);
}
bool PhysicalNumber::operator>=(const PhysicalNumber &num2) const
{
    return (*this == num2 || *this > num2);
}
bool PhysicalNumber::operator!=(const PhysicalNumber &num2) const
{
    return !(*this == num2);
}
bool PhysicalNumber::operator==(const PhysicalNumber &num2) const
{
    if (!sameUnit(num2))
    {
        throw std::runtime_error("not the same units");
    }
    double fin=num2.num*arr[num2.unit]/arr[unit];
    return num == fin;
}
//friends

std::ostream &ariel::operator<<(ostream &os, const PhysicalNumber &pn)
{
    return (os << pn.getNum() << "[" << units[pn.unit] << "]");
}

static istream &getAndCheckNextCharIs(istream &input, char expectedChar)
{
    char actualChar;
    input >> actualChar;
    if (!input)
        return input;

    if (actualChar != expectedChar)
        // failbit is for format error
        input.setstate(ios::failbit);
    return input;
}

std::istream &ariel::operator>>(istream &input, PhysicalNumber &pn)
{
    int i=0;
    double new_num;
    string new_unit;

    // remember place for rewinding
    ios::pos_type startPosition = input.tellg();


    if ((!(input >> new_num)) ||
        (!getAndCheckNextCharIs(input, '[')) ||
        (!(input >> new_unit)))// ||
        //(!(getAndCheckNextCharIs(input, ']'))))
    {
        // rewind on error
        auto errorState = input.rdstate(); // remember error state
        input.clear();                     // clear error so seekg will work
        input.seekg(startPosition);        // rewind
        input.clear(errorState);           // set back the error flag
    }
    else
    {
        if(!(new_unit.find(']')>new_unit.length()))
        {bool flag=false;
        for (i = 0; i < 9; i++)
        {
            if ((units[i]==new_unit.substr(0,new_unit.size()-1))&&new_unit.compare(units[i])==1)
            {
                flag = true;
                break;
            }        
        }
        if(flag)
        {pn.num = new_num;       
        pn.unit=Unit(i);
        }
        }
    }
    return input;
}
double PhysicalNumber::getNum() const {return num;}
////////private methods///////
bool PhysicalNumber::sameUnit(const PhysicalNumber &num2) const
{
    return (unit / 3 == num2.unit / 3);
}