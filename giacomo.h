#ifndef giacomo

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 31




void tutto_maiuscolo(char* str){

	int i;
	int len;

	len = strlen(str);

	for(i=0;i<len;i++){

		if(str[i]>=97 && str[i]<=122)
			str[i] -= 32;
	}
}

char *chiedi_nome(){
	char *nome_file;
	nome_file = malloc(sizeof(char)*50); 

	printf("Inserisci il nome della partita da inserire.\nMiraccomando, con la formattazione giusta: 'nomefile.txt'.\n");

	scanf("%s", nome_file);
	return nome_file;

}


char** alloca_vett(int dimensione){
	char **vett;
	int i;

	//dimensione = numero di parole del gioco
	vett = malloc(sizeof(char*)*dimensione);
	for (i = 0; i < dimensione; i++){
		*(vett + i )= malloc(sizeof(char)*MAX);
	}
	

	return vett;
}


 char ** inserisci_parole(int dimensione, char **vett, char *nome_file){

		FILE *file;
		file = fopen(nome_file, "r");
		int i = 0;
		char temporaneo[MAX];

		while(!feof(file) && i < dimensione){
			fscanf(file, "%s ", temporaneo);

			tutto_maiuscolo(temporaneo);


			strcpy(*(vett+i), temporaneo);
			i = i + 1;
		}


		fclose(file);
		return vett;
}

void visualizza_partita(int dimensione, char **vett){
	int i;

	printf("\nVISUALIZZAZIONE PARTITA:\n");
	for (i = 0; i < dimensione; i++){
		printf("%s ", *(vett+i));
	}

	printf("\n");
}

/*
int main(){
	char *vett;
	int dimensione = 30;
	char nome_file[50];
	strcpy(nome_file, chiedi_nome());

	alloca_vett(dimensione, vett);
	inserisci_parole(30, vett, nome_file);
}

*/



#endif