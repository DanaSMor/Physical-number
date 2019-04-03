#include <iostream>

#include "PhysicalNumber.h"
using namespace ariel;
using namespace std;

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
        case 0:{
        conNum1 = convertLength();
        conNum2 = num2.convertLength();
        return PhysicalNumber(convert(unit,conNum1 + conNum2), unit);
        }
        break;
        case 1:{//time
        conNum1 = convertTime();
        conNum2 = num2.convertTime();
        cout << "first app:"<<conNum1 + conNum2<< endl;
        return PhysicalNumber(convert(unit,conNum1 + conNum2), unit);
        }
        break;
        case 2:{//weight
        conNum1 = convertWeight();
        conNum2 = num2.convertWeight();
        return PhysicalNumber(convert(unit,conNum1 + conNum2), unit);
        }
        break;
    }
}

PhysicalNumber& PhysicalNumber::operator+() 
{
    return *this;
}
PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber &num2)
{
    PhysicalNumber a=*this+num2;
    num=a.getNum();    
    return *this;
}
PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &num2) const
{
    return *this + PhysicalNumber((-1 * num2.num), num2.unit);
}
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber &num2)
{
    PhysicalNumber a=*this-num2;
    num=a.getNum(); 
    return *this; 
}
PhysicalNumber& PhysicalNumber::operator-() 
{
    num=num*-1;
}

////////private methods///////
double PhysicalNumber::getNum()
{return num;}
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
{return unit/3;}

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
double PhysicalNumber::cmToKM(double number) const { return number / 10000; }
double PhysicalNumber::sToMIN(double number) const { return number / 60; }
double PhysicalNumber::sToHOUR(double number) const { return number / 3600; }
double PhysicalNumber::gToKG(double number) const { return number / 1000; }
double PhysicalNumber::gToTON(double number) const { return number / 100000; }
