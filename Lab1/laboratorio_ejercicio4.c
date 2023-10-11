/* Escriba un programa en C que reciba un número entero correspondiente a un año y
determine si corresponde o no a un año bisiesto. Entregue como mensaje si el año
corresponde o no a bisiesto. */

#include <stdio.h>

int main(){
    int anio;

    printf("Ingrese un anio: ");
    scanf("%d", &anio);

    if (anio%4 == 0){
        printf("\n %d es un anio bisiesto!", anio);
    }else{
        printf("\n %d no es un anio bisiesto...", anio);
    }

    return 0;
}