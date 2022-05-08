/*
 ============================================================================
 Name        : TP[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "funciones.h"
#include <stdio.h>

setbuf(stdout, NULL);


int main()
{

    int opcionMenu0;
    int opcionInformes;
    ePassenger listaPasajeros[MAXPASAJEROS];

    // inicializar en cero

    initPassengers(listaPasajeros,MAXPASAJEROS);

    do{
        opcionMenu0 = mostrarMenu0();
    switch(opcionMenu0){
        case 1:   //ALTAS
            addPassenger(listaPasajeros, MAXPASAJEROS);
            break;
        case 2:  //MODIFICACION
            ePassenger_Modificacion(listaPasajeros, MAXPASAJEROS);
            break;
        case 3:  //BAJAS
        	removePassenger(listaPasajeros, MAXPASAJEROS);
            break;
        case 4:  //INFORMAR
            opcionInformes =  mostrarMenuInformes();
            switch(opcionInformes){
                case 1:

                    break;
                case 2:

                    break;
                case 3:

                    break;
            }
        break;

    }

    }while(opcionMenu0 != 5);


    return 0;
}


