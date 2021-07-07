#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Pais.h"

/** \brief Parsea los datos los datos de los paises desde el archivo .csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int parser_FromText(FILE* pFile, LinkedList* pArrayList)
{
    int response=-1;
    ePais* auxPais=NULL;
    char auxBuffer[5][128];
    int cant;

    if(pFile!=NULL && pArrayList!=NULL){
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxBuffer[0],auxBuffer[1],auxBuffer[2],auxBuffer[3],auxBuffer[4]);
        while(!feof(pFile)){
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%s", auxBuffer[0], auxBuffer[1], auxBuffer[2], auxBuffer[3],auxBuffer[4]);
            if(cant==5){
                auxPais=pais_newParams(auxBuffer[0],auxBuffer[1],auxBuffer[2],auxBuffer[3],auxBuffer[4]);
                if(auxPais!=NULL){
                    ll_add(pArrayList,auxPais);
                    response=0;
                }
            }
        }
    }
    return response;
}
