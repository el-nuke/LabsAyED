/* Escriba un programa en C que reciba el nombre y la edad y entregue como resultado
un mensaje señalando “Hola TEXTO, usted tiene NÚMERO años de edad” */

#include <stdio.h>
#include <string.h>

int main(){
    char nombre[50];
    int edad = 0;

    printf("\nIngrese un nombre: ");
    scanf("%s", nombre);

    printf("\nIngrese una edad: ");
    scanf("%d", &edad);

    printf ("\n\n");
    printf("Hola %s, usted tiene %d años de edad", nombre, edad);

    return 0;
}