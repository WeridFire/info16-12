#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 30


char* alloca_vett(int dimensione, char *vett){

	//dimensione = numero di parole del gioco
	vett = malloc(sizeof(char)*MAX*dimensione);
	if(vett){
		printf("Allocazione andata a buon fine\n");
	}

	return vett;
}



char *inserisci_parole(int dimensione, char *vett, char nome_file){

		FILE *file;
		file = fopen(nome_file, "r");
		printf("Ho aperto il file %s\n", nome_file);
		int i = 0;
		char temporaneo[MAX];

		for(i = 0; i <dimensione; i++){
			fscanf(file, "%s", temporaneo);
			strcpy(vett+i, temporaneo);
		}


		fclose(file);
		return vett;
}

void visualizza_partita(int dimensione, char *vett){
	int i;
	for (i = 0; i < dimensione; i++){
		printf("%s ", vett+i);
	}
}

char *chiedi_nome(){
	char nome_file;
	
	printf("Inserisci il nome della partita da inserire.\nMiraccomando, con la formattazione giusta: 'nomefile.txt'.\n");

	scanf("%s", nome_file);
	return nome_file;

}


int main(){
	char *vett;
	int dimensione = 30;
	char nome_file[50];
	strcpy(nome_file, chiedi_nome());

	alloca_vett(dimensione, vett);
	inserisci_parole(30, vett, nome_file);
}