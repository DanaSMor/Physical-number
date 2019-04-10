/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main()
{
  badkan::TestCase testcase;
  int grade = 0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0)
  {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    //advanced tests
    PhysicalNumber cm(50, Unit::CM);
    PhysicalNumber m(300, Unit::M);
    PhysicalNumber km(2, Unit::KM);
    PhysicalNumber s(30, Unit::SEC);
    PhysicalNumber min(10, Unit::MIN);
    PhysicalNumber h(2, Unit::HOUR);
    PhysicalNumber g(200, Unit::G);
    PhysicalNumber kg(45, Unit::KG);
    PhysicalNumber ton(2, Unit::TON);

    testcase
        .setname("Basic output")
        .CHECK_OUTPUT(a, "2[km]")
        .CHECK_OUTPUT(b, "300[m]")

        .setname("Compatible dimensions")
        .CHECK_OUTPUT(b + a, "2300[m]")
        .CHECK_OUTPUT((a += b), "2.3[km]")
        .CHECK_OUTPUT(a, "2.3[km]")
        .CHECK_OUTPUT(a + a, "4.6[km]")
        .CHECK_OUTPUT(b - b, "0[m]")
        .CHECK_OUTPUT(c, "2[hour]")
        .CHECK_OUTPUT(d, "30[min]")
        .CHECK_OUTPUT(d + c, "150[min]")

        .setname("Incompatible dimensions")
        .CHECK_THROWS(a + c)
        .CHECK_THROWS(a + d)
        .CHECK_THROWS(b + c)
        .CHECK_THROWS(b + d)

        .setname("Basic input")
        .CHECK_OK(istringstream("700[kg]") >> a)
        .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

        // YOUR TESTS - INSERT AS MANY AS YOU WANT

        
        .setname("Basic output")
        .CHECK_OUTPUT(cm, "50[cm]")
        .CHECK_OUTPUT(m, "300[m]")
        .CHECK_OUTPUT(km, "2[km]")
        .CHECK_OUTPUT(s, "30[sec]")
        .CHECK_OUTPUT(min, "10[min]")
        .CHECK_OUTPUT(h, "2[hour]")
        .CHECK_OUTPUT(g, "200[g]")
        .CHECK_OUTPUT(kg, "45[kg]")
        .CHECK_OUTPUT(ton, "2[ton]")


        .setname("Compatible dimensions length")
        .CHECK_OUTPUT(cm + m, "30050[cm]")
        .CHECK_OUTPUT((m + cm), "300.5[m]")
        .CHECK_OUTPUT((km += m), "2.3[km]")
        .CHECK_OUTPUT(km, "2.3[km]")
        .CHECK_OUTPUT(m + m, "600[m]")
        .CHECK_OUTPUT(km - km, "0[km]")
        .CHECK_OUTPUT(km++, "2.3[km]")
        .CHECK_OUTPUT(cm++, "50[cm]")
        .CHECK_OUTPUT(m++, "300[m]")
        .CHECK_OUTPUT(++km, "4.3[km]")
        .CHECK_OUTPUT(++cm, "52[cm]")
        .CHECK_OUTPUT(++m, "302[m]")
        .CHECK_OUTPUT(km--, "4.3[km]")
        .CHECK_OUTPUT(cm--, "52[cm]")
        .CHECK_OUTPUT(m--, "302[m]")
        .CHECK_OUTPUT(--km, "2.3[km]")
        .CHECK_OUTPUT(--cm, "50[cm]")
        .CHECK_OUTPUT(--m, "300[m]")

        .setname("Compatible dimensions time")
        .CHECK_OUTPUT(min + s, "10.5[min]")
        .CHECK_OUTPUT((s + h), "7230[sec]")
        .CHECK_OUTPUT((h += min), "2.16667[hour]")
        .CHECK_OUTPUT(h, "2.16667[hour]")
        .CHECK_OUTPUT(min + min, "20[min]")
        .CHECK_OUTPUT(h - h, "0[hour]")
        .CHECK_OUTPUT(s++, "30[sec]")
        .CHECK_OUTPUT(min++, "10[min]")
        .CHECK_OUTPUT(h++, "2.16667[hour]")
        .CHECK_OUTPUT(++s, "32[sec]")
        .CHECK_OUTPUT(++min, "12[min]")
        .CHECK_OUTPUT(++h, "4.16667[hour]")
        .CHECK_OUTPUT(s--, "32[sec]")
        .CHECK_OUTPUT(min--, "12[min]")
        .CHECK_OUTPUT(h--, "4.16667[hour]")
        .CHECK_OUTPUT(--s, "30[sec]")
        .CHECK_OUTPUT(--min, "10[min]")
        .CHECK_OUTPUT(--h, "2.16667[hour]")




        .setname("Incompatible dimensions")
        .CHECK_THROWS(cm + h)
        .CHECK_THROWS(cm + g)
        .CHECK_THROWS(cm + ton)        
        .CHECK_THROWS(m + h)
        .CHECK_THROWS(m + g)
        .CHECK_THROWS(m + ton)
        .CHECK_THROWS(km + h)
        .CHECK_THROWS(km + g)
        .CHECK_THROWS(km + ton)        
        .CHECK_THROWS(s + cm)
        .CHECK_THROWS(s + g)
        .CHECK_THROWS(s + ton)
        .CHECK_THROWS(min + kg)
        .CHECK_THROWS(min + g)
        .CHECK_THROWS(min + ton)        
        .CHECK_THROWS(h + cm)
        .CHECK_THROWS(h + g)
        .CHECK_THROWS(h + ton)
        .CHECK_THROWS(g + h)
        .CHECK_THROWS(g + cm)
        .CHECK_THROWS(kg + s)        
        .CHECK_THROWS(kg + h)
        .CHECK_THROWS(kg + min)
        .CHECK_THROWS(ton + m)


        .print(cout, /*show_grade=*/false);
    grade = testcase.grade();
  }
  else
  {
    testcase.print_signal(signal);
    grade = 0;
  }
  cout << "*** Grade: " << grade << " ***" << endl;
  return grade;
}
