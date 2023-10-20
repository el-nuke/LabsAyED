/*
Ejercicio número 9

Escribir un programa que cuente con una estructura llamada Ciclista, con los siguientes
campos: nombre, edad, club y categoría (debe ser un enum con 3 opciones: juvenil,
senior y veterano). Pedir desde teclado los primeros 3 campos, y asignar el valor de
categoría siguiendo esta regla:
    1. Juvenil - Edad <= 18 años
    2. Senior - 18 años < Edad <= 40 años
    3. Veterano - Edad > 40 años

Al final, debe imprimir todos los datos del corredor, incluida su categoría. Para crear la
instancia de la estructura, debe contar con una función aparte que reciba como
parámetros el nombre, la edad y el club.
*/

#include <iostream>
using namespace std;

enum category{Juvenil, Senior, Veterano};

struct Ciclista
{
    string nombre, club;
    int edad;
    category categoria; 
};

Ciclista crearCiclista(string nombre, int edad, string club){
    Ciclista nCiclista;

    nCiclista.nombre = nombre;
    nCiclista.edad = edad;
    nCiclista.club = club;

    if (nCiclista.edad <= 18){nCiclista.categoria = Juvenil;}
    else if (18 < nCiclista.edad <= 40) {nCiclista.categoria = Senior;}
    else if (nCiclista.edad > 40){nCiclista.categoria = Veterano;}

    return nCiclista;
}

void mostrarCiclista(Ciclista mostrar){
    cout << "\nNombre: " << mostrar.nombre << endl;
    cout << "Edad: " << mostrar.edad << endl;
    cout << "Club: " << mostrar.club << endl;
    
    switch (mostrar.categoria)
    {
    case 0: cout << "Categoria: Juvenil" << endl;
        break;
    case 1: cout << "Categoria: Senior" << endl;
        break;
    case 2: cout << "Categoria: Juvenil" << endl;
        break;
    }
    
    return;
}


int main(){
    string nombre, club;
    int edad;

    cout << "Ingresa nombre: ";
    cin >> nombre;
    
    cout << "Ingresa edad: ";
    cin >> edad;

    cout << "Ingresa club: ";
    cin >> club;

    Ciclista CiclistaEpico = crearCiclista(nombre, edad, club);
    mostrarCiclista(CiclistaEpico);
    
    return 0;
}