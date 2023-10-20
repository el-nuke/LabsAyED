/*
Ejercicio número 3: Entrada y salida de datos.

Escribir un programa que reciba desde teclado un número entero y un string, y luego
los imprima en pantalla.
*/

#include <iostream>
using namespace std;

int main(){
    int num;
    string word;

    cout << "Ingrese un numero entero: ";
    cin >> num;

    cout << "Ingrese una palabra: ";
    cin >> word;

    cout << "\nNumero ingresado: " << num << "\nPalabra ingresada: " << word;
    
    return 0;
}