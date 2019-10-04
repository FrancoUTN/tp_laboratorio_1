#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayEmployees.h"


char menu()
{
    system("cls");
    printf("*** MENU ***\n\n\n");
    printf("1. ALTAS\n\n");
    printf("2. MODIFICAR\n\n");
    printf("3. BAJA\n\n");
    printf("4. INFORMAR:\n\n");
    printf("5. SALIR.\n\n");

    return getch();
}


int initEmployees(Employee* list, int len)
{
    int Ok = -1;

    for(int i = 0; i < len; i++)
    {
        list[i].isEmpty = 1;
        Ok = 0;
    }
    return Ok;
}


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector, int firstEmptyPosition)
{
    int ok = -1;
    list[firstEmptyPosition].id = id;
    strcpy(list[firstEmptyPosition].name, name);
    strcpy(list[firstEmptyPosition].lastName, lastName);
    list[firstEmptyPosition].salary = salary;
    list[firstEmptyPosition].sector = sector;
    list[firstEmptyPosition].isEmpty = 0;
    ok = 0;

    return ok;
}


int registerEmployee(Employee* list, int len, int id)
{
    system("cls");

    int ok = -1;
    char name[99];
    char lastName[99];
    float salary;
    int sector;
    int firstEmptyPosition = -1;

    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty)
        {
            firstEmptyPosition = i;
        }
    }

    if(firstEmptyPosition == -1)
    {
        printf("\n Error. Sistema completo.\n");
    }
    else
    {
        printf("\n Ingrese el nombre: ");
        fflush(stdin);
        scanf("%s", name);
        validString(name, 51, "\n Error. Reingrese el nombre: ");

        printf("\n Ingrese el apellido: ");
        fflush(stdin);
        scanf("%s", lastName);
        validString(lastName, 51, "\n Error. Reingrese el apellido: ");

        printf("\n Ingrese el salario: ");
        salary = validFloat("\n Error. Reingrese el salario: ");

        printf("\n Ingrese el sector: ");
        sector = validInteger("\n Error. Reingrese el sector: ");

        ok = addEmployee(list, len, id, name, lastName, salary, sector, firstEmptyPosition);
    }

    return ok;
}


int printEmployees(Employee* list, int length)
{
    system("cls");

    printf("\n                    * * * * * EMPLEADOS * * * * *\n\n\n ID   "
           "         Nombre          Apellido        Salario     Sector\n\n");

    for(int i = 0; i < length; i++)
    {
        if(!list[i].isEmpty)
        {
            printOneEmployee(list, i);
        }
    }

    return 0;
}


void printOneEmployee(Employee* list, int index)
{
    printf("%3d   %15s   %15s    $ %9.2f      %2d\n", list[index].id, list[index].name, list[index].lastName, list[index].salary, list[index].sector);

    // Aclaración: la precisión de las cadenas de caracteres correspondientes al nombre y apellido fue fijada
    //             en 15 en lugar de 51 para facilitar la prueba y visualización del programa.
}


int hardcodeEmployees(Employee* list, int len, int cant)
{
    int i = 0;

    if(cant <= len)
    {
        Employee auxList[] = {{0, "Rodrigo", "Rodriguez", 10000, 3, 0},
            {1, "Clara", "Claridad", 54004.44, 4, 0},
            {2, "Marta", "Martillan", 7654.3, 2, 0},
            {3, "Sol", "Solari", 18500, 1, 0},
            {4, "Benito", "Benitez", 11213.45, 2, 0},
            {5, "Lorena", "Lorenz", 7998.90, 4, 0},
            {6, "Xiao", "Ming", 8200.05, 3, 0},
            {7, "Raul", "Rawson", 8201.06, 1, 0},
            {8, "Aureliano", "Buendia", 5000.25, 1, 0},
            {9, "Don", "Nadie", 2.50, 2, 0}
        };

        for(; i < cant; i++)
        {
            list[i] = auxList[i];
        }
    }

    return i;
}


void validString(char* stringRequired, int size, char* errorMessage)
{
    while(strlen(stringRequired) > size)
    {
        printf("%s", errorMessage);
        fflush(stdin);
        scanf("%s", stringRequired);
    }

    fflush(stdin);
}


int validInteger(char* errorMessage)
{
    int integerRequired;

    while(!scanf("%d", &integerRequired))
    {
        fflush(stdin);
        printf("%s", errorMessage);
    }

    fflush(stdin);

    return integerRequired;
}


float validFloat(char* errorMessage)
{
    float floatRequired;

    while(!scanf("%f", &floatRequired))
    {
        fflush(stdin);
        printf("%s", errorMessage);
    }

    fflush(stdin);

    return floatRequired;
}


