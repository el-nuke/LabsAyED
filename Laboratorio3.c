/*
Ejercicio número 1
Escriba una estructura en C que permita almacenar la información de Estudiantes.
Cada Estudiante debe tener los campos nombre, número de lista (entero) y promedio
final.

Ejercicio número 2
Escriba un programa para almacenar información de cinco estudiantes y muestre el
estudiante con el promedio más alto.

Ejercicio número 3
Escriba una estructura en C que permita almacenar la información de Libros. Cada
Libro debe tener los campos título, autor, ISBN y precio.

Ejercicio número 4
Escriba un programa para almacenar información de cinco libros y muestre el libro con
el precio más alto.

Ejercicio número 5
Escriba una estructura en C que permita almacenar la información de Productos.
Cada producto debe tener los campos nombre, ID, precio y cantidad. Es necesario
implementar un menú que permita al usuario seleccionar las opciones para; agregar
un producto, mostrar el producto de mayor valor, mostrar el stock actual de productos
y salir. Considere en la solución la definición de funciones para realizar los cálculos y
mostrar la información solicitada

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Ejercicio 1
struct Estudiante
{
    char nombre [50];
    int numLista;
    float promedioFinal;
};

//Ejercicio 2
void ej2_Estudiantes(){
    struct Estudiante estudiantes[5];
    int prom=0, index=0;

    for (int c=0; c<5; c++ ){
        
        char _nombre[50];
        int _numLista=0;
        float _promedioFinal=0;

        printf("\nIngrese nombre del estudiante %d: ", c+1);
        scanf("%s", _nombre);
        printf("\nIngrese num. de lista del estudiante %d: ", c+1);
        scanf("%d", &_numLista);
        printf("\nIngrese promedio final del estudiante %d: ", c+1);
        scanf("%f", &_promedioFinal);
        
        strcpy(estudiantes[c].nombre, _nombre);
        estudiantes[c].numLista = _numLista;
        estudiantes[c].promedioFinal = _promedioFinal;

        if (estudiantes[c].promedioFinal > prom){
            prom = estudiantes[c].promedioFinal;
            index = c;
        }
    }

    printf("\n\nEl estudiante con el promedio mas alto es %s (nro. %d) con un promedio final de %.1f", estudiantes[index].nombre, estudiantes[index].numLista, estudiantes[index].promedioFinal);
}

//Ejercicio 3
struct Libro
{
    char titulo[50], autor[50];
    int ISBN;
    float precio;
};

//Ejercicio 4
void ej4_Libros(){

    struct Libro libros[5];
    int caro=0, index=0;

    for (int c=0; c<5; c++ ){
        
        char _titulo[50], _autor[50];
        int _isbn=0;
        float _precio=0;

        printf("\nIngrese titulo del libro %d: ", c+1);
        scanf("%s", _titulo);
        printf("\nIngrese autor del libro %d: ", c+1);
        scanf("%s", _autor);
        printf("\nIngrese ISBN del libro %d: ", c+1);
        scanf("%d", &_isbn);
        printf("\nIngrese precio del libro %d: ", c+1);
        scanf("%f", &_precio);
        
        strcpy(libros[c].titulo, _titulo);
        strcpy(libros[c].autor, _autor);
        libros[c].ISBN = _isbn;
        libros[c].precio = _precio;

        if (libros[c].precio > caro){
            caro = libros[c].precio;
            index = c;
        }
    }

    printf("\n\nEl libro mas caro es: \n'%s' de %s, \nISBN: %d \nPrecio: %.1f", libros[index].titulo, libros[index].autor, libros[index].ISBN, libros[index].precio);

}

//Ejercicio 5
struct Producto
 {
    char nombre[50];
    int ID, cantidad;
    float precio;
 };

void ej5_Productos(){
    struct Producto stock[50];
    
    for (int c=0; c<50; c++){
        stock[c].ID = -1;
    }

    int salir=0, opcion=0;

    

    do{
        float max=0; 
        int index=-1;

        printf("\n\n1: Agregar un producto");
        printf("\n2: Mostrar el producto de mayor valor");
        printf("\n3: Mostrar el stock actual de productos");
        printf("\n4: Salir");

        printf("\n\nElige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            //Agregar un producto
            for (int c=0; c<50; c++){
                if (stock[c].ID == -1){
                    
                    char _nombre[50];
                    int _ID, _cantidad;
                    float _precio;

                    printf("\nIngrese nombre del producto: ");
                    scanf("%s", _nombre);
                    printf("\nIngrese ID del producto: ");
                    scanf("%d", &_ID);
                    printf("\nIngrese precio del producto: ");
                    scanf("%f", &_precio);
                    printf("\nIngrese cantidad del producto: ");
                    scanf("%d", &_cantidad);

                    strcpy(stock[c].nombre, _nombre);
                    stock[c].ID = _ID;
                    stock[c].cantidad = _cantidad;
                    stock[c].precio = _precio;

                    break;
                }
            }
            break;
        case 2:
            //Mostrar el producto de mayor valor
            
            for (int c=0; c<50; c++){
                if (stock[c].ID != -1 && stock[c].precio > max){
                    max = stock[c].precio;
                    index = c;
                }
            }

            if(index != -1){
                printf("\nEl producto de mayor valor es: \nNombre: %s (ID: %d)\nPrecio: %.1f \nCantidad: %d", stock[index].nombre, stock[index].ID, stock[index].precio, stock[index].cantidad);
            }else{
                printf("\nNo se pudo encontrar el producto de mayor valor.");
            }

            break;
        case 3:
            //Mostrar el stock actual de productos
            for (int c=0; c<50; c++){
                if (stock[c].ID != -1){
                    printf("\n\nNombre: %s (ID: %d)\nPrecio: %.1f \nCantidad: %d", stock[c].nombre, stock[c].ID, stock[c].precio, stock[c].cantidad);
                }else{
                    if (c==0){
                        printf("\nNo hay productos registrados");
                    }
                }
            }
            break;
        case 4:
            //Salir
            break;
        default:
            break;
        }

    }while(opcion!=4);
}

//main
int main(){
    int opcion=0;

    printf("\n\n\n1: ej2_Estudiantes()");
    printf("\n2: ej4_Libros()");
    printf("\n3: ej5_Productos()");
    printf("\nx: Ninguno");

    printf("\n\nElige una opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        printf("\n-- ej2_Estudiantes() --\n");
        ej2_Estudiantes();
        break;
    case 2:
        printf("\n-- ej4_Libros() --\n");
        ej4_Libros();
        break;
    case 3:
        printf("\n-- ej5_Productos() --\n");
        ej5_Productos();
        break;
    default:
        break;
    }
}