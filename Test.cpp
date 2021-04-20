#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <iostream>
#include <iomanip> 
#include "assert.h"


using namespace std;
using namespace ariel;

double randomNumber(){
    srand(time(0));
    return rand()%10 + 1;
}
void unit_test(std::ostream& os , double r, NumberWithUnits n) 
{ 
  os << "value: " + to_string(r) +" unit: " + n.getUnit() ;
} 

TEST_CASE("math operators"){
    double r = randomNumber();
    NumberWithUnits n1(r, "km");
    NumberWithUnits n2(r, "km");
    NumberWithUnits n3(0, "km");
    NumberWithUnits n4(r, "km");
    CHECK(n1 == n2);
    CHECK(n2 == n4);
    n1*r;
    CHECK_EQ(n1.getValue() , r*r);
    n1++;
    CHECK_EQ(n1.getValue(), r*r + 1);
    double sum = n1.getValue() + n2.getValue();
    n1 += n2;
    CHECK_EQ(n1.getValue(), sum);
    double diff = n1.getValue() - n2.getValue(); 
    n1 -= n2;
    CHECK_EQ(n1.getValue(), diff);
    n3 = n1 + n2 + n4;
    CHECK(n3 >= n1 + n2 + n4);
}

TEST_CASE("comparison operators"){
    double r = randomNumber();
    NumberWithUnits n1(r, "km");
    NumberWithUnits n2(r, "km");
    NumberWithUnits n3(r, "km");
    NumberWithUnits n4(r, "km");
    NumberWithUnits n5(r, "km");
    CHECK_EQ(n1,n2);
    CHECK(n1 >= n2);
    CHECK(n1 <= n2);
    n1 += n2;
    CHECK(n1!= n2);
    CHECK(n1 > n2);
    CHECK_FALSE(n1 < n2);
    n3*r;
    n3 += n3;
    CHECK(n3 > n4);
    CHECK(n3 > n5);
    CHECK_FALSE(n3 < n5);    
}

TEST_CASE("stream operators"){
    double r = randomNumber();
    NumberWithUnits n(r, "km");
    ostringstream os;
    unit_test(os, r, n);
    CHECK_EQ(os.str() ,"value: " + to_string(r) +" unit: " + n.getUnit());
    ostringstream ost;
    n*r;
    unit_test(ost, r*r, n);
    CHECK_EQ(ost.str() ,"value: " + to_string(r*r) +" unit: " + n.getUnit());
    double r2 = randomNumber();
    istringstream is(to_string(r2));
    is >> n;
    CHECK_EQ(n.getValue(), r2);
    istringstream ist(to_string(r2*r));
    ist >> n;
    CHECK_EQ(n.getValue(), r2*r);

}
