#include <stdio.h>
#include <stdlib.h>
#include "TAD1.h"

struct complex_num  {

    float  real_part;
    float imaginary_part;
    char imaginary_unit;

};

float power(float base, int exponent) {

    if (exponent == 0){ int power = 1;}

    int power = 1;
    for (int i = 0; i < exponent; i++){
        
        power *= base;
    }

    return power;
}

Complex_num* create_complex_num(float real, float imaginary) {

    Complex_num* ptr = (Complex_num*) malloc(sizeof(Complex_num));

    ptr -> real_part = real;
    ptr -> imaginary_part = imaginary;
    ptr -> imaginary_unit = 'i';

    return ptr;
}

Complex_num* somacomplex(Complex_num* c1, Complex_num* c2) {

    Complex_num* sum = (Complex_num*) malloc(sizeof(Complex_num));

    sum -> real_part = c1 -> real_part + c2 -> real_part;
    sum -> imaginary_part = c1 -> imaginary_part + c2 -> imaginary_part;
    sum -> imaginary_unit = 'i';

    return sum;
}

Complex_num* multiplicacomplex(Complex_num* c1, Complex_num* c2) {

    Complex_num* product = (Complex_num*) malloc(sizeof(Complex_num));

    product -> real_part = (c1 -> real_part * c2 -> real_part) - (c1 -> imaginary_part * c2 -> imaginary_part);
    product -> imaginary_part = (c1 -> real_part * c2 -> imaginary_part) + (c1 -> imaginary_part * c2 -> real_part);
    product -> imaginary_unit = 'i';

    return product;
}
Complex_num* powercomplex(Complex_num* num, int exponent) {

    if (exponent == 0){
        Complex_num* powered = (Complex_num*) malloc(sizeof(Complex_num));
        powered -> real_part = 1;
        powered -> imaginary_part = 0;
        powered -> imaginary_unit = 'i';
        return powered;
    }
    if (exponent == 1){return num;}
    if (exponent > 1){
        
    Complex_num* powered = (Complex_num*) malloc(sizeof(Complex_num));

    for (int i = 0; i < exponent; i++){
        powered = multiplicacomplex(num, num);
    }

    return powered;}

    
}

Complex_num* invert(Complex_num* num) {


    num -> real_part = num -> real_part/power(num -> real_part, 2) + power(num -> imaginary_part, 2);
    num -> imaginary_part = - num -> imaginary_part/power(num -> real_part, 2) + power(num -> imaginary_part, 2);
    Complex_num* inverted = (Complex_num*) malloc(sizeof(Complex_num));
    inverted -> imaginary_unit = 'i';

    return inverted;
} 