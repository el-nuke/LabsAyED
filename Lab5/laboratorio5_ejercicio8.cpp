/*
Ejercicio número 8: Funciones.

Crear un programa que reciba desde teclado un nombre de usuario y una
contraseña. Estos deben ser pasados como parámetros a una función llamada Login,
que retorna verdadero si el nombre de usuario es “user1” y la contraseña es “1234”. Si
al menos uno de los dos no corresponde, entonces retorna falso.

El programa debe tener 3 intentos máximos de Login. Debe indicar si el acceso fue
exitoso o no.
*/

#include <iostream>
using namespace std;

bool login(string user, string pass){
    if (user == "user1" && pass == "1234"){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string user, pass;
    int intentos=0;
    bool logged=false;

    do
    {
        cout << "Ingrese nombre de usuario: ";
        cin >> user;

        cout << "Ingrese clave: ";
        cin >> pass;

        if (login(user, pass)){
            cout << "\nAcceso exitoso" << endl;
            logged = true;
        }else{
            intentos++;
            cout << "\nNombre y/o clave incorrectas" << "\nQuedan " << 3-intentos << " intentos.\n" << endl;
        }

    } while (intentos < 3 && !logged);

    if (logged){ cout << "Bienvenido user1!\n" << endl;}
    else { cout << "\nSe ha bloqueado el acceso\n" << endl;}

    return 0;
}