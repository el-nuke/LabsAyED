#include <iostream>
#include <list>
#include <string>
using namespace std;

/*
Ejercicio número 1
Crea un programa que lea una lista de números desde el usuario y realiza las siguientes
operaciones matemáticas sobre ellos: suma, promedio y el producto.
*/

void ej1_lista(){
    list<double> listadenumeros;
    double res=0, input;

    cout << "Introduce 5 numeros: " << endl;
    for (int c=0;c<5;c++){
        cin >> input;
        listadenumeros.push_front(input);
    }

    cout << "Numeros: ";
    for (double e : listadenumeros){
        cout << e << " ";
    }
    cout << endl;

    for (double e : listadenumeros){
        res = res + e;
    }
    cout << "Suma: " << res << endl;
    
    res = res/listadenumeros.size();
    cout << "Promedio: " << res << endl;

    res=0;
    for (double e : listadenumeros){
        if (res == 0){
            res = res + e;
        }
        else{
            res = res * e;
        }
    }
    cout << "Producto: " << res << endl;

}

/*
Ejercicio número 2
Cree un programa que implemente la función recursiva de cálculo de factorial.
*/

int ej2_factorial(int n){
    if (n < 0){
        return 0;
    }

    if (n == 0){
        return 1;
    }
    else{
        return n * ej2_factorial(n-1);
    }
}

/*
Ejercicio número 3
Cree un programa que implemente la función recursiva de cálculo de la secuencia de
fibonacci.
*/

int ej3_fibonacci(int n){
    if (n < 2){
        return n;
    }else{
        return ej3_fibonacci(n-1) + ej3_fibonacci(n-2);
    }
}

/*
Ejercicio número 4
Cree un programa que implemente la función recursiva que permite determinar si una
palabra u oración es palindrome.
*/

bool ej4_palindrome(string str){
    if (str.length() <= 1){
        return true;
    }
    if (str[0] == str[str.length()-1]){
        return ej4_palindrome(str.substr(1, str.length()-2));
    }
    return false;
}

/*
Ejercicio número 5
Cree un menú para acceder a los cuatro ejercicios desarrollados en el presente
laboratorio. Debe considerar una correcta validación para no tener errores al
momento de ingresar información por parte del usuario.
*/

int main(){
    string strinput;
    bool loop=true;

    do
    {
        cout << "\n\n1: ej1_lista() \n2: ej2_factorial() \n3: ej3_fibonacci \n4: ej4_palindrome() \n5: Salir \n\n Elige una opcion: ";
        cin >> strinput;
        int input = stoi(strinput);

        switch (input)
        {
        case 1:
            ej1_lista();
            break;

        case 2:
            cout << "Ingresa un numero entero positivo para calcular su factorial: ";
            cin >> input;
            cout << input << "! = " << ej2_factorial(input) << endl;
            break;

        case 3:
            cout << "Ingresa la cantidad de iteraciones para fibonacci: ";
            cin >> input;
            cout << "Tras " << input << " iteraciones desde 0, fibonnacci resulta en " << ej3_fibonacci(input) << endl;
            break;

        case 4:
            cout << "Ingresa una palabra o frase para comprobar si es palindrome: ";
            cin.ignore();
            getline(cin, strinput);
            if (ej4_palindrome(strinput)){
                cout << "'" << strinput << "' es palindrome!" << endl;
            }else{
                cout << "'" << strinput << "' no es palindrome..." << endl;
            }
            break;

        case 5:
            loop = false;
            break;
        
        default:
            cout << "what";
            strinput = "";
            input = 0;
            break;
        }        
    } while (loop);
    
    cout << "weno xao" << endl;
    return 0;
}