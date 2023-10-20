/*
Ejercicio número 2: Salida de datos.

Crear un programa que muestre en pantalla los valores de 6 variables distintas,
asignadas desde código. Las variables deben ser una de cada uno de los siguientes
tipos: int, float, double, char, string y bool.
*/

#include <iostream>
using namespace std;

int main(){
    // int, float, double, char, string y bool.
    int integer = 2;
    float floating = 2.23;
    double doubledouble = 22.2222;
    char character = 99;
    string stringline = "String";
    bool boolean = true;

    cout << "int: " << integer << endl;
    cout << "float: " << floating << endl;
    cout << "double: " << doubledouble << endl;
    cout << "char: " << character << endl;
    cout << "string: " << stringline << endl;
    cout << "bool: " << boolean << endl;

    return 0;
}