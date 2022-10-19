/*
 ============================================================================
 Name        : parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estructura.h"
#include "mostrar.h"
#include "validaciones.h"
#include "hardcodeo.h"
#include "altatrabajo.h"
#define TAM 50
#define TAM_T 50
#define TAM_M 5
#define TAM_C 5
#define TAM_S 4
#define LIMPIAR 1
#define NOLIMPIAR 0

int main()
{
	setbuf(stdout,NULL);

    int id = 1;
    int idTrabajos=6000;
    int idMarca;
    int idColor;
    int idServicio;
    int contadorAutos=0;
    eAuto lista[TAM];
    eMarca marcas[TAM_M];
    eColor colores[TAM_C];
    eServicio servicios[TAM_S];
    eTrabajo trabajos[TAM_T];
    eFecha fecha;


    char seguir = 's';

    inicializarAuto(lista,TAM);

    hardcodearMarcas(&idMarca,marcas,TAM,TAM_M);
    hardcodearColores(&idColor,colores,TAM,TAM_C);
    hardcodearServicios(&idServicio,servicios,TAM,TAM_S);

    do
    {
        switch(mostrarMenu())
        {

        case 1:

            if(altaAuto(&id, lista, TAM,marcas,TAM_M,colores,TAM_C))
            {
                printf("auto agregado con exito.\n");
                contadorAutos++;
            }
            else
            {
                printf("Ocurrio un problema durante el alta.\n");
            }

            system("pause");
            break;

        case 2:
            if(contadorAutos > 0)
            {
				modificarAuto(lista, TAM,colores,TAM_C,marcas,TAM_M);
				printf("modificacion exitosa.\n");
			}
			else
			{
				printf("Ocurrio un problema durante la modificacion o no hay autos que modificar.\n");
			}
            system("pause");
            break;

        case 3:

            if(bajaAuto(lista, TAM,marcas,colores,TAM_M,TAM_C))
            {
            	 printf("auto eliminado con exito.\n");
            	 contadorAutos--;
            }
            else
            {
            	 printf("Ocurrio un problema durante la baja.\n");
            }
            system("pause");
            break;

        case 4:

        	ordenarAutos(lista,TAM,marcas,TAM_M);
        	mostrarAutos(lista,TAM,1,marcas,colores,TAM_M,TAM_C);


            system("pause");

            break;

        case 5:
        	mostrarMarcas(marcas,TAM_M);
        system("pause");
        break;
        case 6:
        	mostrarColores(colores,TAM_C);
        system("pause");
	   break;
        case 7:
        	mostrarServicios(servicios,TAM_S);
        system("pause");
	   break;
        case 8:
        if(altaTrabajo(&idTrabajos, lista, TAM,trabajos,TAM_T,servicios,TAM_S,fecha,colores,TAM_C,marcas,TAM_M))
		{
			printf("TRABAJO agregado con exito.\n");
		}
		else
		{
			printf("Ocurrio un problema durante el alta.\n");
		}
         system("pause");
	   break;
        case 9:

        	mostrarTrabajos(trabajos,TAM_T,1);
         system("pause");
	   break;
        case 10:

        confirmarSalida(&seguir, 'n', 's');

        break;

        default:

            printf("Opcion invalida\n");
            system("pause");

        }




    }
    while(seguir == 's');



    return 0;
}
