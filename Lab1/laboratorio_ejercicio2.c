/* Escriba un programa en C que reciba dos números desde el teclado y aplique a lo
menos 4 operaciones aritméticas para demostrar su funcionamiento. */

#include <stdio.h>
#include <stdlib.h>

int main(){
    float num1, num2;
    float res;

    printf("Ingrese 2 numeros: ");
    scanf("%f %f", &num1, &num2);

    res = num1 + num2;
    printf("\n suma: %.2f", res);
    
    res = num1 - num2;
    printf("\n resta: %.2f", res);

    res = num1 * num2;
    printf("\n producto: %.2f", res);

    if (num2 == 0){
        printf("\n cociente: indivisible");
    }else{
        res = num1 / num2;
        printf("\n cociente: %f", res);
    }

    return 0;
}