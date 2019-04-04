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
    //PhysicalNumber a(1, Unit::M);   // 2 kilometers
    //PhysicalNumber b(100, Unit::CM);  // 300 meters
    //PhysicalNumber c=a-b;
    //a+=b;
    //cout << "main: " <<a.getNum() << endl;   // Prints "2[km]"
    //cout << "main: " <<a<< endl;  

    // PhysicalNumber a(2, Unit::KM);
    // PhysicalNumber b(300, Unit::M);
    // cout << "a:" <<a<<" b:"<<b<< endl;  
    // cout <<"\n"<< (a+=b) << endl;  
    string str ="danana";
    string s="300[km]";
    long pos=str.find("5") ;
    cout <<"\n"<< str.find("5") <<" str len: "<<str.length()<< endl;  
    if(pos>=0&&pos<str.length())
      cout<<"horray";
    
    

    
  return 0;
}