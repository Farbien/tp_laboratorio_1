/*
 * funciones.h
 *
 *  Created on: 5 may. 2022
 *      Author: Nicolas
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXPASAJEROS 3
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

typedef struct{
        int id;
        char name[51];
        char lastNmame[51];
        float price;
        char flyCode[10];
        int typePassanger;
        int statusFlight;
        int isEmpty;
    }ePassenger;


int initPassengers(ePassenger list[], int len);

int mostrarMenu0();

int buscarEspacioLibre(ePassenger array[], int tam);
int addPassenger(ePassenger pasajero[], int tam);

void printAPassenger(ePassenger unPasajero);
int printPassengers(ePassenger array[], int tam);

int findPassengerById(ePassenger array[], int tam, int ID);
ePassenger ePassenger_ModificarUno(ePassenger unPasajero);
int ePassenger_Modificacion(ePassenger array[], int tam);

int removePassenger(ePassenger array[], int tam);

int mostrarMenuInformes();


#endif /* FUNCIONES_H_ */
