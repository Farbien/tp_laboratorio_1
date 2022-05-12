/*
 * funciones.c
 *
 *  Created on: 5 may. 2022
 *      Author: Nicolas
 */

#include <ctype.h>
#include "funciones.h"

eTypePassanger listaTipos[MAXTYPES];


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
	printf("\n2. Total, promedio de los precios y cantidad de pasajeros que superan el precio promedio");
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

void CargaForzadaType(eTypePassanger listaTipos[])
{
	eTypePassanger carga[3] = {{1,"First"},{2,"Business"},{3,"Economy"}};

	printf("ID\t Tipo de pasajero\n");

    for(int i = 0; i<3; i++)
    {
    	listaTipos[i] = carga[i];

    	printf("%d\t %s\n",listaTipos[i].idTypePassanger,listaTipos[i].tipo);

    }

}

void CargaForzadaFly(eFly listaFly[])
{
	eFly carga[] = {{1,"Activo"},{2,"Usado"},{-1,"Cancelado"}};

    for(int i = 0; i<3; i++)
    {
    	listaFly[i] = carga[i];
    }
}

/*void CargaForzadaPassanger(ePassenger lista[])
{
	ePassenger carga[] = {{999990,"Gluzmas","Richard",5000,"JHK213",1,1,1},{999991,"Perez","Juan",4000,"GHH456",2,1,1},{999992,"Lopez","Ana",5000,"PIU789",3,-1,1},{999993,"Gluzmas","Laura",6000,"KJL155",1,0,1},{999994,"Lopez","Juan",5000,"PIU789",3,-1,1}};

	printf("\nid\tNombre\tApellido\tPrecio\t\tfly code\tTipo de pasajero\tEstado del vuelo\tEstado\n");

    for(int i = 0; i<5; i++)
    {
    	lista[i] = carga[i];

    	printf("%d\t %s\t %s\t %.2f\t %s\t %d\t %d\t %d\t\n",lista[i].id,lista[i].lastName,lista[i].name,lista[i].price,lista[i].flyCode,lista[i].typePassanger,lista[i].statusFlight,lista[i].isEmpty);

    }

}
*/

void printTypePassenger(eTypePassanger listaTipos[]) {
	int i;
	int tam = MAXTYPES;
	//CABECERA

	printf("\nid\tTipo de pasajero\n");
	printf("\n---------------------------\n");

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (listaTipos != NULL && tam > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < tam; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			printf("%d %s\n", listaTipos[i].idTypePassanger,listaTipos[i].tipo);

		}
	}
}


int addPassenger(ePassenger pasajero[], int tam) {

	int indiceLibre;
	ePassenger aux[1];



	indiceLibre = buscarEspacioLibre( pasajero,MAXPASAJEROS);

	printf("\nIngrese el nombre del pasajero: ");
	fflush(stdin);
	gets(aux[indiceLibre].name);
	printf("Ingrese el apellido del pasajero: ");
	fflush(stdin);
	gets(aux[indiceLibre].lastName);

    do {
    	printf("\nIngrese precio valido: ");
    	fflush(stdin);
    	scanf("%f", &(aux[indiceLibre].price));

    } while(aux[indiceLibre].price <= 0 );

	printf("Ingrese el c%cdigo de vuelo: ",162);
	fflush(stdin);
	gets( aux[indiceLibre].flyCode);
	printf("Ingrese el tipo de pasajero: ");
	scanf("%d", &aux[indiceLibre].typePassanger);
	printf("Ingrese estado de vuelo: ");
	scanf("%d", &aux[indiceLibre].statusFlight);

	pasajero[indiceLibre] =  aux[indiceLibre];


	printf("\nid\tNombre\t    Apellido\t    Precio\t      Fly code\tPax type\tFly status\n");

	pasajero[indiceLibre].id = ePassenger_obtenerID();
	pasajero[indiceLibre].isEmpty = OCUPADO;
	printf("%d\t %s\t\t %s\t  $ %.2f\t %8s\t %d\t \t%d \n",
	    pasajero[indiceLibre].id,
	    pasajero[indiceLibre].name,
	    pasajero[indiceLibre].lastName,
	    pasajero[indiceLibre].price,
	    pasajero[indiceLibre].flyCode,
	    pasajero[indiceLibre].typePassanger,
	    pasajero[indiceLibre].statusFlight);


	return 0;
}




