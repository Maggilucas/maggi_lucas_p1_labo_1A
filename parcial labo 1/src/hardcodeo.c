#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estructura.h"
#include "mostrar.h"
#include "validaciones.h"
#include "hardcodeo.h"
#include "altatrabajo.h"

int hardcodearMarcas(int* pId ,eMarca vec[], int tam, int cant)
{

    int todoOk = 0;

    eMarca marcas[] =
    {
        {1000, "renault"},
        {1001, "ford"},
        {1002, "fiat"},
        {1003, "chevrolet"},
        {1004, "peugeot"}
    };



    if(vec != NULL && tam > 0 && cant <= tam && cant <= 6)
    {

      for(int i = 0 ; i < cant ; i++)
      {

      vec[i] = marcas[i];
      *pId = *pId + 1;
      }
        todoOk = 1;
    }
    return todoOk;
}

int hardcodearColores(int* pId ,eColor vec[], int tam, int cant)
{

    int todoOk = 0;

    eColor colores[] =
    {
        {5000, "negro"},
        {5001, "blanco"},
        {5002, "rojo"},
        {5003, "verde"},
		{5004, "azul"}
    };



    if(vec != NULL && tam > 0 && cant <= tam && cant <= 6)
    {

      for(int i = 0 ; i < cant ; i++)
      {

      vec[i] = colores[i];
      *pId = *pId + 1;
      }
        todoOk = 1;
    }
    return todoOk;
}

int hardcodearServicios(int* pId ,eServicio vec[], int tam, int cant)
{

    int todoOk = 0;

    eServicio servicios[] =
    {
        {20000, "lavado",450},
        {20001, "pulido",500},
        {20002, "encerado",600},
        {20003, "completo",900}
    };



    if(vec != NULL && tam > 0 && cant <= tam && cant <= 6)
    {

      for(int i = 0 ; i < cant ; i++)
      {

      vec[i] = servicios[i];
      *pId = *pId + 1;
      }
        todoOk = 1;
    }
    return todoOk;
}