int findEmployeeById(Employee* list, int len, int id)
{
    int index = -1;

    for(int i = 0; i < len; i++)
    {
        if(list[i].id == id && !list[i].isEmpty)
        {
            index = i;
        }
    }

    return index;
}


int modifyEmployee(Employee* list, int len)
{
    system("cls");

    char opcion;
    char name[99];
    char lastName[99];
    float salary;
    int sector;
    int id;

    printEmployees(list, len);

    printf("\nIngrese el Numero de Id del empleado a modificar: ");
    scanf("%d", &id);

    int index = findEmployeeById(list, len, id);

    if(index == -1)
    {
        printf("\n No hay ningun empleado con ese Numero de Id.\n");
    }
    else
    {

        printf("\n ID            Nombre          Apellido        Salario     Sector\n\n");
        printOneEmployee(list, index);

        printf("\nSeleccione dato a modificar:\n\n1. Nombre"
               "\n2. Apellido\n3. Salario\n4. Sector\n5. Cancelar\n\n");

getOption:
        fflush(stdin);
        opcion = getch();

        switch(opcion)
        {
        case '1':
            printf("\nIngrese el nuevo nombre: ");
            fflush(stdin);
            scanf("%s", name);
            validString(name, 51, "\n Error. Vuelva a ingresar el nuevo nombre: ");
            strcpy(list[index].name, name);
            break;

        case '2':
            printf("\nIngrese el nuevo apellido: ");
            fflush(stdin);
            scanf("%s", lastName);
            validString(lastName, 51, "\n Error. Reingrese el nuevo apellido: ");
            strcpy(list[index].lastName, lastName);
            break;

        case '3':
            printf("\nIngrese el nuevo salario: ");
            salary = validFloat("\nError. Vuelva a ingresar el nuevo salario: ");
            list[index].salary = salary;
            break;

        case '4':
            printf("\nIngrese el nuevo sector: ");
            sector = validInteger("\nError. Reingrese el nuevo sector: ");
            list[index].sector = sector;
            break;

        case '5':
            index = -1;
            break;

        default:
            goto getOption;
        }
    }

    return index;
}


int anyEmployee(Employee* list, int len)
{
    int yes = 0;

    for(int i = 0; i < len; i++)
    {
        if(!list[i].isEmpty)
        {
            yes = 1;
        }
    }

    return yes;
}


int removeEmployee(Employee* list, int len, int id)
{
    int index = findEmployeeById(list, len, id);

    list[index].isEmpty = 1;

    return index;
}


int sortEmployees(Employee* list, int len, int order)
{
    int ok = -1;
    Employee auxEmployee;
    int swap = 0;


    for(int i = 0; i < len -1; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            if(order == 1 && !list[i].isEmpty && !list[j].isEmpty)
            {
                if(list[i].sector > list[j].sector)
                {
                    swap = 1;
                }

                else if(list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) > 0)
                {
                    swap = 1;
                }

                if(swap)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                    ok = 0;
                }

                swap = 0;
            }

            else if(!order && !list[i].isEmpty && !list[j].isEmpty)
            {
                if(list[i].sector < list[j].sector)
                {
                    swap = 1;
                }
                else if(list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) < 0)
                {
                    swap = 1;
                }

                if(swap)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                    ok = 0;

                }

                swap = 0;
            }
        }
    }

    return ok;
}


void reportsMenu(Employee* list, int len)
{
    int order;
    int opcion;
    int cont = 0;
    int overAverage = 0;
    float total = 0;
    float average;

    system("cls");

    printf("\n   Que informe desea ver?\n (Ingrese el numero correspondiente):\n\n"
           "1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n"
           "2. Total y promedio de los salarios,"
           " y cuantos empleados superan el salario promedio.\n\n");

    fflush(stdin);
    opcion = getch();

    switch (opcion)
    {
    case '1':
        system("cls");
        printf(" **Listado de los empleados ordenados alfabeticamente por Apellido y Sector**"
               "\n\nIngrese 0 para orden descendente, o 1, para orden ascendente: ");
        scanf("%d", &order);
        sortEmployees(list, len, order);
        printEmployees(list, len);
        break;

    case '2':

        for(int i = 0; i < len; i++)
        {
            if(!list[i].isEmpty)
            {
                total += list[i].salary;
                cont++;
            }
        }

        average = total / cont;

        for(int j = 0; j < len; j++)
        {
            if(list[j].salary > average && !list[j].isEmpty)
            {
                overAverage++;
            }
        }

        printf("El total de salarios es de: $%.2f\n\n"
               "%d empleados superan el salario promedio, que es de $%.2f", total, overAverage, average);

        break;

    default:
        printf("Opcion invalida.");
        break;
    }

    printf("\n\nPresione cualquier tecla para volver al menu principal.");
}
