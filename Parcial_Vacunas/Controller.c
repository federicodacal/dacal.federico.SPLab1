#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn_validaciones.h"
#include "parser.h"
#include "Pais.h"

/** \brief Carga los datos de los paises desde un archivo .csv (modo texto).
 *
 * \param pArrayList LinkedList* lista
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int controller_loadFromText(LinkedList* pArrayList)
{
    int response=-1;
    char pathIngresado[128];
    FILE* f=NULL;

    if(pArrayList!=NULL){
        if(!utn_getDescripcion(pathIngresado, 128,"Ingrese el path del archivo .csv que desea cargar: \nSi no recuerda el path puede ingresar el archivo predeterminado vacunas.csv\n","\nError. Dato ingresado no valido. Reingrese dato \n",5)){
            f=fopen(pathIngresado,"r");
            if(f==NULL){
                printf("No se encontro el archivo %s\n\n",pathIngresado);
            }
            else{
                if(!parser_FromText(f,pArrayList)){
                    response=0;
                }
            }
        }
    }

    fclose(f);
    return response;
}


/** \brief Muestra la lista de paises
 *
 * \param pArrayList LinkedList* lista
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int controller_List(LinkedList* pArrayList)
{
    int response=-1;

    ePais* auxPais=NULL;
    int flag=0;
    int len;

    if(pArrayList!=NULL){
    	printf("ID - Pais - 1 Dosis - 2 Dosis - Sin Vacunar\n---------------------------------------------------------\n");
    	len=ll_len(pArrayList);
    	for(int i=0;i<len;i++){
    		auxPais=(ePais*)ll_get(pArrayList,i);
    		if(auxPais!=NULL){
    			pais_printPais(auxPais);
    			flag=1;
    		}
    	}
        printf("\n");
    	if(flag==0){
    		printf("No hay paises para mostrar\n");
    	}
    	response=0;
    }

    return response;
}

/** \brief Permite guardar un archivo en modo texto
 *
 * \param pArrayList LinkedList* lista
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int controller_saveAsText(LinkedList* pArrayList)
{
    int response=-1;
    char pathIngresado[128];
    int auxId;
    char auxNombre[128];
    int auxVac1dosis;
    int auxVac2dosis;
    int auxSinVacunar;
    int confirma=1;
    int len=ll_len(pArrayList);
    ePais* auxPais=NULL;
    FILE* f=NULL;

    if(pArrayList!=NULL){
        if(!utn_getDescripcion(pathIngresado, 128,"Ingrese el path del archivo de extension .csv que desea guardar: ","\nError. Dato ingresado no valido. Reingrese dato \n",5)){
            f=fopen(pathIngresado,"r");
            if(f!=NULL){
                printf("Cuidado el archivo %s existe y se va a sobrescribir\n",pathIngresado);
                utn_getNumero(&confirma,"[1] Confirmar [2] Cancelar\n","\nError dato no valido\n",1,2,3);
            }
            fclose(f);
            if(confirma==2){
                printf("Save as text cancelado\n");
                response=1;
            }
            else if(confirma){
                f=fopen(pathIngresado,"w");
                if(f==NULL){
                    printf("No se pudo abrir el archivo\n");
                }
                else{
                    for(int i=0;i<len;i++){
                        auxPais=(ePais*)ll_get(pArrayList,i);
                        if(auxPais!=NULL){
                            if(!pais_getId(auxPais,&auxId) &&
                               !pais_getNombre(auxPais,auxNombre) &&
                               !pais_getVac1dosis(auxPais,&auxVac1dosis) &&
                               !pais_getVac2dosis(auxPais,&auxVac2dosis) &&
                               !pais_getSinVacunar(auxPais,&auxSinVacunar)){
                                    fprintf(f,"%d,%s,%d,%d,%d\n",auxId,auxNombre,auxVac1dosis,auxVac2dosis,auxSinVacunar);
                                    response=0;
                            }
                        }
                    }
                }
            }
        }
        fclose(f);
    }
    return response;
}
