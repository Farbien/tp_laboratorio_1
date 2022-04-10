#include <stdio.h>
#include <stdlib.h>

#define BTC 4606954.55
#define PAGOTD 0.90  // proporcion precio con descueto e intereses
#define PAGOTC 1.25  // proporcion precio con descueto e intereses


    setbuf(stdout,NULL);

int mostrarMenu(float x,float y,float z){


    int opcion;

    printf("MENU PRINCIPAL\nIngrese las opciones del men%c:\n\n",163);
    printf("Carga actual kilom%ctros:                             %.2f kms\n",130,x);
    printf("Precio actual por kilom%ctro Aerol%cneas Argentinas:   $  %.2f\n",130,161,y);
    printf("Precio actual por kilom%ctro Latam:                   $  %.2f\n\n\n",130,z);
    printf("1. Ingresar Kil%cmetros \n",130);
    printf("2. Ingresar Precio por Kil%cmetro de Vuelo por empresa\n",130);
    printf("3. Calcular todos los costos\n");
    printf("4. Informe de Resultados\n");
    printf("5. Carga forzada de datos\n");
    printf("6. Salir\n\n\n");
    printf("Elija su opci%cn: ",162);
    scanf("%d",&opcion);

    while(opcion<1 || opcion>6){
        printf("ERROR. La opci%cn no existe. Reintente: ",162);
        fflush(stdin);
        scanf("%d",&opcion);
    }
    printf("Opci%cn elegida %d: \n",162,opcion);
    return opcion;
    }

int pedirKilometros(float km){
    printf("Ingrese los kilom%ctros: ",130);
    scanf("%f",&km);
    while(km<0){
        printf("ERROR: Reingrese los kilom%ctros: ",130);
        scanf("%f",&km);
        fflush(stdin);
        }
    printf("Ahora ingrese al menú anterior para determinar los precios actuales de la oferta disponible.\n\n");

    return km;
    }


float pedirPrecioAr(float ar){
    printf("Ingrese precio por kilom%ctro para Aerol%cneas Argentinas: ",130,161);
    fflush(stdin);
    scanf("%f",&ar);
    while(ar<0){
        printf("ERROR: Ingrese precio por kilom%ctro para Aerol%cneas Argentinas: ",130,161);
        fflush(stdin);
        scanf("%f",&ar);
        }
    return ar;
    }

float pedirPrecioLa(float la){
    printf("Ingrese precio por kilom%ctro para Latam: ",130);
    fflush(stdin);
    scanf("%f",&la);
    while(la<0){
        printf("Ingrese precio por kilom%ctro para Latam: ",130);
        fflush(stdin);
        scanf("%f",&la);
        }
    return la;
    }

int calcularCostos(float km,float ar,float la){

    int opcion;

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
    if(km>0 && ar>0 && la>0){
        printf("\n\n** Los c%clculos se realizaron satisfactoriamente **\n\n",160);
        }
    else{
        printf("\n\n** ERROR: verifique la carga de datos **\n\n");
        }

    return opcion;
}


int mostrarInformes(float x,float y,float z){

    int opcion;

   if(x>0 && y>0 && z>0){
    printf("Precio Total Aerol%cneas Argentinas: $ %.2f\n",161,precioTotalSinDescuentoAr);
    printf("a) Precio Total tarjeta de d%cbito: $ %.2f\n",130,precioTarjetaDebitoAr);
    printf("b) Precio Total tarjeta de cr%cdito: $ %.2f\n",130,precioTarjetaCreditoAr);
    printf("c) Precio Total pagando con bitcoins: BTC %.8f\n\n",precioBitcoinAr);

    printf("Precio Total Latam: $ %f\n",precioTotalSinDescuentoLa);
    printf("a) Precio Total tarjeta de d%cbito: $ %.2f\n",130,precioTarjetaDebitoLa);
    printf("b) Precio Total tarjeta de cr%cdito: $ %.2f\n",130,precioTarjetaCreditoLa);
    printf("c) Precio Total pagando con bitcoins:BTC %.8f\n\n",precioBitcoinLa);

    printf("La diferencia de precio es: $ %.2f\n\n",diferenciaTotal);
        }
    else{
         printf("\n\n** ERROR: verifique la carga de datos **\n\n");
        }
        return opcion;
    }


void cargaForzada(void){

    float km=7090;
    float ar;
    float la;
    float precioTotalSinDescuentoAr=162965;
    float precioTotalSinDescuentoLa=159339;
    float precioTarjetaDebitoAr;
    float precioTarjetaDebitoLa;
    float precioTarjetaCreditoAr;
    float precioTarjetaCreditoLa;
    float precioBitcoinAr;
    float precioBitcoinLa;
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
    printf("c) Precio Total pagando con bitcoins: BTC %.8f\n\n",precioBitcoinAr);

    printf("Precio Total Latam: $ %f\n",precioTotalSinDescuentoLa);
    printf("a) Precio Total tarjeta de d%cbito: $ %.2f\n",130,precioTarjetaDebitoLa);
    printf("b) Precio Total tarjeta de cr%cdito: $ %.2f\n",130,precioTarjetaCreditoLa);
    printf("c) Precio Total pagando con bitcoins:BTC %.8f\n\n",precioBitcoinLa);

    printf("La diferencia de precio es: $ %.2f\n\n",diferenciaTotal);
    }

