#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include <conio.h>
#include <string.h>


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int ok = 0;

    if(pArrayListEmployee == NULL)
        return ok;

    FILE* f = fopen(path, "r");

    if(f != NULL)
        ok = parser_EmployeeFromText(f, pArrayListEmployee);

    fclose(f);

    return ok;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ok = 0;

    if(pArrayListEmployee == NULL)
        return ok;

    FILE* f = fopen(path, "rb");

    if(f != NULL)
        ok = parser_EmployeeFromBinary(f, pArrayListEmployee);

    fclose(f);

    return ok;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 0;

    if(pArrayListEmployee == NULL)
        return ok;

    char id[10];
    char nombre[128];
    char horasTrabajadas[10];
    char sueldo[10];

    printf("\n Por favor, ingrese\n\nEl id: ");
    gets(id);
    fflush(stdin);

    printf("\nEl nombre: ");
    gets(nombre);
    fflush(stdin);

    printf("\nLas horas trabajadas: ");
    gets(horasTrabajadas);
    fflush(stdin);

    printf("\nY el sueldo: ");
    gets(sueldo);
    fflush(stdin);

    Employee* emp = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

    if(emp != NULL && !ll_add(pArrayListEmployee, emp))
        ok = 1;

    return ok;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 0;

    if(pArrayListEmployee == NULL)
        return ok;

    int id;
    int out = 0;
    char option;
    char charId[10];
    char nombre[128];
    char horasTrabajadas[10];
    char sueldo[10];
    Employee* emp = NULL;

    controller_ListEmployee(pArrayListEmployee);
    printf("\nIngrese el id del empleado a modificar: ");
    scanf("%d", &id);

    for(int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        emp = (Employee*) ll_get(pArrayListEmployee, i);

        if(emp != NULL && emp->id == id)
        {

            do
            {
                system("cls");

                printf("\n EMPLEADO A EDITAR:\n\n"
                       "  Id          Nombre   Horas Trabajadas   Sueldo\n\n");

                showEmployee(emp);

                printf("\n A. Modificar Id\n B. Modificar Nombre"
                       "\n C. Modificar Horas Trabajadas"
                       "\n D. Modificar Sueldo\n E. Volver\n\n"
                        "Ingrese opcion: ");

                option = getche();
                fflush(stdin);

                printf("\n\n");

                switch(option)
                {
                    case 'a':
                    case 'A':
                        printf("Ingrese el nuevo Id: ");
                        gets(charId);

                        if(employee_setId(emp, atoi(charId)))
                            ok = 1;

                        break;

                    case 'b':
                    case 'B':
                        printf("Ingrese el nuevo nombre: ");
                        gets(nombre);

                        if(employee_setNombre(emp, nombre))
                            ok = 1;

                        break;

                    case 'c':
                    case 'C':
                        printf("Ingrese las nuevas Horas Trabajadas: ");
                        gets(horasTrabajadas);

                        if(employee_setHorasTrabajadas(emp, atoi(horasTrabajadas)))
                            ok = 1;

                        break;

                    case 'd':
                    case 'D':
                        printf("Ingrese el nuevo sueldo: ");
                        gets(sueldo);

                        if(employee_setSueldo(emp, atoi(sueldo)))
                            ok = 1;

                        break;

                    case 'e':
                    case 'E':
                        out = 1;
                        break;
                }
            } while(!out);
        }
    }

    return ok;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 0;

    if(pArrayListEmployee == NULL)
        return ok;

    int id;
    Employee* emp = NULL;

    controller_ListEmployee(pArrayListEmployee);
    printf("\nIngrese el id del empleado a eliminar: ");
    scanf("%d", &id);

    for(int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        emp = (Employee*) ll_get(pArrayListEmployee, i);

        if(emp != NULL && emp->id == id)
        {
            ll_remove(pArrayListEmployee, i);
            ok = 1;
        }
    }

    return ok;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 0;

    if(pArrayListEmployee == NULL)
        return ok;

    int accu = 0;
    int size = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("\n        * * * LISTADO DE EMPLEADOS * * *\n\n");
        printf("  Id          Nombre   Horas Trabajadas   Sueldo\n\n");

        for( int i=0; i < size; i++)
        {
            Employee* emp = ll_get(pArrayListEmployee, i);

            if(emp != NULL)
                accu+= showEmployee(emp);
        }

        if(accu == size)
            ok = 1;
    }

    return ok;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 0;

    if(pArrayListEmployee == NULL)
        return ok;

    int out = 0;
    char option;

        do
            {
                system("cls");

                printf("\n ORDENAR POR:"
                       "\n A. Id ascendente\n B. Id descendente"
                       "\n C. Nombre ascendente\n D. Nombre descendente"
                       "\n E. Menos a mas horas trabajadas\n F. Mas a menos horas trabajadas"
                       "\n G. Menor a mayor sueldo \n H. Mayor a menor sueldo"
                       "\n I. Volver\n\nIngrese opcion: ");

                option = getche();
                fflush(stdin);

                printf("\n\nPor favor, espere...\n");

                switch(option)
                {
                    case 'a':
                    case 'A':

                        if(!ll_sort(pArrayListEmployee, employee_compareById, 1))
                        {
                            controller_ListEmployee(pArrayListEmployee);
                            ok = 1;
                        }
                        else
                            printf("\nError al ordenar empleados.");

                        getch();

                        break;

                    case 'b':
                    case 'B':

                        if(!ll_sort(pArrayListEmployee, employee_compareById, 0))
                        {
                            controller_ListEmployee(pArrayListEmployee);
                            ok = 1;
                        }
                        else
                            printf("\nError al ordenar empleados.");

                        getch();

                        break;

                    case 'c':
                    case 'C':

                        if(!ll_sort(pArrayListEmployee, employee_compareByNombre, 1))
                        {
                            controller_ListEmployee(pArrayListEmployee);
                            ok = 1;
                        }
                        else
                            printf("\nError al ordenar empleados.");

                        getch();

                        break;

                    case 'd':
                    case 'D':

                        if(!ll_sort(pArrayListEmployee, employee_compareByNombre, 0))
                        {
                            controller_ListEmployee(pArrayListEmployee);
                            ok = 1;
                        }
                        else
                            printf("\nError al ordenar empleados.");

                        getch();

                        break;

                    case 'e':
                    case 'E':

                        if(!ll_sort(pArrayListEmployee, employee_compareByHoras, 1))
                        {
                            controller_ListEmployee(pArrayListEmployee);
                            ok = 1;
                        }
                        else
                            printf("\nError al ordenar empleados.");

                        getch();

                        break;

                    case 'f':
                    case 'F':

                        if(!ll_sort(pArrayListEmployee, employee_compareByHoras, 0))
                        {
                            controller_ListEmployee(pArrayListEmployee);
                            ok = 1;
                        }
                        else
                            printf("\nError al ordenar empleados.");

                        getch();

                        break;

                    case 'g':
                    case 'G':

                        if(!ll_sort(pArrayListEmployee, employee_compareBySueldo, 1))
                        {
                            controller_ListEmployee(pArrayListEmployee);
                            ok = 1;
                        }
                        else
                            printf("\nError al ordenar empleados.");

                        getch();

                        break;

                    case 'h':
                    case 'H':

                        if(!ll_sort(pArrayListEmployee, employee_compareBySueldo, 0))
                        {
                            controller_ListEmployee(pArrayListEmployee);
                            ok = 1;
                        }
                        else
                            printf("\nError al ordenar empleados.");

                        getch();

                        break;

                    case 'i':
                    case 'I':

                        printf("\nPresione cualquier tecla para regresar.\n");

                        out = 1;

                        break;
                }
            } while(!out);

    return ok;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* emp;

    if(pArrayListEmployee != NULL && path != NULL && !ll_isEmpty(pArrayListEmployee))
    {
        FILE* f = fopen(path, "w");

        if(f == NULL)
            return todoOk;

        fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");

        for(int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            emp = (Employee*) ll_get(pArrayListEmployee, i);

            fprintf(f, "%d, %s, %d, %d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
        }
        fclose(f);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant;

    if(pArrayListEmployee != NULL && path != NULL && !ll_isEmpty(pArrayListEmployee))
    {
        FILE* f = fopen(path, "wb");

        if(f == NULL)
            return todoOk;

        for(int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            cant = fwrite(ll_get(pArrayListEmployee, i), sizeof(Employee),  1, f );

            if(cant < 1)
            {
                fclose(f);
                return todoOk;
            }
        }
        fclose(f);
        todoOk = 1;
    }
    return todoOk;
}

