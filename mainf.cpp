/**
 * Demo file for the exercise on physical numbers
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
#include <stdexcept>
using std::cout, std::endl, std::boolalpha, std::istringstream;
#include "PhysicalNumber.h"

using ariel::PhysicalNumber, ariel::Unit;

int main() {
//cout << "dana";
    PhysicalNumber a(1, Unit::M);   // 2 kilometers
    PhysicalNumber b(5, Unit::CM);  // 300 meters
    //PhysicalNumber c=a-b;
    a+=b;
    cout << "main: " <<a.getNum() << endl;   // Prints "2[km]"
  return 0;
}