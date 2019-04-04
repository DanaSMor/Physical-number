#include <iostream>

#include "PhysicalNumber.h"
using namespace ariel;
using namespace std;

char units[9][5] = {"cm", "m", "km", "sec", "min", "hour", "g", "kg", "ton"};

PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &num2) const
{
    if (!sameUnit(num2))
    {
        throw std::runtime_error("not the same units");
    }
    if (sameType(num2)) //in case they are the same type
    {
        return PhysicalNumber(num + num2.num, unit);
    }
    //same unit different type
    int originalUnit = getUnit();
    double conNum1, conNum2;
    switch (originalUnit)
    {
    //length
    case 0:
    {
        conNum1 = convertLength();
        conNum2 = num2.convertLength();
    }
    break;
    case 1:
    { //time
        conNum1 = convertTime();
        conNum2 = num2.convertTime();
    }
    break;
    case 2:
    { //weight
        conNum1 = convertWeight();
        conNum2 = num2.convertWeight();
    }
    break;
    }
    return PhysicalNumber(convert(unit, conNum1 + conNum2), unit);
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

bool PhysicalNumber::operator<(const PhysicalNumber &num2) const
{
    if (!sameUnit(num2))
    {
        throw std::runtime_error("not the same units");
    }
    //same unit different type
    int originalUnit = getUnit();
    double conNum1, conNum2;
    switch (originalUnit)
    {
    //length
    case 0:
    {
        conNum1 = convertLength();
        conNum2 = num2.convertLength();
    }
    break;
    case 1:
    { //time
        conNum1 = convertTime();
        conNum2 = num2.convertTime();
    }
    break;
    case 2:
    { //weight
        conNum1 = convertWeight();
        conNum2 = num2.convertWeight();
    }
    break;
    }
    return conNum1 < conNum2;
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
    if (sameType(num2)) //in case they are the same type
    {
        return num == num2.getNum();
    }
    //same unit different type
    int originalUnit = getUnit();
    double conNum1, conNum2;
    switch (originalUnit)
    {
    case 0:
    { //length
        conNum1 = convertLength();
        conNum2 = num2.convertLength();
    }
    break;
    case 1:
    { //time
        conNum1 = convertTime();
        conNum2 = num2.convertTime();
    }
    break;
    case 2:
    { //weight
        conNum1 = convertWeight();
        conNum2 = num2.convertWeight();
    }
    break;
    }
    return conNum1 == conNum2;
}
//friends

std::ostream &ariel::operator<<(ostream &os, const PhysicalNumber &pn)
{
    return (os << pn.getNum() << "[" << units[pn.getSpecificUnit()] << "]");
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
        cout<<"new num"<<new_num<<endl;
        
        
        cout<<new_unit<<endl;
        // rewind on error
        auto errorState = input.rdstate(); // remember error state
        input.clear();                     // clear error so seekg will work
        input.seekg(startPosition);        // rewind
        input.clear(errorState);           // set back the error flag
    }
    else
    {
        for (i = 0; i < 9; i++)
        {
            if (units[i]==new_unit.substr(0,new_unit.size()-1))
            {
                //flag = true;
                break;
            }
            
        }
        pn.num = new_num;       
        pn.unit=Unit(i);

    }

    return input;
}

double PhysicalNumber::getNum() const
{
    return num;
}
int PhysicalNumber::getSpecificUnit() const
{
    return unit;
}
////////private methods///////

bool PhysicalNumber::sameUnit(const PhysicalNumber &num2) const
{
    return (unit / 3 == num2.unit / 3);
}
bool PhysicalNumber::sameType(const PhysicalNumber &num2) const
{
    return unit == num2.unit;
}
//function that checks the type of the unit
//0-length, 1-time, 2-weight
int PhysicalNumber::getUnit() const
{
    return unit / 3;
}

double PhysicalNumber::convert(int type, double n) const
{
    switch (type)
    {
    case 0:
        return n;
        break;
    case 1:

        return cmToM(n);
        break;
    case 2:
        return cmToKM(n);
        break;
    case 3:
        return n;
        break;
    case 4:
        return sToMIN(n);
        break;
    case 5:

        return sToHOUR(n);
        break;
    case 6:
        return n;
        break;
    case 7:
        return gToKG(n);
        break;
    case 8:
        return gToTON(n);
        break;

    default:
        break;
    }
}

double PhysicalNumber::convertLength() const
{
    double convertNum = 0;
    switch (unit)
    {
    case 0:
        convertNum = num;
        break;
    case 1:
        convertNum = num * 100;
        break;
    case 2:
        convertNum = num * 100000;

        break;
    }
    return convertNum;
}

double PhysicalNumber::convertTime() const
{
    double convertNum = 0;
    switch (unit)
    {
    case 3:
        convertNum = num;
        break;
    case 4:
        convertNum = num * 60;
        break;
    case 5:
        convertNum = num * 3600;
        break;
    }
    return convertNum;
}
double PhysicalNumber::convertWeight() const
{
    double convertNum = 0;
    switch (unit)
    {
    case 6:
        convertNum = num;
        break;
    case 7:
        convertNum = num * 1000;
        break;
    case 8:
        convertNum = num * 1000000;
        break;
    }
    return convertNum;
}

double PhysicalNumber::cmToM(double number) const { return number / 100; }
double PhysicalNumber::cmToKM(double number) const { return number / 100000; }
double PhysicalNumber::sToMIN(double number) const { return number / 60; }
double PhysicalNumber::sToHOUR(double number) const { return number / 3600; }
double PhysicalNumber::gToKG(double number) const { return number / 1000; }
double PhysicalNumber::gToTON(double number) const { return number / 100000; }
