/*
Ejercicio número 4: Operaciones básicas.

Crear un programa que reciba desde teclado un nombre y 2 números. El programa
debe saludar y mostrar en pantalla la suma, resta, multiplicación, división y el promedio
de todos los resultados anteriores.
*/
#include <iostream>
using namespace std;

int main(){
    string nombre;
    double num1, num2;
    double suma, resta, producto, cociente, promedio;

    cout << "Hola usuario, ingresa tu nombre: ";
    cin >> nombre;

    cout << "\nAhora ingresa 2 numeros: ";
    cin >> num1;
    cin >> num2;

    suma = num1 + num2;
    resta = num1 - num2;
    producto = num1 * num2;
    
    if (num2 == 0) { cociente = 0; } 
    else {cociente = num1 / num2;}
    
    promedio = (num1 + num2)/2;


    cout << "\n\nHola " << nombre << ", estos son los resultados:" << endl;
    cout << "Suma: " << suma << endl; 
    cout << "Resta: " << resta << endl; 
    cout << "Producto: " << producto << endl; 
    cout << "Cociente: " << cociente << endl;
    cout << "Promedio: " << promedio << endl;

    return 0;
}