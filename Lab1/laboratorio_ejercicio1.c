/* Escriba un programa en C que permita evidenciar el uso de todos los tipos de datos
básicos. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int integers = 1;
    float floats = 1.123456789;
    char characters = 99; // las variables char se asignan usando la tabla de caracteres ASCII, es este caso, 99 = c

    printf("\nInt: %d", integers);
    printf("\nFloat: %.4f", floats); // debido a %.4f, solo mostrará 4 decimales
    printf("\nChar: %c", characters);

    return 0;
}