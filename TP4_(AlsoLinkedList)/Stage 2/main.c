#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


int main()
{
    int option = 0;
    int flagTxt = 0;
    int flagBin = 0;
    int flagClon = 0;
    int flagSub = 0;
    int contains;
    int pos;
    void* pElement = NULL;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* subEmpleados = NULL;
    LinkedList* clonEmpleados = NULL;

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
        printf(" 10. Crear subLista\n");
        printf(" 11. Clonar lista\n");
        printf(" 12. Comparar la lista clonada con la original\n");
        printf(" 13. Transferir el ultimo empleado de la lista original a la subLista\n");
        printf(" 14. Salir\n\n");
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

                system("cls");
                printf("\nQue lista desea mostrar?\n\n"
                       " Opciones:\n\n"
                       "A- Original\n"
                       "B- SubLista\n"
                       "C- Clon\n\n");

                switch(getch())
                {
                    case 'a':
                    case 'A':

                        if(ll_isEmpty(listaEmpleados))
                            printf("\nNo hay empleados que mostrar.\n");

                        else
                            controller_ListEmployee(listaEmpleados);

                        break;

                    case 'b':
                    case 'B':

                        if(ll_isEmpty(subEmpleados))
                            printf("\nNo hay empleados que mostrar.\n");

                        else
                            controller_ListEmployee(subEmpleados);

                        break;

                    case 'c':
                    case 'C':

                        if(ll_isEmpty(clonEmpleados))
                            printf("\nNo hay empleados que mostrar.\n");

                        else
                            controller_ListEmployee(clonEmpleados);

                        break;

                    default:

                        printf("Opcion invalida.");

                        break;
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

                if(ll_isEmpty(listaEmpleados))
                    printf("\nNo hay empleados para copiar.\n");

                else
                {
                    subEmpleados = controller_subList(listaEmpleados);

                    if(subEmpleados != NULL)
                    {
                        printf("\nSubLista creada con exito!");
                        flagSub = 1;
                    }

                    else
                    {
                        ll_deleteLinkedList(subEmpleados);
                        printf("\nError al intentar crear subLista.");
                    }
                }

                break;


            case 11:

                if(ll_isEmpty(listaEmpleados))
                    printf("\nNo hay empleados para clonar.\n");

                else
                {
                    clonEmpleados = ll_clone(listaEmpleados);

                    if(clonEmpleados != NULL)
                    {
                        printf("\nLista clonada con exito!");
                        flagClon = 1;
                    }

                    else
                    {
                        ll_deleteLinkedList(clonEmpleados);
                        printf("\nError al intentar clonar la lista");
                    }
                }

                break;

            case 12:

                if(!flagClon)
                {
                    printf("\nAun no se ha clonado ninguna lista.");
                    break;
                }

                contains = ll_containsAll(clonEmpleados, listaEmpleados);

                if(contains)
                    printf("\nLa lista clonada contiene todos los empleados de la original.");

                else if(!contains)
                    printf("\nLa lista original contiene empleados que no estan en la lista clonada.");

                else
                    printf("\nError en la comparacion.");

                break;

            case 13:

                if(!flagSub)
                {
                    printf("\nNo hay aun ninguna subLista a la cual transferir el empleado");
                    break;
                }


                pElement = ll_pop(listaEmpleados, ll_len(listaEmpleados) - 1);

                if(pElement == NULL)
                {
                    printf("\nError.");
                    break;
                }

                printf("\nIngrese la posicion de la subLista en la que quiere colocar al empleado trasferido: ");
                scanf("%d", &pos);

                if(!ll_push(subEmpleados, pos, pElement))
                   printf("\nEmpleado transferido con exito!");

                else
                    printf("\nError en la transferencia.");

                break;

            case 14:
                printf("\n  Hasta pronto!\n");
                break;
        }

        getch();
        system("cls");

    }while(option != 14);

    ll_deleteLinkedList(listaEmpleados);

    if(flagClon)
        ll_deleteLinkedList(clonEmpleados);

    if(flagSub)
        ll_deleteLinkedList(subEmpleados);

    return 0;
}
