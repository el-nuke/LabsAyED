/*
Ejercicio número 6: Bucles.

Crear un programa que genere un número aleatorio secreto entre 1 y 100. Luego, el
usuario debe intentar adivinar el número generado. Para lograrlo, deberá ingresar un
número, y el programa debe indicar si es menor, mayor o igual al número pensado. Si
es menor o mayor, el usuario debe seguir intentando hasta adivinar el número. Al final,
debe indicar la cantidad de intentos que le tomó adivinarlo.
*/

#include <iostream>
#include <time.h>
using namespace std;

int main(){
    srand(time(NULL));

    int numero = rand()%100; //Divide un numero aleatorio en 100 y retorna el resto
    int guess, intentos=0;
    bool win=false;

    if (numero == 0) {numero=1;} //Previene 0 como num. secreto

    cout << "Se ha generado un numero secreto entre 1 y 100, intenta adivinarlo!" << endl;

    do{
        intentos++;
        cout << "Ingresa un numero: ";
        cin >> guess;

        if (guess < numero){cout << "\nEl numero ingresado es MENOR al numero secreto" << endl;}

        if (guess > numero){cout << "\nEl numero ingresado es MAYOR al numero secreto" << endl;}

        if (guess == numero){win=true;}

    }while (!win);

    cout << "\nFelicidades! Adivinaste el numero secreto! \n Te ha tomado " << intentos << " intentos!";

    return 0;
}