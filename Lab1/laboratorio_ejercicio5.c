/* Escriba un programa en C que genere 5 números enteros aleatorios, los almacene en
un arreglo. Entregue como resultado la impresión de los números según el orden que se
encuentra en el arreglo, primero de manera ascendente y luego descendente.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int rng[4], orden[4];
    int temp = 0;
    
    srand(time(NULL));

    printf("\n Arreglo: ");
    for (int c = 0; c < 5; c++){
        rng[c] = rand()%100;
        printf("%d ", rng[c]);
    }
    
    for (int c = 0; c < 5 ; c++){
        temp = 0;
        for (int v = 0; v < 5; v++){
            if (rng[temp] <= rng[v]){
                temp = v;
            }
        }
        orden[c] = rng[temp];
        rng[temp] = 0;
    }


    printf("\n\n Ascendente: ");
    for (int c=4; c >- 1; c--){
        printf("%d ", orden[c]);
    }

    printf("\n Descendente: ");
    for (int c=0; c < 5; c++){
        printf("%d ", orden[c]);
    }

    printf("\n.");


    return 0;
}