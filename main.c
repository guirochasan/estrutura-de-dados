#include <stdio.h>
#include "TAD1.c"
#include "TAD1.h"

int main() {

    float real, imaginary;

    printf("Enter the real part of the complex number: ");
    scanf("%f", &real);
    printf("Enter the imaginary part of the complex number: ");
    scanf("%f", &imaginary);    
    Complex_num* c1 = create_complex_num(real, imaginary);
    Complex_num numero = *c1;
    printf("The complex number is: %.2f + %.2fi\n", numero.real_part, numero.imaginary_part);

return 0;
}