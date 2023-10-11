#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int check(int num){
    int anio = num % 2018;

    if (anio < 0 || anio > 4){
        printf("\nFecha invalida, solo se aceptan valores entre 2018 y 2022");
        return -1;
    }else{
        return anio; //Fecha valida
    }
}

/* Ejercicio número 1
Escriba una estructura en C que permita almacenar la información de Compañías.
Dentro de este problema es necesario guardar su nombre y la cantidad de empleados
que ha tenido en el periodo de años comprometido entre 2018 y 2022.
Para almacenar la información de la cantidad de empleados por año, considere
trabajar con un arreglo. */

struct Company
{
    char nombre[50];
    int cantEmpleados[5]; // 2018=0, 2019=1, 2020=2, 2021=3, 2022=4

};


/* Ejercicio número 2
Escriba una función llamada add_employee_data que toma una estructura Compañia
y dos enteros correspondientes al año y a la cantidad de empleados. */

void add_employee_data(struct Company *company, int anioUser, int empleados){
    
    int anio = check(anioUser);
    
    if (anio!=-1){
        company->cantEmpleados[anio] = company->cantEmpleados[anio] + empleados;
        printf("Agregados %d empleados al anio %d de %s", empleados, anioUser, company->nombre);
    }else{
        printf("No se pudo agregar.");
    }
}

/* Ejercicio número 3
Escriba una función llamada find_total_employees que toma una estructura
Compañia y un entero correspondiente al año como parámetro. Retorna la cantidad
de empleados para ese año. */

int find_total_employees(struct Company *company, int anioUser){
    int anio = check(anioUser);
    
    if (anio!=-1){
        return company->cantEmpleados[anio];
    }
    else{
        return 0;
    }   
}

/* Ejercicio número 4
Escriba una función llamada delete_employee_data que toma una estructura
Compañia y un entero correspondiente al año como parámetro. Realiza la
eliminación de la cantidad de empleados del año señalado. */

void delete_employee_data(struct Company *company, int anioUser){
    int anio = check(anioUser);
    
    if (anio!=-1){
        company->cantEmpleados[anio] = 0;
        printf("Eliminados los datos del año %d de %s", anioUser, company->nombre);
    }else{
        printf("No se pudo eliminar.");
    }
}

/* Ejercicio número 5
Escriba una función llamada calculate_average_employees que toma una estructura
Compañia y retorna el promedio de empleados que tiene. */

float calculate_average_employees(struct Company *company){
    int prom = 0;

    for (int c=0; c<5; c++){
        prom = prom + company->cantEmpleados[c];
    }

    prom = prom/5;

    return prom;
}

/* Ejercicio número 6
Escriba una función llamada general_average_employees que toma todas las
compañías y un entero correspondiente al año como parámetro. Retorna el promedio
de empleados del año. */

float general_average_employees(struct Company companies[5], int anioUser){
    int anio = check(anioUser);
    
    if (anio!=-1){
        int prom=0,promc=0;
        for (int c=0; c<5; c++){
            if (companies[c].cantEmpleados[anio] != -1){
                promc++;
                prom = prom + companies[c].cantEmpleados[anio];
            }
        }
        prom = prom/promc;
        return prom;
    }

    return 0;
}


/* Ejercicio número 7
Actualice su programa en C para recibir el nombre del archivo que contiene la
información por parámetros. Considere por cada línea la información de cada
empresa según lo establecido en la problemática desarrollada en los ejercicios
anteriores. */

int main(){

    FILE *file = fopen("companies.txt", "r");

    if (file == NULL) {
        perror("\nNo se pudo encontrar 'companies.txt' \n");
        return 1;
    }

    struct Company companies[5];
    int cComps=0;

    while (fscanf(file, "%s %d %d %d %d %d", companies[cComps].nombre, &companies[cComps].cantEmpleados[0], &companies[cComps].cantEmpleados[1], &companies[cComps].cantEmpleados[2], &companies[cComps].cantEmpleados[3], &companies[cComps].cantEmpleados[4]) == 6)
    {
        cComps++;

        if(cComps >= 5){
            printf("\nMaximo de companias alcanzado");
            break;
        }
    }

    printf("\n%d companias cargadas correctamente!", cComps);

    int salir=0;
    
    printf("\n\nPara usar las distintas funciones ingresa: \n'(nro. opcion) (parametro)* (parametro2)* (parametro3)*' \n Ej: '2 3 2020' find_total_employees en comp3 durante 2020 \nPara ingresar una compania, usa su orden en el .txt, desde 1");

    do
    {
        int opcion=0;
        printf("\n\n1: add_employee_data (compania, anio, empleados) \n2: find_total_employees (compania, anio)\n3: delete_employee_data (compania, anio) \n4: calculate_average_employees (compania) \n5: general_average_employees (anio) \n6: Salir \n\n");

        scanf("%d", &opcion);

        int companiaIN=0, anioIN=0, empleadosIN=0;
        switch (opcion)
        {
        case 1:
            scanf("%d %d %d", &companiaIN, &anioIN, &empleadosIN);
            add_employee_data(&companies[companiaIN-1], anioIN, empleadosIN);
            break;

        case 2:
            scanf("%d %d", &companiaIN, &anioIN);
            printf("%s contaba con %d empleados durante %d", companies[companiaIN-1].nombre, find_total_employees(&companies[companiaIN-1], anioIN), anioIN);
            break;

        case 3:
            scanf("%d %d", &companiaIN, &anioIN);
            delete_employee_data(&companies[companiaIN-1], anioIN);
            break;

        case 4:
            scanf("%d", &companiaIN);
            printf("Promedio de empleados en %s: %.2f", companies[companiaIN-1].nombre, calculate_average_employees(&companies[companiaIN-1]));
            break;

        case 5:
            scanf("%d", &anioIN);
            printf("Promedio de empleados en todas las companias durante %d: %.2f", anioIN, general_average_employees(companies, anioIN));
            break;

        case 6: 
            salir=1;
            break;

        default:
            break;
        }

        if (salir == 0){
            printf("\n");
            system("pause");
        }

    } while (salir==0);
    
    printf("weno xau");
    return 0;
}