#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 30


int controlla_anagramma(char* a, char* b, int len){

	int i,j;
	char parola1[MAX_STRING], parola2[MAX_STRING];

	strcpy(parola1, a);
	strcpy(parola2, b);

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

int main(){

    char parola1[MAX_STRING], parola2[MAX_STRING];

    scanf("%s", parola1);
    scanf("%s", parola2);

    printf("%d", controlla_anagramma(parola1, parola2, MAX_STRING));



	return 0;

}