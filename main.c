#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Catania.h"

int main()
{
    int A;
    int B;
    int i = 0;
    int j = 0;
    int flag1;
    int flag2;
    int flaga;
    int flagb;
    int flagc;
    int flagd;
    int flage;
    char opcionNum;
    char opcionLetra;

    do{
        printf("\n              CALCULADORA\n\n");

        printf("Ingrese el numero correspondiente a la opcion deseada:\n\n");

        if(flag1){
            printf("1. Ingresar primer operando (A = x)\n\n");
        } else{
            printf("1. Ingresar primer operando (A = %d)\n\n", A);
        }
        if(flag2){
            printf("2. Ingresar segundo operando (B = y)\n\n");
        } else{
            printf("2. Ingresar segundo operando (B = %d)\n\n", B);
        }
        printf("3. Calcular todas las operaciones\n\n");
        printf("4. Salir\n\n");

        etiqueta1:

        opcionNum = getch();

        switch(opcionNum){
            case '1':
                system("cls");
                printf("1. Ingrese el primer operando:\n");
                scanf("%d", &A);
                flag1 = 0;
            break;

            case '2':
                system("cls");
                printf("2. Ingrese el segundo operando:\n");
                scanf("%d", &B);
                flag2 = 0;
            break;

            case '3':
                if(flag1 || flag2){
                    printf("    Error. Primero debe establecer los operandos en las opciones 1 y 2.\n\n");

                    goto etiqueta1;
                } else {
                    system("cls");

                    printf("\n Para los valores %d y %d, ingrese la letra\n correspondiente a la operacion que desee realizar:\n\n", A, B);
                    printf("a) Calcular la suma\n");
                    printf("b) Calcular la resta\n");
                    printf("c) Calcular la division\n");
                    printf("d) Calcular la multiplicacion\n");
                    printf("e) Calcular el factorial\n");
                    printf("f) Volver\n");

                    do{
                        if(flaga || flagb || flagc || flagd || flage){
                            opcionLetra = getch();
                        } else {
                            printf("\n   Ya ha realizado todas las operaciones posibles.\n   Pulse cualquier tecla para regresar.\n");
                            getch();
                            break;
                        }

                        switch(opcionLetra){

                            case 'a':
                                if(flaga){
                                    printf("\n      El resultado de %d + %d es: %d\n", A, B, suma(A,B));
                                    i = 0;
                                    flaga = 0;
                                }
                                break;

                            case 'b':
                                if(flagb){
                                    printf("\n      El resultado de %d - %d es: %d\n", A, B, resta(A,B));
                                    i = 0;
                                    flagb = 0;
                                }
                                break;

                            case 'c':
                                if(flagc){
                                    if(B == 0){
                                        printf("\n      No es posible dividir por cero.\n");
                                    } else{
                                        printf("\n      El resultado de %d / %d es: %.2f\n", A, B, division(A,B));
                                    }
                                    i = 0;
                                    flagc = 0;
                                }
                                break;

                            case 'd':
                                if(flagd){
                                    printf("\n      El resultado de %d * %d es: %d\n", A, B, multiplicacion(A,B));
                                    i = 0;
                                    flagd = 0;
                                }
                                break;

                            case 'e':
                                if(flage){
                                    printf("\n      El factorial de %d es %lli", A, factorial(A));
                                    printf(", y el de %d: %lli\n", B, factorial(B));
                                    i = 0;
                                    flage = 0;
                                }
                                break;

                            case 'f':
                                break;

                            default:
                                if(i < 3){
                                    i++;

                                    printf("\n  Error. Seleccione una operacion, o pulse 'f' para volver. (Aviso %d/3)\n", i);

                                } else {
                                    opcionLetra = 'f';
                                }
                        }

                    }while(opcionLetra != 'f');

                i = 0;
                flaga = 1;
                flagb = 1;
                flagc = 1;
                flagd = 1;
                flage = 1;
            }

            break;

            case '4':
                break;

            default:

                if(j < 3){
                    j++;

                    printf("    Error. Ingrese una opcion, o pulse 4 para salir. (Aviso %d/3)\n\n", j);

                    goto etiqueta1;
                } else {
                    return 0;
                }
        }

        j = 0;

        system("cls");

    }while(opcionNum != '4');

    return 0;
}
