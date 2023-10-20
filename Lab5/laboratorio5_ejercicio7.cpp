/*
Ejercicio número 7: Funciones.

Escribir un programa que reciba desde teclado dos números mayores que 0 (debe
contar con validación). Estos deben ser pasados como parámetros a una función que
los compare y retorne el número mayor. En caso de ser iguales, el programa debe
indicarlo.
*/

#include <iostream>
using namespace std;

int comparacion(double num1, double num2){

    if (num1 > num2){
        return num1;
    }

    if (num1 < num2){
        return num2;
    }
}

int main(){
    double num1, num2, nummayor;

    do
    {
        cout << "Ingresa dos numeros mayores a 0: " << endl;
        cin >> num1;
        cin >> num2;

        if (num1 < 0||num2 < 0){cout << "Uno de los numeros es menor a 0 >:C" << endl;}

    } while (num1 < 0 || num2 < 0);
    
    

    if (num1 == num2){
        cout << "Los numeros son iguales :/" << endl;
    }
    else{
        nummayor = comparacion(num1, num2);
        cout << "El numero mayor es " << nummayor << " :D" << endl;
    }

    return 0;
}