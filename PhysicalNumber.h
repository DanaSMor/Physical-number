
#include "Unit.h"
using namespace std;
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
PhysicalNumber operator-()const;
bool operator<(const PhysicalNumber& num2)const;
bool operator<=(const PhysicalNumber& num2)const;
bool operator>(const PhysicalNumber& num2)const;
bool operator>=(const PhysicalNumber& num2)const;
bool operator!=(const PhysicalNumber& num2)const;
bool operator==(const PhysicalNumber& num2)const;
double getNum()const;
int getSpecificUnit()const;
//friend global IO operators
friend ostream& operator<<(ostream& os, const PhysicalNumber& pn);
friend istream& operator>>(istream& os, PhysicalNumber& pn);

private:
bool sameUnit(const PhysicalNumber& num2)const;
bool sameType(const PhysicalNumber& num2)const;
int getUnit()const;

};
}