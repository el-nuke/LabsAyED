/*
Ejercicio número 5: Condicionales.

Escribir un programa que solicite una edad, e indique en la salida si la edad
introducida se encuentra dentro del siguiente rango: [18 - 25]
*/

#include <iostream>
using namespace std;

int main(){
    int edad;

    cout << "Ingresa una edad: ";
    cin >> edad;

    if (edad >= 18 && edad <= 25){
        cout << "La edad ingresada (" << edad << ") se encuentra DENTRO del rango [18 - 25]";
    }
    else{
        cout << "La edad ingresada (" << edad << ") se encuentra FUERA del rango [18 - 25]";
    }

    return 0;
}