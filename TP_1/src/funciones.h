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
#include <ctype.h>
#include <string.h>
#include <math.h>


int MostrarMenu(float x,float y,float z);
int PedirKilometros(float km);
float PedirPrecioAr(float ar);
float PedirPrecioLa(float la);
int CalcularCostos(float km,float ar,float la);
int MostrarInformes(float x,float y,float z);
int CargaForzada(void);
void Pausar(void);


#endif /* FUNCIONES_H_ */
