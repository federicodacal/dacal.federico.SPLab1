#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pais.h"
#include "LinkedList.h"
#include "utn_validaciones.h"

/** \brief Constructor de Pais
 *
 * \return ePais*
 *
 */
ePais* pais_new()
{
    ePais* newPais=(ePais*)malloc(sizeof(ePais));

    if(newPais!=NULL){
        newPais->id=0;
        strcpy(newPais->nombre," ");
        newPais->vac1dosis=0;
        newPais->vac2dosis=0;
        newPais->sinVacunar=0;
    }
    return newPais;
}

/** \brief Constructor de Pais con parametros
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param vac1dosis char*
 * \param vac2dosis char*
 * \param sinVacunar char*
 * \return ePais*
 *
 */
ePais* pais_newParams(char* idStr, char* nombreStr, char* vac1dosis, char* vac2dosis, char* sinVacunar)
{
    ePais* newPais=(ePais*)malloc(sizeof(ePais));

    if(newPais!=NULL){
        if(!(!pais_setId(newPais,atoi(idStr)) &&
             !pais_setNombre(newPais,nombreStr) &&
             !pais_setVac1dosis(newPais,atoi(vac1dosis)) &&
             !pais_setVac2dosis(newPais,atoi(vac2dosis)) &&
             !pais_setSinVacunar(newPais,atoi(sinVacunar)))){
                pais_delete(newPais);
                newPais=NULL;
        }
    }
    return newPais;
}

void pais_delete(ePais* this)
{
    if(this!=NULL){
        free(this);
    }
}

int pais_setId(ePais* this,int id)
{
    int response=-1;
    if(this!=NULL && id>=0){
        this->id=id;
        response=0;
    }
    return response;
}

int pais_getId(ePais* this,int* id)
{
    int response=-1;

    if(this!=NULL && id!=NULL){
        *id=this->id;
        response=0;
    }
    return response;
}

int pais_setNombre(ePais* this,char* nombre)
{
    int response=-1;

    if(this!=NULL && nombre!=NULL){
        if(esNombre(nombre,128)){
            strncpy(this->nombre,nombre,128);
            response=0;
        }
    }
    return response;
}

int pais_getNombre(ePais* this,char* nombre)
{
    int response=-1;

    if(this!=NULL && nombre!=NULL){
        strncpy(nombre,this->nombre,128);
        response=0;
    }
    return response;
}

int pais_setVac1dosis(ePais* this,int vac1dosis)
{
    int response=-1;
    if(this!=NULL && vac1dosis>=0){
        this->vac1dosis=vac1dosis;
        response=0;
    }
    return response;
}

int pais_getVac1dosis(ePais* this,int* vac1dosis)
{
    int response=-1;

    if(this!=NULL && vac1dosis!=NULL){
        *vac1dosis=this->vac1dosis;
        response=0;
    }
    return response;
}

int pais_setVac2dosis(ePais* this,int vac2dosis)
{
    int response=-1;
    if(this!=NULL && vac2dosis>=0){
        this->vac2dosis=vac2dosis;
        response=0;
    }
    return response;
}

int pais_getVac2dosis(ePais* this,int* vac2dosis)
{
    int response=-1;

    if(this!=NULL && vac2dosis!=NULL){
        *vac2dosis=this->vac2dosis;
        response=0;
    }
    return response;
}

int pais_setSinVacunar(ePais* this,int sinVacunar)
{
    int response=-1;
    if(this!=NULL && sinVacunar>=0){
        this->sinVacunar=sinVacunar;
        response=0;
    }
    return response;
}

int pais_getSinVacunar(ePais* this,int* sinVacunar)
{
    int response=-1;

    if(this!=NULL && sinVacunar!=NULL){
        *sinVacunar=this->sinVacunar;
        response=0;
    }
    return response;
}

/** \brief Imprime un pais
 *
 * \param pPais ePais*
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int pais_printPais(ePais* pPais)
{
    int response=-1;

    int id;
    char nombre[128];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;

    if(pPais!=NULL &&
       !pais_getId(pPais, &id) &&
       !pais_getNombre(pPais, nombre) &&
       !pais_getVac1dosis(pPais, &vac1dosis)&&
       !pais_getVac2dosis(pPais, &vac2dosis) &&
       !pais_getSinVacunar(pPais, &sinVacunar)){
            printf("%d %10s %d %d %d\n",id,nombre,vac1dosis,vac2dosis,sinVacunar);
             response=0;
    }
    return response;
}

/** \brief Gnera un numero aleatorio entre 1 y 60
 *
 * \param void
 * \return int numero generado
 *
 */
