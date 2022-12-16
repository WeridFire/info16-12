#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu(){

	int scelta;

	printf("[1] visualizza insieme di parole");
	printf("[2] verifica soluzione");
	printf("[3] acquisisci nuova sequenza");

	do{
		printf("Digitare modalità, da 1 a 3");
		scanf("%d", &scelta);
	}while(scelta<0 || scelta>3);


	return scelta;
}

int cambiachar(char *vet, int len){

	int i,j;

	if(strlen(vet[i])==strlen(vet[i+1])){

		for(i=0; i<strlen(vet[i]); i++)

	}

	else return 0;

}

int main(){

	int scelta;

	scelta=menu();

	if(scelta==1){



	}

	if(scelta==2){

		

	}

	if(scelta==3){

		

	}

	


	return 0;
}


