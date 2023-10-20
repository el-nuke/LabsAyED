/*
Ejercicio número 10: Control y uso de estructuras anidadas.

Crear un programa que cuente con las siguientes estructuras:
    1. Registro, que contiene una nota 1, 2 y 3, además de un promedio.
    2. Alumno, que tiene nombre, edad, número de matrícula y un Registro.

El programa debe recibir por teclado todos los datos, y luego imprimirlos, incluyendo
las notas y el promedio. Debe contar con 3 funciones: ingreso de datos, cálculo del
promedio e impresión de datos. Las 3 deben recibir como parámetros a 2 alumnos
distintos.

En el main solo deben crearse 2 instancias de Alumno y realizar el llamado de las 3
funciones.
*/

#include <iostream>
using namespace std;

struct Registro
{
    double nota1,nota2,nota3, promedio;
};

struct Alumno
{
    string nombre;
    int edad, matricula;
    Registro registro;
};

void ingresar(Alumno& alumno, Alumno& alumno2){
    string str_input;
    int int_input;
    double double_input;

    //Alumno 1
    cout << "Ingresa nombre de alumno 1: ";
    cin >> str_input;
    alumno.nombre = str_input;
    cout << "Ingresa edad de alumno 1: ";
    cin >> int_input; 
    alumno.edad = int_input;
    cout << "Ingresa matricula de alumno 1: ";
    cin >> int_input;
    alumno.matricula = int_input;

    cout << "Ingresa nota 1 de alumno 1: ";
    cin >> double_input;
    alumno.registro.nota1 = double_input;
    cout << "Ingresa nota 2 de alumno 1: ";
    cin >> double_input;
    alumno.registro.nota2 = double_input;
    cout << "Ingresa nota 3 de alumno 1: ";
    cin >> double_input;
    alumno.registro.nota3 = double_input;

    //Alumno 2
    cout << "\nIngresa nombre de alumno 2: ";
    cin >> alumno2.nombre;
    cout << "Ingresa edad de alumno 2: ";
    cin >> alumno2.edad;
    cout << "Ingresa matricula de alumno 2: ";
    cin >> alumno2.matricula;

    cout << "Ingresa nota 1 de alumno 2: ";
    cin >> alumno2.registro.nota1;
    cout << "Ingresa nota 2 de alumno 2: ";
    cin >> alumno2.registro.nota2;
    cout << "Ingresa nota 3 de alumno 2: ";
    cin >> alumno2.registro.nota3;

    return;
}

void promedio(Alumno& alumno, Alumno& alumno2){
    
    alumno.registro.promedio = (alumno.registro.nota1 + alumno.registro.nota2 + alumno.registro.nota3) / 3;
    alumno2.registro.promedio = (alumno2.registro.nota1 + alumno2.registro.nota2 + alumno2.registro.nota3) / 3;

    return;
}

void print(const Alumno& alumno, const Alumno& alumno2){

    cout << "-- Alumno 1 --" << endl;
    cout << "\nNombre: " << alumno.nombre << "\tEdad: " << alumno.edad << endl;
    cout << "Matricula: " << alumno.matricula << endl;
    cout << "Nota 1: " << alumno.registro.nota1 << "\tNota 2: " << alumno.registro.nota2 << "\tNota 3: " << alumno.registro.nota1 << endl;
    cout << "\tPromedio: " << alumno.registro.promedio << endl; 

    cout << "\n\n-- Alumno 2 --" << endl;
    cout << "\nNombre: " << alumno2.nombre << "\tEdad: " << alumno2.edad << endl;
    cout << "Matricula: " << alumno2.matricula << endl;
    cout << "Nota 1: " << alumno2.registro.nota1 << "\tNota 2: " << alumno2.registro.nota2 << "\tNota 3: " << alumno2.registro.nota3 << endl;
    cout << "\tPromedio: " << alumno2.registro.promedio << endl; 

    return;
}

int main(){
    Alumno alumno, alumno2;

    ingresar(alumno, alumno2);
    promedio(alumno, alumno2);
    print(alumno, alumno2);

    return 0;        
}