int generateRandomVac1dosis(void)
{
    int random;
    random=rand()%(60-1+1)+1;
    return random;
}

/** \brief Genera un numero aleatorio entre 1 y 40
 *
 * \param void
 * \return int numero generado
 *
 */
int generateRandomVac2dosis(void)
{
    int random;
    random=rand()%(40-1+1)+1;

    return random;
}

/** \brief Cargar un valor random para vac1dosis
 *
 * \param pElement void*
 * \return void
 *
 */
void loadVac1dosis(void* pElement)
{
    int random=generateRandomVac1dosis();
    ePais* auxPais;

    if(pElement!=NULL)
    {
        auxPais=(ePais*)pElement;
        auxPais->vac1dosis=random;
        pElement=auxPais;
    }
}

/** \brief Cargar un valor random para vac2dosis
 *
 * \param pElement void*
 * \return void
 *
 */
void loadVac2dosis(void* pElement)
{
    int random=generateRandomVac2dosis();
    ePais* auxPais;

    if(pElement!=NULL)
    {
        auxPais=(ePais*)pElement;
        auxPais->vac2dosis=random;
        pElement=auxPais;
    }
}

/** \brief Asigna el valor a SinVacunar teniendo en cuenta el valor de vac1dosis y vac2dosis
 *
 * \param pElement void*
 * \return void
 *
 */
void loadSinVacunar(void* pElement)
{
    int cantidadSinVacunar;
    int cantidadVacunados;
    ePais* auxPais;

    cantidadVacunados=auxPais->vac1dosis+auxPais->vac2dosis;
    cantidadSinVacunar=100-cantidadVacunados;

    if(pElement!=NULL)
    {
        auxPais=(ePais*)pElement;
        auxPais->sinVacunar=cantidadSinVacunar;
        pElement=auxPais;
    }
}

/** \brief Funcion de filtro para vac1dosis mayor a 30%
 *
 * \param pElement void*
 * \return int
 *
 */
int filterExitosos(void* pElement)
{
    return((ePais*)pElement)->vac2dosis>=30;
}

/** \brief Funcion de filtro para sinVacunar mayor a vac1dosis, vac2dosis
 *
 * \param pElement void*
 * \return int
 *
 */
int filterHorno(void* pElement)
{

    return((ePais*)pElement)->sinVacunar>((ePais*)pElement)->vac1dosis+((ePais*)pElement)->vac2dosis;
}

/** \brief Permite comparar de dos elementos su campo vac1dosis
 *
 * \param pais1 void*
 * \param pais2 void*
 * \return int
 *
 */
int cmpVac1dosis(void* pais1, void* pais2)
{
	int response=0;

	ePais* auxPais1=NULL;
	ePais* auxPais2=NULL;

	if(pais1!=NULL && pais2!=NULL){
		auxPais1=(ePais*)pais1;
		auxPais2=(ePais*)pais2;
		if(auxPais1->vac1dosis>auxPais2->vac1dosis){
			response=1;
		}
		if(auxPais1->vac1dosis<auxPais2->vac1dosis){
			response=-1;
		}
	}
	return response;
}

/** \brief Permite comparar de dos elementos su campo sinVacunar
 *
 * \param pais1 void*
 * \param pais2 void*
 * \return int
 *
 */
int cmpSinVacunar(void* pais1, void* pais2)
{
	int response=0;

	ePais* auxPais1=NULL;
	ePais* auxPais2=NULL;

	if(pais1!=NULL && pais2!=NULL){
		auxPais1=(ePais*)pais1;
		auxPais2=(ePais*)pais2;
		if(auxPais1->sinVacunar>auxPais2->sinVacunar){
			response=1;
		}
		if(auxPais1->sinVacunar<auxPais2->sinVacunar){
			response=-1;
		}
	}
	return response;
}


/** \brief Recorre y ordena la lista con ll_sort de menor a mayor e imprime el pais menos vacunado
 *
 * \param this LinkedList* lista
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int pais_findMasCastigado(LinkedList* this)
{
    int response=-1;

    ePais* masCastigado;

    if(this!=NULL){
        ll_sort(this,cmpSinVacunar,0);
        masCastigado=ll_get(this,0);
        if(masCastigado!=NULL){
            pais_printPais(masCastigado);
            response=0;
        }
    }
    return response;
}
