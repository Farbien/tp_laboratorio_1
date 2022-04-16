#include "funciones.h"

#define BTC 4610734.81  // Cotización 16/04/22 20:42
#define PAGOTD 0.90  // proporcion precio con descueto e intereses
#define PAGOTC 1.25  // proporcion precio con descueto e intereses


    float ar;
    float la;
    float precioTotalSinDescuentoAr;
    float precioTotalSinDescuentoLa;
    float precioTarjetaDebitoAr;
    float precioTarjetaDebitoLa;
    float precioTarjetaCreditoAr;
    float precioTarjetaCreditoLa;
    double precioBitcoinAr;
    double precioBitcoinLa;
    float diferenciaTotal;

void Pausar(){
	int aux;

		printf("Presione cualquier tecla para continuar...");
		scanf("%d",&aux);
}

int MostrarMenu(float x,float y,float z){
     ///Esta función  muestra las opciones que se ofrecen como menú principal, muestra los valores cargados
     /// de cantidad de kilómetros, y precios por kilómetro de las compañías aéreas, y solicita el ingreso de una
     /// opción del menú. Luego devuelve un entero validado entre las opciones de 1 a 6.


    int opcion;

        printf("MENU PRINCIPAL\nIngrese las opciones del men%c:\n\n",163);
        printf("Carga actual kil%Cmetros:                             %.2f kms\n",162,x);
        printf("Precio actual por kil%Cmetro Aerol%cneas Argentinas:   $  %.2f\n",162,161,y);
        printf("Precio actual por kil%Cmetro Latam:                   $  %.2f\n\n\n",162,z);
        printf("1. Ingresar Kil%cmetros \n",130);
        printf("2. Ingresar Precio por kil%Cmetro de Vuelo por empresa\n",162);
        printf("3. Calcular todos los costos\n");
        printf("4. Informe de Resultados\n");
        printf("5. Carga forzada de datos\n");
        printf("6. Salir\n\n\n");
        printf("Elija su opci%cn: ",162);
        scanf("%d",&opcion);

        while(opcion<1 || opcion>6){
            printf("ERROR. La opci%cn no existe. Reintente: ",162);

            scanf("%d",&opcion);
        }
        printf("Opci%cn elegida %d: \n",162,opcion);
        return opcion;

    }

int PedirKilometros(float km){
    ///La función pide el ingreso de la cantidad de kilómetros que demandará el viaje, valida
    /// que el valor no sea negativo o cero, y lo devuelve al menú.

	printf("Ingrese los kil%Cmetros: ",162);
    fflush(stdin);
    scanf("%f",&km);
    while(km<0){
        printf("ERROR: Reingrese los kil%Cmetros: ",162);
        fflush(stdin);
        scanf("%f",&km);

        }
    printf("Ahora ingrese al menú anterior para determinar los precios actuales de la oferta disponible.\n\n");

    system("pause");

    return km;

}


float PedirPrecioAr(float ar){
    /// La función pide precio por kilómetro para Aerolineas Argentinas, valida que el mismo no sea un valor
    ///  negativo o cero, y lo devuelve al menú.
    printf("Ingrese precio por kil%Cmetro para Aerol%cneas Argentinas: ",162,161);
    fflush(stdin);
    scanf("%f",&ar);
    while(ar<0){
        printf("ERROR: Ingrese precio por kil%Cmetro para Aerol%cneas Argentinas: ",162,161);
        fflush(stdin);
        scanf("%f",&ar);
        }
		system("pause");

		return ar;

		}

float PedirPrecioLa(float la){
    /// La función pide precio por kilómetro para Latam, valida que el mismo no sea un valor
    ///  negativo o cero, y lo devuelve al menú.

    printf("Ingrese precio por kil%Cmetro para Latam: ",162);
    fflush(stdin);
    scanf("%f",&la);
    while(la<0){
        printf("Ingrese precio por kil%Cmetro para Latam: ",162);
        setbuf(stdin,NULL);
        scanf("%f",&la);
        }
    system("pause");

    return la;

    }

int CalcularCostos(float km,float ar,float la){

    ///La función calcula los costos de acuerdo a los parámetros recibidos y muestra si pudo realizar los cálculos.
    /// Si no pudo hacerlos, muestra un mensaje de error solicitando la verificación de los datos cargados.

	int rta;

    if(km>0 && ar>0 && la>0){

    precioTotalSinDescuentoAr=km*ar;
    precioTotalSinDescuentoLa=km*la;

    precioTarjetaDebitoAr=precioTotalSinDescuentoAr*PAGOTD;
    precioTarjetaDebitoLa=precioTotalSinDescuentoLa*PAGOTD;

    precioTarjetaCreditoAr=precioTotalSinDescuentoAr*PAGOTC;
    precioTarjetaCreditoLa=precioTotalSinDescuentoLa*PAGOTC;

    precioBitcoinAr=(double)precioTotalSinDescuentoAr/BTC;
    precioBitcoinLa=(double)precioTotalSinDescuentoLa/BTC;

        if(precioTotalSinDescuentoAr>precioTotalSinDescuentoLa){
            diferenciaTotal=precioTotalSinDescuentoAr-precioTotalSinDescuentoLa;
         }
        else{
            diferenciaTotal=precioTotalSinDescuentoLa-precioTotalSinDescuentoAr;
            }
    printf("\n****************************************************\n");
    printf("\n** Los c%clculos se realizaron satisfactoriamente ***\n",160);
    printf("\n*****************************************************\n");
        }
    else{
        printf("\n*******************************************\n");
        printf("\n**** ERROR: verifique la carga de datos ***\n");
        printf("\n*******************************************\n");
        }
    system("pause");
    rta=0;


    return rta;
    }



