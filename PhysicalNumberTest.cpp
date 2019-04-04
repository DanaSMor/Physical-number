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

        //length manipulation
        .setname("Basic output")
        .CHECK_OUTPUT(cm, "50[cm]")
        .CHECK_OUTPUT(m, "300[m]")
        .CHECK_OUTPUT(km, "2[km]")

        .setname("Compatible dimensions")
        .CHECK_OUTPUT(cm + m, "30050[cm]")
        .CHECK_OUTPUT((m + cm), "300.5[m]")
        .CHECK_OUTPUT((km += m), "2.3[km]")
        .CHECK_OUTPUT(km, "2.3[km]")
        .CHECK_OUTPUT(m + m, "600[m]")
        .CHECK_OUTPUT(km - km, "0[km]")


        .setname("Incompatible dimensions")
        .CHECK_THROWS(cm + h)
        .CHECK_THROWS(m + g)
        .CHECK_THROWS(km + ton)

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
