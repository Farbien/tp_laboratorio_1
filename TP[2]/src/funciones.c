/*
 * funciones.c
 *
 *  Created on: 5 may. 2022
 *      Author: Nicolas
 */

#include "funciones.h"


static int idIncremental = 10000;
static int ePassenger_obtenerID();
static int ePassenger_obtenerID() {
	return idIncremental++;
}


int initPassengers(ePassenger list[], int len){
	int rtn = -1;
	int i;

	if (list != NULL) {
		if (len >= 0) {
			for (i = 0; i < len; i++) {
				//INICIALIZO ESTRUCTURA - LIBRE 0 - OCUPADO 1
				list[i].isEmpty = LIBRE;
			}
			rtn = LIBRE;
		}
	}

	return rtn;
}

int mostrarMenu0(){

    int opcionMenu0;

    printf("******************************************************\n");
    printf("\tSISTEMA DE ADMINISTRACION DE PASAJEROS\n");
    printf("******************************************************\n\n");

    printf("Men%c Principal;\n",163);
    printf("1. Alta de pasajero\n");
    printf("2. Modificaci%cn de pasajero\n",162);
    printf("3. Baja de pasajero\n");
    printf("4. Informes: \n");
    printf("5. Salir.\n");




    printf("ingrese la opción deseada: ");
    scanf("%d",&opcionMenu0);

    return opcionMenu0;
}

int mostrarMenuInformes() {
    int opcion;

    printf("\n\n****MENU INFORMES*****\n");
    printf("***********************\n\n");
    printf("Ingrese la opci%cn deseada: \n", 162);
	printf("\n1. Listado de los pasajeros ");
	printf("\n2. Total, promedio de los precios y cantidad qde pasajeros que superan el precio promedio");
	printf("\n3. Pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO");
	printf("\n4. Volver");

	printf("\nOpcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

    return opcion;
}


int buscarEspacioLibre(ePassenger array[], int tam) {
	int rtn = -1;
	int indice;

	if (array != NULL) {
		if (tam >= 0) {
			for (indice = 0; indice < tam; indice++) {
				//BUSCA EL PRIMER ESPACIO LIBRE DE MI ARRAY
				if (array[indice].isEmpty == LIBRE) {
					rtn = indice;
					break;
				}
			}
		}
	}
	return rtn;
}


int findPassengerById(ePassenger array[], int tam, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && tam > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < tam; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].id == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

//ALTAS


int addPassenger(ePassenger pasajero[], int tam) {

	int indiceLibre;
	int fechaValida = 0;

	indiceLibre = buscarEspacioLibre( pasajero,MAXPASAJEROS);


	printf("\nIngrese el nombre del pasajero: ");
	fflush(stdin);
	scanf("%[^\n]", pasajero[indiceLibre].name);
	printf("Ingrese el apellido del pasajero: ");
	fflush(stdin);
	scanf("%[^\n]", pasajero[indiceLibre].lastNmame);

    do {
    	printf("Ingrese el precio valido: ");
    	scanf("%f", &pasajero[indiceLibre].price);
    } while(pasajero[indiceLibre].price < 0);

	printf("Ingrese el c%cdigo de vuelo: ",162);
	scanf("%s", &pasajero[indiceLibre].flyCode);
	printf("Ingrese el tipo de pasajero: ");
	scanf("%d", &pasajero[indiceLibre].typePassanger);
	printf("Ingrese estado de vuelo: ");
	scanf("%d", &pasajero[indiceLibre].statusFlight);
	printf("Ingrese ID del tipo de artista: ");
	printf("\nid\tNombre\tApellido\tPrecio\t\tfly code\tTipo de pasajero\tEstado del vuelo\n");

	pasajero[indiceLibre].id = ePassenger_obtenerID();
	pasajero[indiceLibre].isEmpty = OCUPADO;
	printf("%d \t%s \t%s\t $ %.2f\t %s\t %d \t%d\t %d\n",
	    pasajero[indiceLibre].id,
	    pasajero[indiceLibre].name,
	    pasajero[indiceLibre].lastNmame,
	    pasajero[indiceLibre].price,
	    pasajero[indiceLibre].flyCode,
	    pasajero[indiceLibre].typePassanger,
	    pasajero[indiceLibre].statusFlight);


	return 0;
}

void printAPassenger(ePassenger unPasajero) {
	//PRINTF DE UNO SOLO
	printf("\nid\tNombre\tApellido\tPrecio\t\tfly code\tTipo de pasajero\tEstado del vuelo\tLugar\n");
	printf("%d \t%s \t%s\t $ %.2f\t %d\t %d \t%d\t %d\n",
	    unPasajero.id,
	    unPasajero.name,
	    unPasajero.lastNmame,
	    unPasajero.price,
	    unPasajero.flyCode,
	    unPasajero.typePassanger,
	    unPasajero.statusFlight,
	    unPasajero.isEmpty);

}

int printPassengers(ePassenger array[], int tam) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO PASAJEROS");

	printf("\nid\tNombre\tApellido\tPrecio\t\tfly code\tTipo de pasajero\tEstado del vuelo\tEstado\n");

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && tam > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < tam; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO pasajero
				printAPassenger(array[i]);
				//CONTADOR
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO pasajeros PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}
ePassenger ePassenger_ModificarUno(ePassenger unPasajero) {
	ePassenger auxiliar = unPasajero;
	printf("Ingrese nuevo Nombre: \n");
	fflush(stdin);
	scanf("%s",auxiliar.name);
	printf("Ingrese nuevo Apellido: \n");
	fflush(stdin);
	scanf("%s",auxiliar.lastNmame);
	printf("\nIngrese el precio: ");
	scanf("%f",&auxiliar.price);
	printf("Ingrese nuevo c%cdigo de vuelo: \n",162);
	fflush(stdin);
	scanf("%s",auxiliar.flyCode);
	printf("Ingrese el Tipo de pasajero: ");
	scanf("%d",&auxiliar.typePassanger);


	return auxiliar;
}