int MostrarInformes(float x,float y,float z){


	///La función solo muestra por pantalla los cálculos realizados en la función CalcularCostos, donde
	/// puede apreciarse los costos del viaje para cada tipo de pago, con una comparación entre conpañías.

    int rta;

   if(x>0 && y>0 && z>0){
		printf("Precio Total Aerol%cneas Argentinas: $ %.2f\n",161,precioTotalSinDescuentoAr);
		printf("a) Precio Total tarjeta de d%cbito: $ %.2f\n",130,precioTarjetaDebitoAr);
		printf("b) Precio Total tarjeta de cr%cdito: $ %.2f\n",130,precioTarjetaCreditoAr);
		printf("c) Precio Total pagando con bitcoins: BTC %.8lf\n\n",precioBitcoinAr);

		printf("Precio Total Latam: $ %f\n",precioTotalSinDescuentoLa);
		printf("a) Precio Total tarjeta de d%cbito: $ %.2f\n",130,precioTarjetaDebitoLa);
		printf("b) Precio Total tarjeta de cr%cdito: $ %.2f\n",130,precioTarjetaCreditoLa);
		printf("c) Precio Total pagando con bitcoins:BTC %.8lf\n\n",precioBitcoinLa);

		printf("La diferencia de precio es: $ %.2f\n\n",diferenciaTotal);
        rta=0;
   	   }

    else{
        printf("\n\n** ERROR: verifique la carga de datos **\n\n");
        rta=7;
        }
   system("pause");
   return rta;


    }


int CargaForzada(void){
    ///Esta función realiza las operaciones como lo hace la función CalcularCostos con la diferencia que los cálculos
    ///  se realizan con valores prestablecidos (no variables). Luego muestra los cálculos.

	int rta;
    float km=7090;
    float precioTotalSinDescuentoAr=162965;
    float precioTotalSinDescuentoLa=159339;
    float precioTarjetaDebitoAr;
    float precioTarjetaDebitoLa;
    float precioTarjetaCreditoAr;
    float precioTarjetaCreditoLa;
    double precioBitcoinAr;
    double precioBitcoinLa;
    float diferenciaTotal;


    ar=precioTotalSinDescuentoAr/km;
    la=precioTotalSinDescuentoLa/km;

    precioTarjetaDebitoAr=precioTotalSinDescuentoAr*PAGOTD;
    precioTarjetaDebitoLa=precioTotalSinDescuentoLa*PAGOTD;

    precioTarjetaCreditoAr=precioTotalSinDescuentoAr*PAGOTC;
    precioTarjetaCreditoLa=precioTotalSinDescuentoLa*PAGOTC;

    precioBitcoinAr=(double)precioTotalSinDescuentoAr/BTC;
    precioBitcoinLa=(double)precioTotalSinDescuentoLa/BTC;

        if(precioTotalSinDescuentoAr>precioTotalSinDescuentoLa){
            diferenciaTotal=precioTotalSinDescuentoAr-precioTotalSinDescuentoLa;
            }
        else{
            diferenciaTotal=precioTotalSinDescuentoLa-precioTotalSinDescuentoAr;
            }

    printf("Precio Total Aerol%cneas Argentinas: $ %.2f\n",161,precioTotalSinDescuentoAr);
    printf("a) Precio Total tarjeta de d%cbito: $ %.2f\n",130,precioTarjetaDebitoAr);
    printf("b) Precio Total tarjeta de cr%cdito: $ %.2f\n",130,precioTarjetaCreditoAr);
    printf("c) Precio Total pagando con bitcoins: BTC %.8lf\n\n",precioBitcoinAr);

    printf("Precio Total Latam: $ %f\n",precioTotalSinDescuentoLa);
    printf("a) Precio Total tarjeta de d%cbito: $ %.2f\n",130,precioTarjetaDebitoLa);
    printf("b) Precio Total tarjeta de cr%cdito: $ %.2f\n",130,precioTarjetaCreditoLa);
    printf("c) Precio Total pagando con bitcoins:BTC %.8lf\n\n",precioBitcoinLa);

    printf("La diferencia de precio es: $ %.2f\n\n",diferenciaTotal);
    system("pause");
    rta=0;

    return rta;
    }

