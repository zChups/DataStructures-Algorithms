#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	char nome[21];	//con terminatore
}Studente;

static bool Verifica(Studente* vcurr, int vcurr_size, Studente* tocheck) {
	for (int i = 0; i < vcurr_size; i++) {
		bool a = vcurr[i].nome[0] == tocheck->nome[0];	//stessa iniziale
		bool b = (vcurr[i].nome[0] == tocheck->nome[0] + 1) || (vcurr[i].nome[0] == tocheck->nome[0]-1);//iniziali consecutive
		if (a || b)return false;
	}
	return true;
}

void GruppiRec(Studente* stud, int k, Studente* vcurr, int i, int n, int* nsol) {
	if (i == n) {
		printf("%s", vcurr[0].nome);
		for (int j = 1; j < n; j++) {
			printf(", %s", vcurr[j].nome);
		}
		puts(" }");
		(*nsol)++;
		return;
	}

	for (int j = 0; j < k; j++) {
		if (Verifica(vcurr, i, stud + j)) {
			strcpy(vcurr[i].nome, stud[j].nome);
			GruppiRec(stud, k, vcurr, i + 1, n, nsol);
		}
	}
}

int Gruppi(const char* filename, int n) {	//n -> numero di studenti
	FILE* fp = fopen(filename, "r");
	if (!fp) return 0;
	Studente* stud = NULL;
	int k = 0;	//dimensione del vettore studenti
	while (1) {	//lettura da file
		stud = realloc(stud, sizeof(Studente) * (k + 1));
		
		if (fscanf(fp, "%20s", stud[k].nome) != 1) {
			stud = realloc(stud, sizeof(Studente) * k);
			break;
		}
		k++;
	}
	fclose(fp);

	if (n < 1 || n > k) {
		free(stud);
		return 0;
	}

	Studente* vcurr = malloc(sizeof(Studente) * n);
	int nsol = 0;

	GruppiRec(stud, k, vcurr, 0, n, &nsol);

	free(stud);
	free(vcurr);
	return nsol;
}