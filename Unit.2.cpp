
#include "Unit.hpp"
#include <iostream>
#include <string>
using  ariel::Unit;



double ariel::mToKm(double a){
    return a/1000;
}

double ariel::kmToM(double a){
    return a * 1000;
}

double ariel::mToCm(double a){
    return a * 100;
}

double ariel::cmToM(double a){
    return a/100;
}

double ariel::kmToCm(double a){
    return a*100000;
}

double ariel::cmToKm(double a){
    return a/100000;
}

double ariel::secToMin(double a){
    return a/60;
}

double ariel::minToSec(double a){
    return a*60;
}

double ariel::secToHour(double a){
    return a/3600;
}

double ariel::hourToSec(double a){
    return a*3600;
}

double ariel::minToHour(double a){
     return a/60;
}

double ariel::hourToMin(double a){
    return a*60;
}

double ariel::gToKg(double a){
    return a/1000;
}

double ariel::kgToG(double a){
    return a*1000;
}

double ariel::gToTon(double a){
    return a/907185;
}

double ariel::tonToG(double a){
    return a*907185;
}

double ariel::tonToKg(double a){
    return a*907.185;
}

double ariel::kgToTon(double a){
    return a/907.185;
}


bool ariel::same(Unit a, Unit b){
    if (a==M || a==KM || a==CM){
        return (b==M || b==KM || b==CM);
    }
    else if (a==SEC || a==MIN || a==HOUR){
        return (b==M || b==KM || b==CM);
    }
    else if(a==G || a==KG || a==TON){
        return (b==G || b==KG || b==TON);
    }

    return false;
}


string ariel::toString(Unit unit){

    if(unit==M)
    return "[m]";

    else if(unit==KM)
    return "[km]";

    else if(unit==CM)
    return "[cm]";
	
    else if(unit==SEC)
    return "[sec]";
	
    else if(unit==MIN)
    return "[min]";

    else if(unit==HOUR)
    return "[hour]";

    else if(unit==G)
    return "[g]";

    else if(unit==KG)
    return "[kg]";

    else 
    return "[ton]";

     
}

bool ariel::isUnit(string str){   
return (str.compare("m")==0 || str.compare("km")==0 || str.compare("cm")==0 || str.compare("sec")==0 || 
str.compare("min")==0 || str.compare("hour")==0 || str.compare("g")==0 || str.compare("kg")==0 || str.compare("ton")==0);
}

Unit ariel::strToUnit(string str){
    if(str.compare("m")==0)
    return Unit::M;
    else  if(str.compare("km")==0)
    return Unit::KM;
    else  if(str.compare("cm")==0)
    return Unit::KM;
    else  if(str.compare("sec")==0)
    return Unit::SEC;
    else  if(str.compare("min")==0)
    return Unit::MIN;
    else  if(str.compare("hour")==0)
    return Unit::HOUR;
    else  if(str.compare("g")==0)
    return Unit::G;
    else  if(str.compare("kg")==0)
    return Unit::KG;
    else  if(str.compare("ton")==0)
    return Unit::TON;
    else throw "no measure";
}

string ariel::unitToStr(Unit unit){
    if(unit == Unit::M)
    return "m";
    else if(unit == Unit::CM)
    return "cm";
    else if(unit == Unit::KM)
    return "km";
    else if(unit == Unit::SEC)
    return "sec";
    else if(unit == Unit::MIN)
    return "min";
    else if(unit == Unit::HOUR)
    return "hour";
    else if(unit ==Unit::G)
    return "G";
    else if(unit ==Unit::KG)
    return "kg";
    else if(unit == Unit::TON)
    return "ton";
    else throw "no measure";
}