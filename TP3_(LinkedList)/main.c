#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <conio.h>


int main()
{
    int option = 0;
    int flagTxt = 0;
    int flagBin = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        printf("    Menu:\n\n");
        printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf(" 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
        printf(" 3. Alta de empleado\n");
        printf(" 4. Modificar datos de empleado\n");
        printf(" 5. Baja de empleado\n");
        printf(" 6. Listar empleados\n");
        printf(" 7. Ordenar empleados\n");
        printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf(" 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
        printf(" 10. Salir\n\n");
        printf("Ingrese opcion: ");

        scanf("%d", &option);
        fflush(stdin);

        switch(option)
        {
            case 1:
                if(flagTxt)
                    printf("\nLos empleados ya han sido cargados desde \"data.csv\"\n");

                else if(flagBin)
                    printf("\nLos empleados ya han sido cargados desde \"data.bin\"\n");

                else
                {
                    if(controller_loadFromText("data.csv",listaEmpleados))
                    {
                        printf("\nDatos cargados del texto con exito!");
                        flagTxt = 1;
                    }

                    else
                        printf("\nError al cargar los datos de los empleados desde el texto.");
                }
                break;

            case 2:
                if(flagTxt)
                    printf("\nLos empleados ya han sido cargados desde \"data.csv\"\n");

                else if(flagBin)
                    printf("\nLos empleados ya han sido cargados desde \"data.bin\"\n");

                else
                {
                    if(controller_loadFromBinary("data.bin",listaEmpleados))
                    {
                        printf("\nDatos cargados del binario con exito!");
                        flagBin = 1;
                    }

                    else
                        printf("\nError al cargar los datos de los empleados desde el binario.");
                }
                break;

            case 3:
                if(controller_addEmployee(listaEmpleados))
                    printf("\nAlta exitosa!");

                else
                    printf("\nNo se ha podido dar de alta.");

                break;

            case 4:
                if(ll_isEmpty(listaEmpleados))
                    printf("\nNo hay empleados cargados aun.\n");

                else
                {
                    if(controller_editEmployee(listaEmpleados))
                        printf("\nModificacion exitosa!");

                    else
                        printf("\nNo se ha podido modificar.");
                }
                break;

            case 5:
                if(ll_isEmpty(listaEmpleados))
                    printf("\nNo hay empleados cargados aun.\n");

                else
                {
                    if(controller_removeEmployee(listaEmpleados))
                        printf("\nBaja exitosa!");

                    else
                        printf("\nNo se ha podido dar de baja.");
                }
                break;

            case 6:
                if(ll_isEmpty(listaEmpleados))
                    printf("\nNo hay empleados que mostrar.\n");

                else
                {
                    if(controller_ListEmployee(listaEmpleados))
                        printf("\nSe han mostrado todos los empleados.\n");

                    else
                        printf("\nNo se han podido mostrar todos los empleados.\n");
                }
                break;

            case 7:
                if(ll_isEmpty(listaEmpleados))
                    printf("\nNo hay empleados que ordenar.\n");

                else if(!controller_sortEmployee(listaEmpleados))
                        printf("\nNo se han podido ordenar los empleados.\n");

                break;

            case 8:
                if(controller_saveAsText("data.csv", listaEmpleados))
                    printf("\nEmpleados guardados textualmente con exito.\n");

                else
                    printf("\nNo se pudieron guardar los empleados.\n");

                break;

            case 9:
                if(controller_saveAsBinary("data.bin", listaEmpleados))
                    printf("\nEmpleados guardados en binario con exito.\n");

                else
                    printf("\nNo se pudieron serializar los empleados.\n");

                break;

            case 10:
                printf("\n  Hasta pronto!\n");
                break;
        }

        getch();
        system("cls");

    }while(option != 10);

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}
