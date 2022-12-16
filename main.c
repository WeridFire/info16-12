#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "giacomo.h"

#define MAX_FILE 50
#define MAX_STRING 30

int menu(){

	int scelta;

	printf("[1] visualizza insieme di parole\n");
	printf("[2] verifica soluzione\n");
	printf("[3] Acquisisci nuova sequenza\n"); //inizia nuova partita.

	do{
		
		scanf("%d", &scelta);
	}while(scelta<0 || scelta>3);


	return scelta;
}
/*
int cambiachar(char *vet, int len){

	int i,j;

	if(strlen(vet[i])==strlen(vet[i+1])){

		for(i=0; i<strlen(vet[i]); i++)

	}

	else return 0;

}
*/
int conta_elementi(char* nome_file){

	int elements = 0;
	char stringa[MAX_STRING];
	FILE *file;
	file = fopen(nome_file, "r");

	
	if(file){	
		while(!feof(file)){

			elements =  elements + fscanf(file, "%s ", stringa);	
			
		}
		fclose(file);


	}else{

		printf("\nerrore apertura file");
	}

	return elements;
}

char *inizia_partita(char *vett){

}


int main(){

	int scelta;
	char **vett;
	int dimensione; //numero di parole della partita
	char nome_file[MAX_STRING];

	scelta=menu();

	if(scelta==1){

		
	}

	if(scelta==2){

		

	}

	if(scelta==3){

		strcpy(nome_file, chiedi_nome());
		dimensione = conta_elementi(nome_file);
		vett = alloca_vett(dimensione);
		inserisci_parole(dimensione, vett, nome_file);
		visualizza_partita(dimensione, vett);
	}

	


	return 0;
}


