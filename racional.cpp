#include "racional.h"
#include <string>
using std::string;

#include <sstream>
using std::stringstream;

#include <cmath>
using std::abs;

#include <iostream>
using std::istream;
using std::ostream;




const Racional& Racional::simplificar(){
    if (denominador > abs(numerador)){
        for (int i = numerador; i >= 2; --i){
            if(denominador%i==0 && numerador%i==0){
                numerador/=i;
                denominador/=i;
                return *this;
            }
        }
    }
    else{
        for (int i = denominador; i >= 2; --i){
            if(denominador%i==0 && numerador%i==0){
                numerador/=i;
                denominador/=i;
                return *this;
            }
        }
    }
}
Racional::Racional(int numerador, int denominador){
    this->numerador=numerador;
    if(denominador != 0)
        this->denominador=denominador;
    else
        this->denominador=1;
    simplificar();
}

ostream& operator<<(ostream& out, const Racional& r){
    out << r.toString();
    return out;


}
istream& operator>>(istream& in, Racional& r){
    int num,den;
    in>>num;
    in>>den;
    Racional temp(num,den);
    r = temp;
    return in;

}
string Racional::toString()const{
    stringstream ss;

    if (numerador == 0){
        ss << 0;
    } else{

        if(denominador == 1){
            ss << numerador;
        }
        else{
            ss << numerador << "/" << denominador;
        }
    }
        
    return ss.str();
}
double Racional::toDouble()const{
    return ((double)numerador)/denominador;
}
const Racional& Racional::operator=(const Racional& r){
    this->numerador = r.numerador;
    this->denominador = r.denominador;
    simplificar();
    return *this;
}
const Racional& Racional::operator+=(const Racional& r){
    this->numerador = (this->numerador*r.denominador) + (this->denominador*r.numerador);
    this->denominador*= r.denominador;
    simplificar();
    return *this;
}
const Racional& Racional::operator-=(const Racional& r){
    this->numerador = (this->numerador*r.denominador) - (this->denominador*r.numerador);
    this->denominador*= r.denominador;
    simplificar();
    return *this;
}
const Racional& Racional::operator*=(const Racional& r){
    this->denominador *= r.denominador;
    this->numerador *= r.numerador;
    simplificar();
    return *this;
}
const Racional& Racional::operator/=(const Racional& r){
    this->denominador *= r.numerador;
    this->numerador *= r.denominador;
    simplificar();
    return *this;
}
const Racional Racional::operator+(const Racional& r)const{
    Racional retval((this->numerador*r.denominador) + (this->denominador*r.numerador), this->denominador*r.denominador);
    return retval;
}
const Racional Racional::operator-(const Racional& r)const{
    Racional retval((this->numerador*r.denominador) - (this->denominador*r.numerador), this->denominador*r.denominador);
    return retval;
}
const Racional Racional::operator*(const Racional& r)const{
    Racional retval(this->numerador*r.numerador,this->denominador*r.denominador);
    return retval;
}
const Racional Racional::operator/(const Racional& r)const{
    Racional retval(this->numerador*r.denominador,this->denominador*r.numerador);
    return retval;
}
bool Racional::operator==(Racional& r){
    simplificar();
    r.simplificar();
    if(this->numerador == r.numerador && this->denominador == r.denominador)
        return true;
    return false;
}
bool Racional::operator!=(Racional& r){
    simplificar();
    r.simplificar();
    if(this->numerador != r.numerador || this->denominador != r.denominador)
        return true;
    return false;
}
