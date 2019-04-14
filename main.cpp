
#include "PhysicalNumber.hpp"
#include "Unit.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>
using ariel::PhysicalNumber;
using  ariel::Unit;

int main(){
    PhysicalNumber a(4, Unit::KM);
    PhysicalNumber b(20, Unit::M);
    cout<<"a's value is: "<<a._value<<endl;
    cout<<"a's unit is: "<<ariel::toString(a._unit)<<endl;
    cout<<"a's string is: "<<a.toString()<<endl;



  return 0;
}
