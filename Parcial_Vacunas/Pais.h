#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

#include "LinkedList.h"

typedef struct{
    int id;
    char nombre[128];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
}ePais;

ePais* pais_new();
ePais* pais_newParams(char* idStr, char* nombreStr, char* vac1dosis, char* vac2dosis, char* sinVacunar);
void pais_delete(ePais* this);
int pais_setId(ePais* this,int id);
int pais_getId(ePais* this,int* id);
int pais_setNombre(ePais* this,char* nombre);
int pais_getNombre(ePais* this,char* nombre);
int pais_setVac1dosis(ePais* this,int vac1dosis);
int pais_getVac1dosis(ePais* this,int* vac1dosis);
int pais_setVac2dosis(ePais* this,int vac2dosis);
int pais_getVac2dosis(ePais* this,int* vac2dosis);
int pais_setSinVacunar(ePais* this,int sinVacunar);
int pais_getSinVacunar(ePais* this,int* sinVacunar);
int pais_printPais(ePais* pPais);
int generateRandomVac1dosis(void);
int generateRandomVac2dosis(void);
int generateRandomSinVacunar(void);
void loadVac1dosis(void* pElement);
void loadVac2dosis(void* pElement);
void loadSinVacunar(void* pElement);
int filterExitosos(void* pElement);
int filterHorno(void* pElement);
int cmpVac1dosis(void* pais1, void* pais2);
int pais_findMasCastigado();
#endif // PAIS_H_INCLUDED
