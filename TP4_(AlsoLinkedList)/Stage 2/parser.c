#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    if(pFile == NULL)
        return 0;

    Employee* emp = NULL;
    int sum;
    char buffer[4][128];

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while(!feof(pFile))
    {
        sum = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        if(sum != 4)
            return 0;

        emp = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

        if(emp == NULL)
            return 0;

        ll_add(pArrayListEmployee, emp);
    }

    return 1;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    if(pFile == NULL)
        return 0;

    Employee* emp = NULL;

    while(!feof(pFile))
    {
        emp = employee_new();

        if(emp == NULL)
            return 0;

        if(fread(emp, sizeof(Employee), 1, pFile) < 1)
            break;

        ll_add(pArrayListEmployee, emp);
    }

    return 1;
}
