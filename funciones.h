/*
 * funciones.h
 *
 *  Created on: 9 abr. 2022
 *      Author: Nicolas
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>

int mostrarMenu(float x,float y,float z);
int pedirKilometros(float km);
float pedirPrecioAr(float ar);
float pedirPrecioLa(float la);
int calcularCostos(float km,float ar,float la);
int mostrarInformes(float x,float y,float z);
int cargaForzada(void);


#endif /* FUNCIONES_H_ */
