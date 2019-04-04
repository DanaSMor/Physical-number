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
#include <string>
#include <cstdlib>
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
    
    // char units[9][5]={"cm","m","km","sec","min","hour","g","kg","ton"};
    // string str ="25.3[g]";
    // string su;
    // int i;
    // bool flag=false;
    // for(i=0;i<9;i++)
    // {
    //   su="[";
    //   su=su+units[i];
    //   su=su+"]";
    //   cout<<su;
    //   if(str.find(su)<9)
    //     {flag=true;
    //       break;}
    // }
    //cout<<str.substr(0,str.find("[")).c_str()<<"\n";
    //if(flag){
    // double x=atof(str.substr(0,str.find("[")).c_str());
     PhysicalNumber a(2, Unit::KM);   // 2 kilometers
      cout << a << endl; 
   istringstream input("700[kg]");
    input >> a;
    cout << a << endl;   // Prints "700[kg]"
    // PhysicalNumber a(x,Unit(i));
    // cout<<a;
    // }
    // else
    // {
    //   throw runtime_error("not a valid value");
    // }


    
        //string b="52";
    //int x=atoi(b.c_str());
    /*
    //cout<<str.substr(str.find("[")+1,5);//str.find("]")-2
    int start=str.find("[")+1;
    //string sub=str.substr(str.find(("[")+1),(str.find("]")-2));
cout<<start<<"\n";
    string sub=str.substr(start, (str.length()-start-1));
    cout<<"sub:"<<sub;
    int i;
    for(i=0;i<sub.length();i++)
      sub[i]=sub[i]-32;
    cout<<"sub:"<<sub;
    
     PhysicalNumber a(5,Unit(0));
     cout<<a;
   // string s="300[kl]";
    long pos=str.find("5") ;
    cout <<"\n"<< str.find("5") <<" str len: "<<str.length()<< endl;  
    if(pos>=0&&pos<str.length())
      cout<<"horray";*/
    
    

    
  return 0;
}