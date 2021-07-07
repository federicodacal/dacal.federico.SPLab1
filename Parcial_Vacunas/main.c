// Federico Dacal

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Pais.h"
#include "menu.h"
#define DESC 0
#define ASC 1

int main()
{
    srand(time(NULL));
	int option;
	char salir='n';
	int flag=0;
	int flag2=0;

    LinkedList* list=ll_newLinkedList();
    LinkedList* listPaisesExitosos=NULL;
    LinkedList* listPaisesEnElHorno=NULL;

    if(list==NULL){
		printf("Ocurrio un error al intentar crear LinkedList\n");
		system("pause");
		exit(1);
    }
	do{
		option=menu();
		if(option!=-1){
			switch(option)
			{
				case 1:
				    if(flag){
                        printf("Ya hay un archivo cargado\n");
				    }
				    else{
                        if(!controller_loadFromText(list)){
                            printf("Paises fueron cargados con exito\n\n");
                            flag=1;
                        }
                        else{
                            printf("Ocurrio un problema\n");
                        }
				    }
					system("pause");
					break;
				case 2:
                    if(!flag){
                        printf("Aun no hay un archivo cargado\n");
                    }
                    else{
                        if(!controller_List(list)){
                            printf("Lista OK\n");
                        }
                        else{
                            printf("Ocurrio un problema\n");
                        }
                    }
                    system("pause");
					break;
				case 3:
				    if(!flag){
                        printf("Primero debe cargar el archivo\n");
				    }
				    else{
                        list=ll_map(list,loadVac1dosis);
                        list=ll_map(list,loadVac2dosis);
                        list=ll_map(list,loadSinVacunar);
                        if(list!=NULL){
                            printf("Estadisticas fueron asignadas\n");
                            flag2=1;
                        }
                        else{
                            printf("Ocurrio un error\n");
                        }
				    }
                    system("pause");
					break;
				case 4:
				    if(!flag2){
                        printf("Primer debe asignar las estadisticas\n");
				    }
				    else{
                        listPaisesExitosos=ll_filter(list,filterExitosos);
                        if(listPaisesExitosos!=NULL){
                            controller_List(listPaisesExitosos);
                            if(!controller_saveAsText(listPaisesExitosos)){
                                printf("El archivo se guardo correctamente\n");
                            }
                            else{
                                printf("Ocurrio un problema\n");
                            }
                        }
				    }
                    system("pause");
					break;
				case 5:
				    if(!flag2){
                        printf("Primero debe asignar las estadisticas\n");
				    }
				    else{
                        listPaisesEnElHorno=ll_filter(list,filterHorno);
                        if(listPaisesEnElHorno!=NULL){
                            controller_List(listPaisesEnElHorno);
                            if(!controller_saveAsText(listPaisesEnElHorno)){
                                printf("El archivo se guardo correctamente\n");
                            }
                            else{
                                printf("Ocurrio un problema\n");
                            }
                        }
				    }
                    system("pause");
					break;
				case 6:
				    if(!flag2){
                        printf("Primero debe asginar las estadisticas\n");
				    }
				    else{
                        ll_sort(list,cmpVac1dosis,DESC);
                        controller_List(list);
				    }
                    system("pause");
					break;
				case 7:
                    if(!pais_findMasCastigado(list)){
                        printf("Pais mas castigado\n");
                    }
                    system("pause");
					break;
                case 8:
                    printf("Confirmar salida: s/n ");
                    fflush(stdin);
                    salir=getchar();
                    break;
			}
		}
	}while(salir!='s');
    return 0;
}
