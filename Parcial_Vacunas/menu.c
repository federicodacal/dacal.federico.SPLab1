#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn_validaciones.h"

/** \brief Interfaz menu
 *
 * \return int -1 (Error) o Opcion elegida (Exito)
 *
 */
int menu()
{
    int response=-1;;
    int optionAux;

    system("cls");
    printf("\n*****OPCIONES*****\n");
    printf("------------------------------------------\n");
    printf("[1] Cargar archivo .csv\n");
    printf("[2] Imprimir lista\n");
    printf("[3] Asignar estadisticas\n");
    printf("[4] Filtrar por paises exitosos\n");
    printf("[5] Filtrar por paises en el horno\n");
    printf("[6] Ordenar por nivel de vacunacion\n");
    printf("[7] Mostrar mas castigado\n");
    printf("--------------------------------------------------------------\n");
    printf("[8] Salir\n");

    if(utn_getNumero(&optionAux,"\nIngrese opcion:\n","\nDato ingresado no valido.",1,8,5)==0){
        response=optionAux;
    }

    return response;
}
