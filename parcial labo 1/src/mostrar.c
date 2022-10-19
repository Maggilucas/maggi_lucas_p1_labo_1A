#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estructura.h"
#include "mostrar.h"
#include "validaciones.h"
#include "hardcodeo.h"
#include "altatrabajo.h"
int mostrarServicio(eServicio servicio)
{

    int todoOk = 0;

    printf("%2d    %2s   %2f\n",
    servicio.id,
	servicio.descripcion,
	servicio.precio);

    return todoOk;
}

int mostrarServicios(eServicio vec[], int tam)
{

    int todoOk = 0;
    int flag = 1;

    if(vec != NULL && tam > 0)
    {

        printf("**** Lista de servicios ****\n");
        printf("id   descripcion     precio      \n");
        for(int i = 0 ; i < tam ; i++)
        {
                mostrarServicio(vec[i]);
                flag = 0;
        }
        printf("\n\n");

        if(flag)
        {

            printf("No hay servicios en el sistema.\n\n");
        }


        todoOk = 1;
    }

    return todoOk;
}



int mostrarMarcas(eMarca vec[], int tam)
{

    int todoOk = 0;
    int flag = 1;

    if(vec != NULL && tam > 0)
    {

        printf("**** Lista de marcas ****\n");
        printf("id   Nombre   \n");
        for(int i = 0 ; i < tam ; i++)
        {
                mostrarMarca(vec[i]);
                flag = 0;
        }
        printf("\n\n");

        if(flag)
        {

            printf("No hay marcas en el sistema.\n\n");
        }


        todoOk = 1;
    }

    return todoOk;
}

int mostrarColores(eColor vec[], int tam)
{

    int todoOk = 0;
    int flag = 1;

    if(vec != NULL && tam > 0)
    {

        printf("**** Lista de colores ****\n");
        printf("id   Nombre   \n");
        for(int i = 0 ; i < tam ; i++)
        {
                mostrarColor(vec[i]);
                flag = 0;
        }
        printf("\n\n");

        if(flag)
        {

            printf("No hay colores en el sistema.\n\n");
        }


        todoOk = 1;
    }

    return todoOk;
}
int mostrarMarca(eMarca marca)
{

    int todoOk = 0;

    printf("%2d    %2s   \n",
    marca.id,
	marca.descripcion);

    return todoOk;
}

int mostrarColor(eColor color)
{

    int todoOk = 0;

    printf("%2d    %2s   \n",
    color.id,
	color.descripcion);

    return todoOk;
}



int mostrarMenu()
{

    int opcion;

    system("cls");

    printf("*** ABM autos ***\n\n");
    printf("1- Alta ato\n");
    printf("2- Modificar auto\n");
    printf("3- Baja auto\n");
    printf("4- listar autos\n");
    printf("5- listar marcas.\n");
    printf("6- listar colores.\n");
    printf("7- listar servicios.\n");
    printf("8- alta trabajo.\n");
    printf("9- listar trabajos.\n");
    printf("10- salir.\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);



    return opcion;
}

int mostrarAuto(eAuto autos,eMarca marcas[],eColor colores[],int tam_m,int tam_c)
{

    int todoOk = 0;
    char auxMarca[20];
    char auxColor[20];


	cargarDescripcionMarcas(autos.idMarca, auxMarca, marcas, tam_m);
	cargarDescripcionColores(autos.idColor, auxColor, colores, tam_c);

    printf("%2d    %9s    %2s      %2c   \n",
    		autos.id,
			auxMarca,
			auxColor,
			autos.caja);

    return todoOk;
}

int mostrarAutos(eAuto vec[], int tam, int limpiar,eMarca marcas[],eColor colores[],int tam_m,int tam_c)
{

    int flag = 0;

    if(vec != NULL && tam > 0 && limpiar >= 0 && limpiar <= 1)
    {


        if(limpiar)
        {

                system("cls");

        }
        printf("**** Lista de autos ****\n");
        printf("id   marca   color   caja  \n");
        for(int i = 0 ; i < tam ; i++)
        {
            if(!vec[i].isEmpty)
            {
                mostrarAuto(vec[i],marcas,colores,tam_m,tam_c);
                flag = 1;
            }
        }
        printf("\n\n");

        if(flag != 1)
        {

            printf("No hay autos en el sistema.\n\n");
        }
    }



    return flag;
}

int subMenuModificarAutos()
{
	int opcion;
	printf("elija que desea modificar:/n");
	printf("1-marca /n");
	printf("2-color /n");
	scanf("%d",&opcion);

	return opcion;
}
