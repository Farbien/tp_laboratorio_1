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
#include <ctype.h>

#define MAXTYPES 3
#define MAXTFLY 3
#define MAXPASAJEROS 2000
#define MAXTYPES 3
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

typedef struct{
        int id;
        char name[51];
        char lastName[51];
        float price;
        char flyCode[10];
        int typePassanger;
        int statusFlight;
        int isEmpty;
    }ePassenger;

typedef struct{
		int statusFlight;
		char descrpcion[10];
	}eFly;

typedef struct{
		int idTypePassanger;
		char tipo[10];
	}eTypePassanger;

void printTypePassenger(eTypePassanger lista[]);
void CargaForzadaType(eTypePassanger listaTipos[]);
void CargaForzadaFly(eFly listaFly[]);
//void CargaForzadaPassanger(ePassenger lista[])

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
void sortPassengersByName(ePassenger array[], int tam);
void sortPassengersById(ePassenger array[], int tam);

int mostrarMenuInformes();
void promedioImporte(ePassenger array[], int tam) ;


#endif /* FUNCIONES_H_ */
