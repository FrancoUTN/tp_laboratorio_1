#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayEmployees.h"

#define ELEMENTS 1000


int main()
{
    int id = 0;
    int seguir = 1;
    int removeId;
    int removeIndex;

    Employee arrayEmployees[ELEMENTS];

    initEmployees(arrayEmployees, ELEMENTS);

    // En caso de querer hardcodear correcamente, descomnentar la linea de abajo:
    // id = hardcodeEmployees(arrayEmployees, ELEMENTS, 10);

    do
    {

        switch(menu())
        {
        case '1':
            if(!registerEmployee(arrayEmployees, ELEMENTS, id))
            {
                printf("\n Registro exitoso!");
                id++;
            }
            else
            {
                printf("\n No se ha podido hacer el registro.");
            }
            getch();
            break;
        case '2':
            if(anyEmployee(arrayEmployees, ELEMENTS))
            {
                if(modifyEmployee(arrayEmployees, ELEMENTS) == -1)
                {
                    printf("\n Modificacion cancelada.");
                }
                else
                {
                    printf("\n Modificacion exitosa!");
                }
            }
            else
            {
                printf("No hay actualmente ningun empleado.");
            }
            getch();
            break;
        case '3':
            if(anyEmployee(arrayEmployees, ELEMENTS))
            {
                system("cls");
                printEmployees(arrayEmployees, ELEMENTS);
                printf("\nIngrese el Numero de Id del empleado a eliminar: ");
                scanf("%d", &removeId);
                removeIndex = removeEmployee(arrayEmployees, ELEMENTS, removeId);
                if(removeIndex != -1)
                {
                    printf("\n ID            Nombre          Apellido        Salario     Sector\n\n");
                    printOneEmployee(arrayEmployees, removeIndex);
                    printf("\n Ha sido dado/a de baja.");
                }
                else
                {
                    printf("\n Error. Baja cancelada.");
                }
            }
            else
            {
                printf("No hay actualmente ningun empleado.");
            }
            getch();
            break;
        case '4':
            if(anyEmployee(arrayEmployees, ELEMENTS))
            {
                reportsMenu(arrayEmployees, ELEMENTS);
            }
            else
            {
                printf("\n No hay empleados acerca de los cuales informar.");
            }
            getch();
            break;
        case '5':
            seguir = 0;
            printf("   Hasta pronto!\n");
            break;
        default:
            printf("Error. Opcion invalida.");
            getch();
            break;
        }

    }
    while(seguir);

    return 0;
}


