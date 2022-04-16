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

    setbuf(stdout,0);

    printf("Bienvenido al sistema de carga de datos\n\n");

    opcionMenu0=MostrarMenu(x,y,z);

    while(opcionMenu0!=6){
        switch(opcionMenu0){
            case 1:
            	x=PedirKilometros(x);
            	system("cls");
                opcionMenu0=MostrarMenu(x,y,z);
            break;
            case 2:
            	y=PedirPrecioAr(y);
                z=PedirPrecioLa(z);
                system("cls");
                opcionMenu0=MostrarMenu(x,y,z);
            break;
            case 3:
            	opcionMenu0=CalcularCostos(x,y,z);
            	system("cls");
                opcionMenu0=MostrarMenu(x,y,z);
            break;
            case 4:
                opcionMenu0=MostrarInformes(x,y,z);
                system("cls");
                opcionMenu0=MostrarMenu(x,y,z);
            break;
            case 5:
            	opcionMenu0=CargaForzada();
            	system("cls");
                opcionMenu0=MostrarMenu(x,y,z);
            break;
            default:

            break;
        }
    }


    return 0;
}
