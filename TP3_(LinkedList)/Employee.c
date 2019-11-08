#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmp = employee_new();

    if(newEmp != NULL)
    {
        if(!(employee_setId(newEmp, atoi(idStr)) &&
           employee_setNombre(newEmp, nombreStr) &&
           employee_setHorasTrabajadas(newEmp, atoi(horasTrabajadasStr)) &&
           employee_setSueldo(newEmp, atoi(sueldoStr))))
        {
            newEmp = NULL;
        }
    }

    return newEmp;
}

Employee* employee_new()
{
    Employee* newEmp = (Employee*) malloc(sizeof(Employee));

    if(newEmp != NULL)
    {
        newEmp->id = 0;
        strcpy(newEmp->nombre, " ");
        newEmp->horasTrabajadas = 0;
        newEmp->sueldo = 0;
    }

    return newEmp;
}



int employee_setId(Employee* this, int id)
{
    int ok = 0;

    if( this != NULL && id > 0)
    {
        this->id = id;
        ok = 1;
    }

    return ok;
}

int employee_setNombre(Employee* this, char* nombre)
{
    int ok = 0;

    if( this != NULL && strlen(nombre) < 128)
    {
        strcpy(this->nombre, nombre);
        ok = 1;
    }

    return ok;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ok = 0;

    if( this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        ok = 1;
    }

    return ok;
}


int employee_setSueldo(Employee* this,int sueldo)
{
    int ok = 0;

    if( this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        ok = 1;
    }

    return ok;
}


int showEmployee(Employee* this)
{
    int ok = 0;

    if(this != NULL)
    {
        printf("%4d %15s         %3d Hs       $%5d\n",
                this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        ok = 1;
    }

    return ok;
}


int employee_getId(Employee* this,int* id)
{
    if(this == NULL || id == NULL)
        return 0;

    *id = this->id;

    return 1;
}

int employee_getNombre(Employee* this,char* nombre)
{
    if(this == NULL || nombre == NULL)
        return 0;

    strcpy(nombre, this->nombre);

    return 1;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    if(this == NULL || horasTrabajadas == NULL)
        return 0;

    *horasTrabajadas = this->horasTrabajadas;

    return 1;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this == NULL || sueldo == NULL)
        return 0;

    *sueldo = this->sueldo;

    return 1;
}


int employee_compareById(void* emp1, void* emp2)
{
    if(emp1 == NULL || emp2 == NULL)
        return 0;

    int id1;
    int id2;

    employee_getId((Employee*) emp1, &id1);
    employee_getId((Employee*) emp2, &id2);

    if(id1 == id2)
        return 0;

    else if(id1 > id2)
        return 1;

    else
        return -1;
}

int employee_compareByNombre(void* emp1, void* emp2)
{
    if(emp1 == NULL || emp2 == NULL)
        return 0;

    char nombre1[128];
    char nombre2[128];

    employee_getNombre((Employee*) emp1, nombre1);
    employee_getNombre((Employee*) emp2, nombre2);

    return strcmp(nombre1, nombre2);
}

int employee_compareBySueldo(void* emp1, void* emp2)
{
    if(emp1 == NULL || emp2 == NULL)
        return 0;

    int sueldo1;
    int sueldo2;

    employee_getSueldo((Employee*) emp1, &sueldo1);
    employee_getSueldo((Employee*) emp2, &sueldo2);

    if(sueldo1 == sueldo2)
        return 0;

    else if(sueldo1 > sueldo2)
        return 1;

    else
        return -1;
}

int employee_compareByHoras(void* emp1, void* emp2)
{
    if(emp1 == NULL || emp2 == NULL)
        return 0;

    int horasTrabajadas1;
    int horasTrabajadas2;

    employee_getHorasTrabajadas((Employee*) emp1, &horasTrabajadas1);
    employee_getHorasTrabajadas((Employee*) emp2, &horasTrabajadas2);

    if(horasTrabajadas1 == horasTrabajadas2)
        return 0;

    else if(horasTrabajadas1 > horasTrabajadas2)
        return 1;

    else
        return -1;
}
