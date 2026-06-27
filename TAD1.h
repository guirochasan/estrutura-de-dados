#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct complex_num Complex_num;


float power(float base, int exponent);

Complex_num* somacomplex(Complex_num* c1, Complex_num* c2) ;
Complex_num* multiplicacomplex(Complex_num* c1, Complex_num* c2);
Complex_num* invert(Complex_num* num);
Complex_num* create_complex_num(float real, float imaginary); 

#endif