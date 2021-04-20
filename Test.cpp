#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <iostream>
#include <iomanip> 


using namespace std;
using namespace ariel;
double randomNumber(){
    srand(time(0));
    return rand()%10;
}

TEST_CASE("math operators"){
    double r = randomNumber();
    cout<<r<<endl;
    NumberWithUnits n1(r, "km");
    NumberWithUnits n2(r, "km");
    CHECK_EQ(n1 == n2, true);
    n1*r;
    CHECK_EQ(n1.getValue() , r*r);
    n1++;
    CHECK_EQ(n1.getValue(), r*r + 1);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
    CHECK_EQ(n1 > n2, true);
}

TEST_CASE("comparison operators"){

}