void printAPassenger(ePassenger unPasajero) {
	//PRINTF DE UNO SOLO
	//printf("\nid\tNombre\tApellido\t           Precio\tfly code\tTipo de pasajero\tEstado del vuelo\tLugar\n");
	printf("%d \t%s \t1\t%s\t\t $ %.2f\t\t %s\t\t %d \t\t%d\t\t %d\n",
	    unPasajero.id,
	    unPasajero.name,
	    unPasajero.lastName,
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

	printf("\nid\tNombre\t\tApellido\tPrecio\tfly code\tTipo de pasajero\tEstado del vuelo\tEstado\n");

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
	scanf("%s",auxiliar.lastName);
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

void promedioImporte(ePassenger array[], int tam) {
    int contador=0;
    int contadorMayores=0;
    float acumulador=0;
    float promedio=0;

    for (int i = 0;i < tam; i++) {
        if (array[i].isEmpty == OCUPADO) {
            acumulador += array[i].price;
            contador++;
        }
    }

    if (contador > 0) {
        promedio = acumulador / contador;
        printf("\nEl total es $ %.2f\n",acumulador);
        printf("\nEl promedio es $ %.2f\n",promedio);
    } else {
        printf("\nNo hay datos cargados");
    }

    if (contador>0) {
        for (int i = 0;i < tam; i++) {
            if (array[i].isEmpty == OCUPADO) {
                if (array[i].price>promedio) {
                    contadorMayores++;
                }
            }
        }
        printf("\n%d - Cantidad de pasajero que superan el precio promedio",contadorMayores);
    }
    system("pause");
 }


void sortPassengersByName(ePassenger listaPassenger[], int tam){
	
	//printPassengers( listaPassenger, tam);

	ePassenger auxPassenger;
    printf("********************************************************************\n");
    printf("\tLISTADO DE PASAJEROS ORDENADO POR APELLIDO Y CODIGO DE VUELO\n");

	printf("id\tFly Code\t Apellido\tNombre\n");
	printf("********************************************************************\n");

	for(int i=0;i<tam-1;i++)
	{       
		for(int j=i+1; j<tam ;j++)
	    {
			if(strcmp(listaPassenger[i].lastName, listaPassenger[j].lastName) > 0)
	        {
	        	auxPassenger=listaPassenger[i];
	            listaPassenger[i]=listaPassenger[j];
	            listaPassenger[j]=auxPassenger;
	        }
	        if(strcmp(listaPassenger[i].lastName, listaPassenger[j].lastName) == 0)
	        {
	        	if(strcmp(listaPassenger[i].flyCode, listaPassenger[j].flyCode) > 0)
	        	{
		        	auxPassenger=listaPassenger[i];
		            listaPassenger[i]=listaPassenger[j];
		            listaPassenger[j]=auxPassenger;
	        	}
	        }
	    }
	}
	for (int i=0;i<tam;i++)
	{
		printf("%d\t%s\t\t %s\t\t\t %s\t\t\t\n",listaPassenger[i].id ,listaPassenger[i].flyCode,listaPassenger[i].lastName,listaPassenger[i].name);
	}
	system("pause");
	system("cls");

}

void sortPassengersById(ePassenger listaPassenger[], int tam) {

	ePassenger auxPassenger;

    printf("********************************************************************\n");
    printf("\tLISTADO DE PASAJEROS ORDENADO POR APELLIDO Y CODIGO DE VUELO\n");
    printf("********************************************************************\n");
	printf("Fly Code\t Apellido\tNombre\tEstado d vuelo\n");
	printf("-----------------------------------------------------------------\n");

		for(int i=0;i<tam-1;i++)
		{
			for(int j=i+1; j<tam ;j++)
		    {
				if(strcmp(listaPassenger[i].flyCode, listaPassenger[j].flyCode) > 0)
				{
					auxPassenger=listaPassenger[i];
					listaPassenger[i]=listaPassenger[j];
					listaPassenger[j]=auxPassenger;
				}
		    }
		}
		for(int i=0;i<tam;i++)
		{
			if(listaPassenger[i].statusFlight == 1)
			{
				printf("%s\t %s\t\t %s\t\t %d\n",listaPassenger[i].flyCode, listaPassenger[i].lastName,listaPassenger[i].name,listaPassenger[i].statusFlight);
			}
		}
		system("pause");
}








