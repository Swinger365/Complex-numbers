//Header Guards
#ifndef INCLUDED
#define INCLUDED
//Headers
#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <conio.h>
//Constant of Precision
#define PRECISION 10000000

//------------------------Complex Alg-----------------------------------------------------
class ComplexAlg{
private:
    double Re, Im;
public:
    //----------------------Constructors----------------------------------------------------
    ComplexAlg():Re(0),Im(0){}
    ComplexAlg(const double &real):Re(real),Im(0){}
    ComplexAlg(const double &real,const double &imaginary):Re(real),Im(imaginary){}
    ComplexAlg(const ComplexAlg &other):Re(other.Re),Im(other.Im){}
    //--------------------Getters and Setters---------------------------------------------
    void setReal(const double &real){Re = real;}
    void setIm(const double &imaginary){Im = imaginary;}
    void setNum(const double &real, const double &imaginary){Re=real;Im=imaginary;};
    double getReal()const{return Re;}
    double getIm()const{return Im;}
    //--------------------Useful Methods---------------------------------------------------
    inline double module()const{return sqrt(Re*Re + Im*Im);}//magnitude (module)
    ComplexAlg conjugate()const{ComplexAlg conjug(Re,-Im);return conjug;}
    //------------------------Operations----------------------------------------------------
    //------------------------Plus-----------------------------------------------------------
    ComplexAlg operator+(const ComplexAlg &other)const{ComplexAlg sum(other.Re+Re,other.Im+Im);return sum;}
    ComplexAlg operator+(const double &other)const{ComplexAlg sum(Re+other,Im);return sum;}
    void operator+=(const ComplexAlg &other){Re+=other.Re;Im+=other.Im;}
    void operator+=(const double &other){Re+=other;}
    //------------------------Minus---------------------------------------------------------
    ComplexAlg operator-(const ComplexAlg &other)const{ComplexAlg sub(Re-other.Re,Im-other.Im);return sub;}
    ComplexAlg operator-(const double &other)const{ComplexAlg sub(Re-other,Im);return sub;}
    void operator-=(const ComplexAlg &other){Re-=other.Re;Im-=other.Im;}
    void operator-=(const double &other){Re-=other;}
    //------------------------Multiplication-------------------------------------------------
    ComplexAlg operator*(const ComplexAlg &other)const{ComplexAlg mult(Re*other.Re - Im*other.Im,Re*other.Im+Im*other.Re);return mult;}
    ComplexAlg operator*(const double &other)const{ComplexAlg mult(Re*other,Im*other);return mult;}
    void operator *=(const ComplexAlg &other){ComplexAlg mult = (*this) * other; *this = mult;}
    void operator *=(const double &other){Re*=other;Im*=other;}
    //-----------------------Division--------------------------------------------------------
    ComplexAlg operator/(const ComplexAlg &other)const{ComplexAlg divis((Re*other.Re + Im*other.Im)/(other.module()*other.module()), (other.Re*Im - Re*other.Im)/(other.module()*other.module()));return divis;}
    ComplexAlg operator/(const double &other)const{ComplexAlg divis(Re/other,Im/other);return divis;}
    void operator/=(const ComplexAlg &other){ComplexAlg divis = (*this) / other; (*this) = divis;}
    void operator/=(const double &other){Re/=other;Im/=other;}
    //-------------------------------Show--------------------------------------------------
    void show() const{
        if(round(Re*PRECISION)/PRECISION != 0 && round(Im*PRECISION)/PRECISION !=0){
            std::cout<<round(Re*PRECISION)/PRECISION<<( (Im>0)? "+":"")<<round(Im*PRECISION)/PRECISION<<"i"<<std::endl;
        }else if(round(Re*PRECISION)/PRECISION == 0 && round(Im*PRECISION)/PRECISION != 0){
            std::cout<<Im<<"i"<<std::endl;
        } else if(round(Im*PRECISION)/PRECISION == 0 && round(Re*PRECISION)/PRECISION != 0){
            std::cout<<Re<<std::endl;
        } else {
            std::cout<<"0"<<std::endl;
        }
    }
};
//-------------------------------Complex Trig---------------------------------------------
class ComplexTrig{
protected:
    double module,argument;
public:
    //-------------------Constructors------------------------------------------------------
    ComplexTrig():module(0),argument(0){}
    ComplexTrig(const double &magnitude):module(magnitude),argument(0){}
    ComplexTrig(const double &magnitude,const double &angle):module(magnitude),argument(angle){}
    //-----------------Getters and Setters-------------------------------------------------
    void setMod(const double &magnitude){module = magnitude;}
    void setArg(const double &angle){argument = angle;}
    void setNum(const double &magnitude,const double &angle){module = magnitude;argument=angle;}
    double getMod()const{return module;}
    double getArg()const{return argument;}
    //-------------------Useful Methods----------------------------------------------------
    ComplexTrig calc_pow(double n){ComplexTrig trigonometric(pow(module,n),n*argument);return trigonometric;}
    ComplexTrig sqroot(){ComplexTrig trigonometric(sqrt(module),argument/2);return trigonometric;}
    //--------------------Operators---------------------------------------------------------
    //--------------------Plus----------------------------------------------------------------
    ComplexTrig operator +(const double &other) const{
        double real = module*cos(argument) + other,im = module*sin(argument);
        double magn = sqrt(real*real + im*im),angl = atan2(im,real);
        ComplexTrig trigonometric(magn,angl);
        return trigonometric;
    }
    ComplexTrig operator +(const ComplexTrig &other) const{
        double real = module*cos(argument) + other.getMod()*cos(other.getArg()),im = module*sin(argument) + other.getMod()*sin(other.getArg());
        double magn = sqrt(real*real + im*im), angl = atan2(im,real);
        ComplexTrig trigonometric(magn, angl);
        return trigonometric;
    }
    void operator +=(const double &other){
        double real = module*cos(argument) + other,im = module*sin(argument);
        module = sqrt(real*real + im*im); argument = atan2(im,real);
    }
    void operator +=(const ComplexTrig &other){
        double real = module*cos(argument) + other.getMod()*cos(other.getArg()),im = module*sin(argument) + other.getMod()*sin(other.getArg());
        module = sqrt(real*real + im*im);argument = atan2(im,real);
    }
    //--------------------Minus-------------------------------------------------
    ComplexTrig operator -(const double &other)const{
        double real = module*cos(argument) - other,im = module*sin(argument);
        double magn = sqrt(real*real + im*im),angl = atan2(im,real);
        ComplexTrig trigonometric(magn,angl);
        return trigonometric;
    }
    ComplexTrig operator -(const ComplexTrig &other) const{
        double real = module*cos(argument) - other.getMod()*cos(other.getArg()),im = module*sin(argument) - other.getMod()*sin(other.getArg());
        double magn = sqrt(real*real + im*im), angl = atan2(im,real);
        ComplexTrig trigonometric(magn, angl);
        return trigonometric;
    }
    void operator -=(const double &other){
        double real = module*cos(argument) - other,im = module*sin(argument);
        module = sqrt(real*real + im*im), argument = atan2(im,real);
    }
    void operator -=(const ComplexTrig &other){
        double real = module*cos(argument) - other.getMod()*cos(other.getArg()),im = module*sin(argument) - other.getMod()*sin(other.getArg());
        module = sqrt(real*real + im*im), argument = atan2(im,real);
    }
    //--------------------Multiplication---------------------------------------------
    ComplexTrig operator *(const double &other)const{
        ComplexTrig trigonometric(module*other,argument);
        return trigonometric;
    }
    ComplexTrig operator *(const ComplexTrig &other)const{
        double new_mod = module * other.getMod(),new_angle = argument + other.getArg();
        ComplexTrig trigonometric(new_mod,new_angle);
        return trigonometric;
    }
    void operator *=(const double &other){module*=other;}
    void operator *=(const ComplexTrig &other){module*=other.getMod();argument += other.getArg();}
    //--------------------Division-----------------------------------------------
    ComplexTrig operator /(const double &other)const{
        double new_mod = module / other;
        ComplexTrig trigonometric(new_mod,argument);
        return trigonometric;
    }
    ComplexTrig operator /(const ComplexTrig &other)const{
        ComplexTrig trigonometric(module/other.getMod(),argument-other.getArg());
        return trigonometric;
    }
    void operator /=(const double &other){module/=other;}
    void operator /=(const ComplexTrig &other){module/=other.getMod();argument-=other.getArg();}
    //--------------------Show--------------------------------------------------
    virtual void show ()const{
        std::cout<<round(module*PRECISION)/PRECISION<<"*["<<"cos("<<round(argument*PRECISION)/PRECISION<<")"<<" + i*sin("<<round(argument*PRECISION)/PRECISION<<")]"<<std::endl;
    }
};
//---------------------------Complex Exponential--------------------------------------------
class ComplexExp: public ComplexTrig{
public:
    //--------------------Constructors------------------------------------------------------
    using ComplexTrig::ComplexTrig;
    //-------------------Useful Methods----------------------------------------
    ComplexExp calc_pow(const double &n){ComplexExp exp(pow(module,n),n*argument);return exp;}
    ComplexExp sqroot(){ComplexExp exp(sqrt(module),argument/2);return exp;}
    //--------------------Operators--------------------------------------------
    //--------------------Plus-------------------------------------------------
    ComplexExp operator +(const double &other) const{
        double real = module*cos(argument) + other,im = module*sin(argument);
        double magn = sqrt(real*real + im*im),angl = atan2(im,real);
        ComplexExp exp(magn,angl);
        return exp;
    }
    ComplexExp operator +(const ComplexExp &other) const{
        double real = module*cos(argument) + other.getMod()*cos(other.getArg()),im = module*sin(argument) + other.getMod()*sin(other.getArg());
        double magn = sqrt(real*real + im*im), angl = atan2(im,real);
        ComplexExp exp(magn, angl);
        return exp;
    }
    void operator +=(const double &other){
        double real = module*cos(argument) + other,im = module*sin(argument);
        module = sqrt(real*real + im*im); argument = atan2(im,real);
    }
    virtual void operator +=(const ComplexExp &other){
        double real = module*cos(argument) + other.getMod()*cos(other.getArg()),im = module*sin(argument) + other.getMod()*sin(other.getArg());
        module = sqrt(real*real + im*im);argument = atan2(im,real);
    }
    //--------------------Minus----------------------------------------------
    ComplexExp operator -(const double &other)const{
        double real = module*cos(argument) - other,im = module*sin(argument);
        double magn = sqrt(real*real + im*im),angl = atan2(im,real);
        ComplexExp exp(magn,angl);
        return exp;
    }
    ComplexExp operator -(const ComplexExp &other) const{
        double real = module*cos(argument) - other.getMod()*cos(other.getArg()),im = module*sin(argument) - other.getMod()*sin(other.getArg());
        double magn = sqrt(real*real + im*im), angl = atan2(im,real);
        ComplexExp exp(magn, angl);
        return exp;
    }
    void operator -=(const double &other){
        double real = module*cos(argument) - other,im = module*sin(argument);
        module = sqrt(real*real + im*im), argument = atan2(im,real);
    }
    void operator -=(const ComplexExp &other){
        double real = module*cos(argument) - other.getMod()*cos(other.getArg()),im = module*sin(argument) - other.getMod()*sin(other.getArg());
        module = sqrt(real*real + im*im), argument = atan2(im,real);
    }
    //--------------------Multiplication---------------------------------------
    ComplexExp operator *(const double &other)const{
        ComplexExp exp(module*other,argument);
        return exp;
    }
    ComplexExp operator *(const ComplexExp &other)const{
        double new_mod = module * other.getMod(),new_angle = argument + other.getArg();
        ComplexExp exp(new_mod,new_angle);
        return exp;
    }
    void operator *=(const double &other){module*=other;}
    void operator *=(const ComplexExp &other){module*=other.getMod();argument += other.getArg();}
    //--------------------Division----------------------------------------------
    ComplexExp operator /(const double &other)const{
        double new_mod = module / other;
        ComplexExp exp(new_mod,argument);
        return exp;
    }
    ComplexExp operator /(const ComplexExp &other)const{
        ComplexExp exp(module/other.getMod(),argument-other.getArg());
        return exp;
    }
    void operator /=(const double &other){module/=other;}
    void operator /=(const ComplexExp &other){module/=other.getMod();argument-=other.getArg();}
    //--------------------Show-------------------------------------------------
    void show() const {
        std::cout<<round(module*PRECISION)/PRECISION<<"*e^(i*"<<round(argument*PRECISION)/PRECISION<<")"<<std::endl;
    }
};
//-------------------------Functions------------------------------------------------------
//---------------------Transform to alg---------------------------------------------------
ComplexAlg to_alg(const ComplexAlg &num){ return num;}// alg->alg
ComplexAlg to_alg(const ComplexTrig &num){
    ComplexAlg algebraic(num.getMod()*cos(num.getArg()),num.getMod()*sin(num.getArg()));
    return algebraic;
}//trig->alg
ComplexAlg to_alg(const ComplexExp &num){
    double real = round(num.getMod()*cos(num.getArg())*PRECISION)/PRECISION;
    double im = round(num.getMod()*sin(num.getArg())*PRECISION)/PRECISION;
    ComplexAlg algebraic(real,im);
    return algebraic;
}//exp->alg
//---------------------Transform to trig---------------------------------------------------
ComplexTrig to_trig(const ComplexTrig &num){ return num;}//trig->trig
ComplexTrig to_trig(const ComplexAlg &num){
    double module = sqrt(num.getReal()*num.getReal() + num.getIm()*num.getIm());
    double arg = atan2(num.getIm(),num.getReal());
    ComplexTrig geometric(module,arg);
    return geometric;
}//alg->trig
ComplexTrig to_trig(const ComplexExp &num){
    ComplexTrig trigonometric(num.getMod(),num.getArg());
    return trigonometric;
}//exp->trig
//-----------------------Transform to exp-------------------------------------------------
ComplexExp to_exp(const ComplexExp &num){return num;}//exp->exp
ComplexExp to_exp(const ComplexAlg &num){
    double module = sqrt(num.getReal()*num.getReal() + num.getIm()*num.getIm()),arg = atan2(num.getIm(),num.getReal());
    ComplexExp exponential(module,arg);
    return exponential;
}//alg->exp
ComplexExp to_exp(const ComplexTrig &num){
    ComplexExp exponential(num.getMod(),num.getArg());
    return exponential;
}//trig->exp
//-------------------Show All Forms------------------------------------------------------
void show_forms(const ComplexAlg &other){
    std::cout<<"------------------------Forms-----------------------------------------\n";
    std::cout<<"algebraic: ";other.show();
    std::cout<<"trigonometric: ";(to_trig(other)).show();
    std::cout<<"exponential: ";(to_exp(other)).show();
    std::cout<<"----------------------------------------------------------------------\n";
}
void show_forms(const ComplexTrig &other){
    std::cout<<"------------------------Forms-----------------------------------------\n";
    std::cout<<"algebraic: ";(to_alg(other)).show();
    std::cout<<"trigonometric: ";other.show();
    std::cout<<"exponential: ";(to_exp(other)).show();
    std::cout<<"----------------------------------------------------------------------\n";
}
void show_forms(const ComplexExp &other){
    std::cout<<"------------------------Forms-----------------------------------------\n";
    std::cout<<"algebraic: ";(to_alg(other)).show();
    std::cout<<"trigonometric: ";(to_trig(other)).show();
    std::cout<<"exponential: ";other.show();
    std::cout<<"----------------------------------------------------------------------\n";
}
//-------------------Trigonometric Functions---------------------------------------------
//-------------------Sin-----------------------------------------------------------------
ComplexAlg Csin(const ComplexAlg &other){
    ComplexAlg result;
    result.setReal( sin( other.getReal() ) * cosh( other.getIm() ));
    result.setIm(cos( other.getReal() ) * sinh( other.getIm() ));
    return result;
}
//-------------------Cos--------------------------------------------------------------
ComplexAlg Ccos(const ComplexAlg &other){
    ComplexAlg result;
    result.setReal( cos( other.getReal() ) * cosh( other.getIm() ));
    result.setIm(( sin( other.getReal() ) * sinh( other.getIm() ) ) *(-1) );
    return result;
}
//-----------------Tg-----------------------------------------------------------------
ComplexAlg Ctg(const ComplexAlg &other){
    ComplexAlg res;
    res = Csin(other)/Ccos(other);
    return res;
}
//-----------------Ctg----------------------------------------------------------------
ComplexAlg Cctg(const ComplexAlg &other){
    ComplexAlg res;
    res = Ccos(other)/Csin(other);
    return res;
}
//--------------Logarithms-----------------------------------------------------------
ComplexAlg Clog(const ComplexAlg &other){
    ComplexAlg res;
    res.setIm(atan2(other.getIm(),other.getReal())/log(2));
    res.setReal(log2(res.module()));
    return res;
}
ComplexAlg Clg(const ComplexAlg &other){
    ComplexAlg res;
    res.setIm(atan2(other.getIm(),other.getReal())/log(10));
    res.setReal(log10(res.module()));
    return res;
}
ComplexAlg Cln(const ComplexAlg &other){
    ComplexAlg res;
    res.setIm(atan2(other.getIm(),other.getReal()));
    res.setReal(log(other.module()));
    return res;
}
#endif