int ePassenger_Modificacion(ePassenger array[], int tam) {
	int rtn = 0;
	int idPasajero;
	int index;
	int flag = 0;
	ePassenger auxiliar;
	char confirma;

	//LISTAR TODOS LOS PASAJEROS
	if (printPassengers(array, tam)) {
		//BANDERA EN 1 SI HAY PASAJEROS DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY PASAJEROS PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR

		printf("INGRESE ID A : ");
		fflush(stdin);
		scanf("%d", &idPasajero);

		//BUSCO INDEX POR ID EN ARRAY
		while (findPassengerById(array, tam, idPasajero) == -1) {
			puts("NO EXISTE ID.");


			printf("INGRESE ID A MODIFICAR: ");
			scanf("%d", &idPasajero);
		}

		//OBTENGO INDEX DEL ARRAY A MODIFICAR
		index = findPassengerById(array, tam, idPasajero);

		//LLAMO A FUNCION QUE MODIFICA PASAJERO
		auxiliar = ePassenger_ModificarUno(array[index]);

		do {
    		printf("Se va a modificar un registro, confirma? s/n ");
    		fflush(stdin);
    		scanf("%c",&confirma);
		} while(confirma != 's' && confirma != 'n');

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
		if(confirma=='s') {
		   array[index] = auxiliar;
		}
	}

	return rtn;
}

int removePassenger(ePassenger array[], int tam) {
	int rtn = 0;
	int idPasajero;
	int index;
	int flag = 0;
	char confirma;

	//LISTO TODOS LOS PASAJEROS
	if (printPassengers(array, tam)) {
		//BANDERA EN 1 SI HAY PASAJEROS DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY PASAJEROS PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA

		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idPasajero);

		//BUSCO INDEX POR ID EN ARRAY
		while (findPassengerById(array, MAXPASAJEROS, idPasajero) == -1) {
			puts("NO EXISTE ID.");


			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idPasajero);
		}

		//OBTENGO INDEX DEL ARRAY DE A DAR DE BAJA
		index = findPassengerById(array, MAXPASAJEROS, idPasajero);

        do {
            printf("Se va a eliminar un regidstro, confirma? s/n ");
            fflush(stdin);
            scanf("%c",&confirma);
		} while(confirma != 's' && confirma != 'n');

		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		if(confirma=='s') {
		  	array[index].isEmpty = BAJA;
		}

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}











