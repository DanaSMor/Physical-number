#include <iostream>
#include "Unit.h"
namespace ariel {
class PhysicalNumber{
private:
double num;
Unit unit;   
    
public:

    PhysicalNumber(double number, Unit u)
    {
        num=number;
        unit=u;
    }

PhysicalNumber operator+(const PhysicalNumber& num2) const;
PhysicalNumber& operator+();
PhysicalNumber& operator+=(const PhysicalNumber& num2);
PhysicalNumber operator-(const PhysicalNumber& num2)const;
PhysicalNumber& operator-=(const PhysicalNumber& num2);
PhysicalNumber& operator-();
double getNum();


private:
bool sameUnit(const PhysicalNumber& num2)const;
bool sameType(const PhysicalNumber& num2)const;
int getUnit()const;
double convert(int type,double num)const;
double convertLength()const;
double convertTime()const;
double convertWeight()const;
double cmToM(double number)const;
double cmToKM(double number)const;
double sToMIN(double number)const;
double sToHOUR(double number)const;
double gToKG(double number)const;
double gToTON(double number)const;
};
}