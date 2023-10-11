/*
Ejercicio número 1
Escriba una función en C que permita determinar si un número dado es par o impar.
Realice 2 llamadas a la función para corroborar su funcionamiento.

Ejercicio número 2
Escriba una función en C que permita determinar si un número dado es primo o no.
Realice 2 llamadas a la función para corroborar su funcionamiento.

Ejercicio número 3
Escriba una función en C que permita determinar el promedio, valor máximo y valor
mínimo dentro de un arreglo de enteros. Realice la llamada a la función para
corroborar su funcionamiento.

Ejercicio número 4
Escriba una función en C que permita determinar el índice de un número dentro de un
arreglo de enteros. La función debe devolver el índice de la primera aparición del
valor buscado y entregar un -1 si no se encuentra el valor. Realice 2 llamadas a la
función para corroborar su funcionamiento.

Ejercicio número 5
Escriba una función en C que permite eliminar valores duplicados de un arreglo de
enteros. La función debe devolver el nuevo tamaño del arreglo. Realice 2 llamadas a
la función para corroborar su funcionamiento.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void ej1_ParOImpar(int num){
    if (num %2 == 0){
        printf("\n%d es par.", num);
    }else{
        printf("\n%d es impar.", num);
    }
}

int ej2_Primo(int num){ 
    
    if(num % 1 == 0 && num % num == 0 && num % 2 == 1){
        printf("\n%d es primo", num);
    }
    else{
        printf("\n%d no es primo", num);
    }
    

}

int ej3_promMaxMin(int array[5]){
    float suma = 0, prom;
    int min=100, max=0;

    for (int c = 0; c < 5 ; c++){
        suma = suma + array[c];
    }

    prom = suma/5;
    printf("\nPromedio: %.2f ", prom);

    min = max = array[0];
    for (int c = 0; c < 5 ; c++){
        if (min > array[c]){
            min = array[c];
        }
        if (max < array[c]){
            max = array[c];
        }
    }
    printf("\n Min: %d ", min);
    printf("\n Max: %d ", max);
}

int ej4_buscarIndice(int array[5], int numABuscar){
    
    for (int c=0; c<5; c++){
        if (array[c] == numABuscar){
            return c;
        }
    }
    return -1;
}

int ej5_eliminarDuplicados(int array[5]){
    int eliminados=0;

    for (int c=0; c<5; c++){
        for (int v=c+1; v<5;v++){
            //printf("%d %d \n", array[c],array[v]);
            if (array[c] == array[v]){
                eliminados++;
                for (int r = c; r<5; r++){
                    array[r] = array[r+1];
                }
            }
        }
    }

    return 5-eliminados;
}


int main(){

    int array[5], arrayarra[5], retorno;

    srand(time(NULL));

    printf("\n Arreglo:\n ");
    for (int c = 0; c < 5; c++){
        array[c] = rand()%100;
        printf("%d ", array[c]);
    }

    printf("\n Arreglo con repetidos:\n ");
    for (int c = 0; c < 5; c++){
        if (c < 3){
            arrayarra[c] = c+1;
        }else {
            arrayarra[c] = c-1;
        }
        
        printf("%d ", arrayarra[c]);
    }



    printf("\n");
    ej1_ParOImpar(2);
    ej1_ParOImpar(array[0]);

    printf("\n");
    ej2_Primo(5);
    ej2_Primo(array[1]);

    printf("\n");
    ej3_promMaxMin(array);

    printf("\n");
    
    printf("\nSe busco 4 en el arreglo, retorno: %d", ej4_buscarIndice(array, 4));
    printf("\nSe busco 89 en el arreglo, retorno: %d", ej4_buscarIndice(array, 89));

    //EJERCICIO 5 INCOMPLETO
    printf("\n");
    printf("\nSe eliminaron los duplicados de arreglo normal, nuevo tamanio: %d", ej5_eliminarDuplicados(array));
    printf("\nSe eliminaron los duplicados de arreglo con reps., nuevo tamanio: %d", ej5_eliminarDuplicados(arrayarra));
    //EJERCICIO 5 INCOMPLETO



    return 0;
}
