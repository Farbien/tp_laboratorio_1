/******************************************************************************

                UNIVERSIDAD TECNOLOGICA NACIONAL
                Facultad Regional de Avellaneda
                Tecnicatura Superior en Programación

        Asignatura: Programación I – Laboratorio I.
        Alumno:  Chirdo, Nicolas Andres
        Division: 1 F
                ---- Primer cuatrimestre 2022 ----

        Fecha de entrega 16/04/2022

*******************************************************************************/
#include <stdio.h>
#include "funciones.h"


int main()
{
    int opcionMenu0;
    float x;  // kilometros
    float y;  // precio km Aerolineas
    float z;  // precio km latam

    x=0;
    y=0;
    z=0;

    printf("Bienvenido al sistema de carga de datos\n\n");

    opcionMenu0=mostrarMenu(x,y,z);

    while(opcionMenu0!=6){
        switch(opcionMenu0){
            case 1:
                x=pedirKilometros(x);

                opcionMenu0=mostrarMenu(x,y,z);
            break;
            case 2:
                y=pedirPrecioAr(y);
                z=pedirPrecioLa(z);

                opcionMenu0=mostrarMenu(x,y,z);
            break;
            case 3:
                opcionMenu0=calcularCostos(x,y,z);

                opcionMenu0=mostrarMenu(x,y,z);
            break;
            case 4:
                opcionMenu0=mostrarInformes(x,y,z);
                opcionMenu0=mostrarMenu(x,y,z);
            break;
            case 5:
                opcionMenu0=cargaForzada();
                opcionMenu0=mostrarMenu(x,y,z);
            break;
            default:
                 opcionMenu0=mostrarMenu(x,y,z);
            break;
        }
    }


    return 0;
}
