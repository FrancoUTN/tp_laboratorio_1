#include "Catania.h"

int suma(int a, int b){

    int resultado = a + b;

    return resultado;
}

int resta(int a, int b){


    int resultado = a - b;

    return resultado;
}

float division(int a, int b){

    float resultado = (float) a / (float) b;

    return resultado;
}

int multiplicacion(int a, int b){

    int resultado = a * b;

    return resultado;
}

long long factorial(int a){

    long long fact = 1;

    while( a > 1 ){
        fact = fact * a;
        a--;
    }

    return fact;
}
