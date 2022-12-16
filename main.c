#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "giacomo.h"

#define MAX_FILE 50
#define MAX_STRING 30


int anagramma(char* a, char* b){

	int i,j,len;
	char parola1[MAX_STRING], parola2[MAX_STRING];

	strcpy(parola1, a);
	strcpy(parola2, b);

	len = strlen(a);

	if(strlen(a) != strlen(b))
		return 0;

	for(i=0; i<len; i++){

		for(j=0; j<len; j++){

			if(parola1[i] == parola2[j]){

				parola2[j] = '0';
			}

		}
	}

	for(i=0;i<len;i++){

		if(parola2[i]!='0')
			return 0;
	}

	return 1;
}

int addchar(char* parola1, char* parola2){

	//nota che parola1 è piu lungo di parola2

	int len,flag=0,i,j=0;

	len=strlen(parola1);

	if(strlen(parola2) != len-1)
		return 0;

	for(i=0;i<len-1; i++){

		if(parola1[j] != parola2[i]){

			flag++;
			j++;
		}

		j++;

		if(flag==2)
			return 0;
	}

	return 1;
}

int cambiachar(char *a, char *b){

	int j;
	int flag = 0;

	if(strlen(a)==strlen(b)){

		
		for(j=0; j<strlen(a); j++){

			if(a[j]!=b[j])
				flag++;
		}

		if(flag==1)
			return 1;
		else
			return 0;

	}

	else return 0;

}

int check(char **vet, int len){

	int check=1;
	int i;

	for(i=0; i<len-1 & check==1; i++){

		check = addchar(vet[i], vet[i+1])+addchar(vet[i+1], vet[i])+anagramma(vet[i], vet[i+1])+cambiachar(vet[i], vet[i+1]);

	}

	
	if(i==len-1)
		return 1;
	else
		return 0;
}


int menu(){

	int scelta;

	printf("[1] Inizia partita\n");
	printf("[2] Inserisci e verifica soluzione\n");
	printf("[3] Visualizza le parole\n"); //inizia nuova partita.
	printf("\n[0] Esci\n");

	do{
		
		scanf("%d", &scelta);
	}while(scelta<0 || scelta>3);


	return scelta;
}

int controlla_diverse(char** vet, int len){

	int i,j;

	for(i=0;i<len;i++){

		for(j=0;j<len;j++){

			if(j != i && strcmp(*(vet+i), *(vet+j)) == 0)
				return 0;
		}
	}

	return 1;

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



int main(){

	int scelta;
	char **vett;
	int check_var; //1 se è la partita valida
	int dimensione; //numero di parole della partita
	int dimensione_soluzione;
	char nome_file[MAX_STRING];
	char nome_soluzione[MAX_STRING];


		while (scelta != 0){ 
		scelta=menu();


		if(scelta==1){

			strcpy(nome_file, chiedi_nome());
			dimensione = conta_elementi(nome_file);
			if (dimensione >= 4){

				vett = alloca_vett(dimensione);



				vett = inserisci_parole(dimensione, vett, nome_file);

				if (controlla_diverse(vett, dimensione) == 0){
					printf("Inserire una partita con tutte le parole diverse\n");
				}
				

			}
			else{
				printf("Rinserire la partita con almeno quattro parole\n");
			}
		}


		if(scelta==2){


			strcpy(nome_soluzione, chiedi_nome());
			dimensione_soluzione = conta_elementi(nome_soluzione);
			vett = alloca_vett(dimensione_soluzione);
			vett = inserisci_parole(dimensione_soluzione, vett, nome_soluzione);

			if (controlla_diverse(vett, dimensione) == 0){
					printf("Inserire una partita con tutte le parole diverse\n");
				}

			check_var = check(vett, dimensione_soluzione);
			if(check_var){
				printf("\n\nComplimenti campioncino, soluzione giusta\n\n");
				printf("\nA presto!!!\n");
				scelta = 0;
			}
			else{
				printf("\n\nStronzo riprova\n\n");
			}

		}


		if(scelta==3){
			visualizza_partita(dimensione, vett);
			//visualizza la partita in corso (il vettore)
			
		}	



		

	}
	return 0;
}


