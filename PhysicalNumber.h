#include "Unit.h"

 namespace ariel{
using ariel::Unit;
   
    class PhysicalNumber{
    public:
    Unit _unit;
    double _value;
    public:

    PhysicalNumber(double value, Unit unit);

    PhysicalNumber(int value, Unit unit);
    
    string toString();

    
    };


    bool same(Unit a, Unit b);

double mToKm(double a);

double kmToM(double a);

double mToCm(double a);

double cmToM(double a);

double kmToCm(double a);

double cmToKm(double a);

double secToMin(double a);

double minToSec(double a);

double secToHour(double a);

double hourToSec(double a);

double minToHour(double a);

double hourToMin(double a);

double gToKg(double a);

double kgToG(double a);

double gToTon(double a);

double tonToG(double a);

double tonToKg(double a);

double kgToTon(double a);

string toString(Unit unit);

bool isUnit(string str);

Unit strToUnit(string str);

string unitToStr(Unit unit);




     double convert(double value, Unit unit1, Unit unit2);

     string removeZeroes(string number);

     string operator+(PhysicalNumber a, PhysicalNumber b);

     string operator+=(PhysicalNumber &a, PhysicalNumber b);

     string operator+(PhysicalNumber a);

     string operator-(PhysicalNumber a, PhysicalNumber b);

     string operator-=(PhysicalNumber &a, PhysicalNumber b);

     string operator-(PhysicalNumber a);

     string operator++(PhysicalNumber &a,int);

     string operator--(PhysicalNumber &a, int);

     

     ostream & operator<<(std::ostream &out, PhysicalNumber a);

     void operator<<(PhysicalNumber a, std::ostream &out);

     istream &  operator>>(std::istream &in, PhysicalNumber& a);

     


     bool operator==(PhysicalNumber a, PhysicalNumber b);

     bool operator>=(PhysicalNumber a, PhysicalNumber b);

     bool operator<=(PhysicalNumber a, PhysicalNumber b);

     bool operator>(PhysicalNumber a, PhysicalNumber b);

     bool operator<(PhysicalNumber a, PhysicalNumber b);

     bool operator!=(PhysicalNumber a, PhysicalNumber b);

     string reformString(PhysicalNumber a, string str);




};