#ifndef giacomo

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 30


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
	if(vett){
		printf("Allocato un vettore di %d elementi\n", dimensione);
	}

	return vett;
}


 void inserisci_parole(int dimensione, char **vett, char *nome_file){

		FILE *file;
		file = fopen(nome_file, "r");
		printf("Ho aperto il file %s\n", nome_file);
		int i = 0;
		char temporaneo[MAX];

		while(!feof(file) && i < dimensione){
			fscanf(file, "%s ", temporaneo);
			strcpy(*(vett+i), temporaneo);
			i = i + 1;
		}


		fclose(file);
}

void visualizza_partita(int dimensione, char **vett){
	int i;

	printf("Visualizzazione partita:\n")
	for (i = 0; i < dimensione; i++){
		printf("%s ", *(vett+i));
	}
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