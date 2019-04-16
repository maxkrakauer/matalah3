#include "Unit.h"
#include "PhysicalNumber.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

using ariel::Unit;
using  ariel::PhysicalNumber;





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
    return a/1000000;
}

double ariel::tonToG(double a){
    return a*1000000;
}

double ariel::tonToKg(double a){
    return a*1000;
}

double ariel::kgToTon(double a){
    return a/1000;
}


bool ariel::same(Unit a, Unit b){
    if (a==M || a==KM || a==CM){
        return (b==M || b==KM || b==CM);
    }
    else if (a==SEC || a==MIN || a==HOUR){
        return (b==SEC || b==MIN || b==HOUR);
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



string ariel::PhysicalNumber::toString(){
    string val = std::to_string(_value);
    val = ariel::removeZeroes(val);
    string unit =ariel::toString(this->_unit);
    string whole = val + unit;
    return whole;
}


 double  ariel::convert(double value, Unit unit1, Unit unit2){

     if(unit1==unit2)
     return value;


     else if(unit1==HOUR && unit2==MIN)
     return ariel::minToHour(value);
     
     else if(unit1==MIN && unit2==HOUR)
     return ariel::hourToMin(value);
     
     else if(unit1==HOUR && unit2==SEC)
     return ariel::secToHour(value);
     
     else if(unit1==SEC && unit2==HOUR)
     return ariel::hourToSec(value);

     else if(unit1==MIN && unit2==SEC)
     return ariel::secToMin(value);

     else if(unit1==SEC && unit2==MIN)
     return ariel::minToSec(value);

     else if(unit1==M && unit2==CM)
     return ariel::cmToM(value);

     else if(unit1==CM && unit2==M)
     return ariel::mToCm(value);

     else if(unit1==KM && unit2==CM)
     return ariel::cmToKm(value);

     else if(unit1==CM && unit2==KM)
     return ariel::kmToCm(value);

     else if(unit1==M && unit2==KM)
     return ariel::kmToM(value);

     else if(unit1==KM && unit2==M)
     return ariel::mToKm(value);

     else if(unit1==KG && unit2==TON)
     return ariel::tonToKg(value);

     else if(unit1==TON && unit2==KG)
     return ariel::kgToTon(value);

     else if(unit1==KG && unit2==G)
     return ariel::gToKg(value);

     else if(unit1==G && unit2==KG)
     return ariel::kgToG(value);

     else if(unit1==G && unit2==TON)
     return ariel::tonToG(value);

     else 
     return ariel::gToTon(value);
     }


     string ariel::removeZeroes(string number){
    int size = number.size();
    
    int i=size-1;
    while(i>=0 && number.at(i)!='.'){
        i--;
    }
    if(i>-1){
    i=size-1;    
    while(number.at(i)=='0'){
        i--;
    }
    if(number.at(i)=='.')
    i--;
    return number.substr(0,i+1);
    }
    return number;
     }


     string ariel::reformString(PhysicalNumber a, string str){
        return str+"["+unitToStr(a._unit)+"]";
    }




     ariel::PhysicalNumber strToNum(string s){
        //create char array
        char str[s.size()+1];
        strcpy(str, s.c_str());
        
        
        int i=0;
        char* number;
        char* measure;

        int size = sizeof(str);
        while(*(str+i)!='[' && i<size)
        i++;
        if(i==size)
        throw "ilegal input";
        number = (char*)malloc(sizeof(char)*i);
        std::strncpy(number,str,i);
        double value;
        cout<<"before try"<<endl;
        try{
            value = std::atof(number);
            cout<<value<<endl;
        }
        catch (std::invalid_argument const &e){
        throw "ilegal input";
    }
        cout<<"after try"<<endl;
    
        int j=i+1;
        while(*(str+i)!=']' && i<size)
        i++;
        cout<<"before throw"<<endl;
        if(i==size)
        throw "ilegal input";
        cout<<"after throw"<<endl;
        measure = (char*)malloc(sizeof(char)*(i-j));
        std::strncpy(measure,str+j,i-j);
        cout<<number<<endl;
        if(ariel::isUnit(measure)==false)
        throw "ilegal input";
        cout<<measure<<endl;
        cout<<value<<endl;

        PhysicalNumber a(value, ariel::strToUnit(measure));

        cout<<"a's values is:"<<endl;
        cout<<a<<endl;
        delete(number);
        number=NULL;
        delete(measure);
        measure=NULL;
        return a;

    }

    



    PhysicalNumber ariel::operator+(PhysicalNumber a, PhysicalNumber b){
         cout<<"a+b has started"<<endl;
         if(same(a._unit, b._unit)==false){
         cout<<"same went wrong"<<endl;
         throw "mismatch";
         }
         else{
             
             double val = ariel::convert(b._value, a._unit,b._unit);
             cout<<"val is: "<<val<<endl;
             cout<<"a's is: "<<a._value<<endl;
             double sum = val + a._value;
             return PhysicalNumber(sum, a._unit);
             /**
             cout<<"sum is: "<<sum<<endl;
             string total = to_string(sum);
             string reformed = removeZeroes(total);
             string str = reformed+  ariel::toString(a._unit);
             cout<<str<<endl;
             return str;
             */

         }
     }

/**
     string operator+(string str, PhysicalNumber b){
         PhysicalNumber a = strToNum(str);
         return (a+b);
     }

     string operator+(PhysicalNumber a, string str){
         PhysicalNumber b = strToNum(str);
         return (a+b);
     }
     */


     PhysicalNumber ariel::operator-(PhysicalNumber a, PhysicalNumber b){
         if(!same(a._unit, b._unit))
         throw "mismatch";
         else{
             double val = ariel::convert(b._value, a._unit,b._unit);
             double sum = a._value - val;
             return PhysicalNumber(sum, a._unit);
             /**
             string str;
             string total = to_string(sum);
             string reformed = removeZeroes(total);
             str = reformed+  ariel::toString(a._unit);
             cout<<str<<endl;
             return str;
             */
         }
     }


/**

     string operator-(string str, PhysicalNumber b){
         PhysicalNumber a = strToNum(str);
         return (a-b);
     }

     string operator-(PhysicalNumber a, string str){
         PhysicalNumber b = strToNum(str);
         return (a-b);
     }

     
*/
    
    PhysicalNumber ariel::operator+=(PhysicalNumber &a, PhysicalNumber b){
         cout<<"before same"<<endl;
         if(same(a._unit, b._unit)==false)
         throw "mismatch";
        else{ cout<<"no mismatch"<<endl;
         
             double val = ariel::convert(b._value, a._unit,b._unit);
             double sum = val + a._value;
             a._value = sum;
             return a;
             
             /**
             string str;
             string total = to_string(sum);
             string reformed = removeZeroes(total);
             str = reformed+  ariel::toString(a._unit);
             cout<<str<<endl;
             return str;
             */
         }
     }

/**
     string operator+=(PhysicalNumber &a, string str){
         PhysicalNumber b = strToNum(str);
         return a+=b;
     }




     


     string ariel::operator+(PhysicalNumber a){
        cout<<a.toString()<<endl;
        return a.toString();
     }

     */


     PhysicalNumber ariel::operator-=(PhysicalNumber &a, PhysicalNumber b){
         if(!same(a._unit, b._unit))
         throw "mismatch";
         else{
             double val = ariel::convert(b._value, a._unit,b._unit);
             double sum = a._value - val;
             a._value=sum;
             return a;
             /**
             string str;
             string total = to_string(sum);
             string reformed = removeZeroes(total);
             str = reformed+  ariel::toString(a._unit);
             cout<<str<<endl;
             return str;
             */
         }
     }
/**
     string operator-=(PhysicalNumber &a, string str){
         PhysicalNumber b = strToNum(str);
         return a-=b;
     }


*/


     

    
ariel::PhysicalNumber::PhysicalNumber(double value, Unit unit){
        _unit = unit;
        _value = value;
    }

    ariel::PhysicalNumber::PhysicalNumber(int value, Unit unit){
        _unit = unit;
        _value = value;
    }


    




    PhysicalNumber ariel::operator-(PhysicalNumber a){
             //string total = to_string(-a._value);
             //string reformed = removeZeroes(total);
             //cout<<reformed<<endl;
             //return reformed+"["+unitToStr(a._unit)+"]";
             a._value = -a._value;
             return a;
            // return a.toString();

     }


PhysicalNumber ariel::operator--(PhysicalNumber &a,int){
    double prev=a._value;
    a._value=a._value-1;
    return PhysicalNumber(prev,a._unit);
    /**
    string number = to_string(prev);
    string reformed = removeZeroes(number);
    reformed = reformString(a,reformed);
    cout<<reformed<<endl;
    return reformed;
    */
}

ariel::PhysicalNumber ariel::operator++(ariel::PhysicalNumber &a,int){
    int prev=a._value;
    a._value=a._value+1;
    return PhysicalNumber(prev,a._unit);
    /**
    string number = to_string(prev);
    string reformed = removeZeroes(number);
    reformed = reformString(a,reformed);
    cout<<reformed<<endl;
    return reformed;
    */
}


ariel::PhysicalNumber ariel::operator++(ariel::PhysicalNumber &a){
    a._value=a._value+1;
    return a;
    /**
    string number = to_string(a._value);
    string reformed = removeZeroes(number);
    reformed = reformString(a,reformed);
    cout<<reformed<<endl;
    return reformed;
    */
}

PhysicalNumber ariel::operator--(PhysicalNumber &a){
    a._value=a._value-1;
    return a;
    /**
    string number = to_string(a._value);
    string reformed = removeZeroes(number);
    reformed = reformString(a,reformed);
    cout<<reformed<<endl;
    return reformed;
    */
}




ostream & ariel::operator<<(std::ostream &out, ariel::PhysicalNumber a){
    out<<a.toString();
    return out;
}


void ariel::operator<<(ariel::PhysicalNumber a, std::ostream &out){
   out<<endl;
}


istream & ariel::operator>>(std::istream &in, PhysicalNumber& a){
    cout<<"does the >> func start"<<endl;
    //insert string into str
    string s = a.toString();
   
    in>>s;
    return in;

    /**



    //check whether str is valid
    cout<<"str prints: "<<s<<endl;

    char str[s.size()+1];
    strcpy(str, s.c_str());




    int i=0;
    char* number;
    char* measure;
    int size = sizeof(str);
    while(*(str+i)!='[' && i<size)
    i++;
    if(i==size)
    throw "ilegal input";
    number = (char*)malloc(sizeof(char)*i);
    std::strncpy(number,str,i);
    double value;
    cout<<"before try"<<endl;
    try{
        value = std::atof(number);
        cout<<value<<endl;
    }
    catch (std::invalid_argument const &e){
        throw "ilegal input";
    }
    cout<<"after try"<<endl;
    
    int j=i+1;
    while(*(str+i)!=']' && i<size)
    i++;
    cout<<"before throw"<<endl;
    if(i==size)
    throw "ilegal input";
    cout<<"after throw"<<endl;
    measure = (char*)malloc(sizeof(char)*(i-j));
    std::strncpy(measure,str+j,i-j);
    cout<<number<<endl;
    if(isUnit(measure)==false)
    throw "ilegal input";
    cout<<measure<<endl;
    cout<<value<<endl;

    
    a._value=value;
    a._unit = strToUnit(measure);
    cout<<"a's values is:"<<endl;
    cout<<a<<endl;
    delete(number);
    number=NULL;
    delete(measure);
    measure=NULL;
    return in;
    */
    }







    bool ariel::operator==(PhysicalNumber a, PhysicalNumber b){
        if (same(a._unit,b._unit)==false)
        throw "incopatible units";
        else
            return (a._value == convert(b._value, a._unit,b._unit));
    }
/**
    bool operator==(bool boo, PhysicalNumber b){
         //PhysicalNumber a = strToNum(str);

         return a==b;
    }

    bool operator==(PhysicalNumber a, string str){
        PhysicalNumber b = strToNum(str);
        return a==b;
    }
*/

    bool ariel::operator>=(PhysicalNumber a, PhysicalNumber b){
        if (same(a._unit,b._unit)==false)
        throw "incopatible units";
        else
            return (a._value >= convert(b._value, a._unit,b._unit));
    }
    /**

    bool operator>=(string str, PhysicalNumber b){
        PhysicalNumber a = strToNum(str);
         return a>=b;
    }

     bool operator>=(PhysicalNumber a, string str){
         PhysicalNumber b = strToNum(str);
        return a>=b;
     }
*/
    bool ariel::operator<=(PhysicalNumber a, PhysicalNumber b){
        if (same(a._unit,b._unit)==false)
        throw "incopatible units";
        else
            return (a._value <= convert(b._value, a._unit,b._unit));
    }
/**
    bool ariel::operator<=(string str, PhysicalNumber b){
        PhysicalNumber a = strToNum(str);
         return a<=b;
    }


     bool ariel::operator<=(PhysicalNumber a, string str){
         PhysicalNumber b = strToNum(str);
        return a<=b;
     }
*/
    bool ariel::operator<(PhysicalNumber a, PhysicalNumber b){
        if (same(a._unit,b._unit)==false)
        throw "incopatible units";
        else
            return (a._value < convert(b._value, a._unit,b._unit));
    }
/**
    bool ariel::operator<(string str, PhysicalNumber b){
        PhysicalNumber a = strToNum(str);
        return a<b;
    }

     bool ariel::operator<(PhysicalNumber a, string str){
         PhysicalNumber b = strToNum(str);
        return a<b;
     }
*/
    bool ariel::operator>(PhysicalNumber a, PhysicalNumber b){
        if (same(a._unit,b._unit)==false)
        throw "incopatible units";
        else
            return (a._value > convert(b._value, a._unit,b._unit));
    }
/**
    bool ariel::operator>(string str, PhysicalNumber b){
         PhysicalNumber a = strToNum(str);
         return a>b;
    }

     bool ariel::operator>(PhysicalNumber a, string str){
         PhysicalNumber b = strToNum(str);
         return a>b;
     }
*/
    bool ariel::operator!=(PhysicalNumber a, PhysicalNumber b){
        if (same(a._unit,b._unit)==false)
        throw "incopatible units";
        else
            return (a._value != convert(b._value, a._unit,b._unit));
    }
/**
     bool ariel::operator!=(string str, PhysicalNumber b){
         PhysicalNumber a = strToNum(str);
         return a!=b;
     }

     bool ariel::operator!=(PhysicalNumber a, string str){
         PhysicalNumber b = strToNum(str);
         return a!=b;
     }

**/

    
