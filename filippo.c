#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 30
int controlla_anagramma(char* a, char* b){

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

int add_char(char* parola1, char* parola2){

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

int check(char *vet, int len){

	int check=1;
	int i;

	for(i=1; i<len & check==1; i++){

		check = addchar(vet[i], vet[i+1])+addchar(vet[i+1], vet[i])+anagramma(vet[i], vet[i+1])+cambiachar(vet[i], vet[i+1]);

	}

	
	if(i==len-1)
		return 1;
	else
		return 0;
}

void tutto_maiuscolo(char* str){

	int i;
	int len;

	len = strlen(str);

	for(i=0;i<len;i++){

		if(str[i]>=97 || str[i]<=122)
			str[i] -= 20;
	}
}


int main(){

    char parola1[MAX_STRING], parola2[MAX_STRING];

    scanf("%s", parola1);
    scanf("%s", parola2);

    printf("%d", add_char(parola1, parola2));



	return 0;

}

