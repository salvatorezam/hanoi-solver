#include <stdio.h> //programma che calcola i passaggi per la risoluzione della torre di hanoi secondo il metodo binario
#include <math.h>
#include <time.h>

void binaryMoves(unsigned int n);
void printHeading(void);

int main(void)
{
	printHeading(); 

	unsigned int dischi;
	printf("Inserisci il numero di dischi: ");
	scanf("%u", &dischi);

	puts("");

	clock_t begin = clock();

	binaryMoves(dischi);

	clock_t end = clock();
	double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

	puts("");

	printf("Time spent: %f\n\n", time_spent);

	return 0;
}

void binaryMoves(unsigned int n)
{	
	unsigned int check;

	for (unsigned int i = 1; i <= (unsigned int) pow(2, n) - 1; i++) {

		unsigned int shift = 0;
		unsigned int count = 0;

		check = 0;

		while (check == 0) {

			check = i & (1 << shift);

			shift++;
			count++;
		}

		printf("%u. Muovi il disco %u\n", i, count);
	}
}

void printHeading(void) 
{
	puts("");
	puts("--------------------------------------------- TORRE DI HANOI ---------------------------------------------");
	puts("");
	puts("                                            Risoluzione binaria ");
	puts("");
	puts("Ogni mossa dovrà essere effettuata nel più vicino piolo a destra, qualora non ce ne fossero disponibili allora la mossa va eseguita sempre verso destra, ma partendo dall'estrema sinistra.");
	puts("");
}