#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#include <stdio.h>

#include <math.h>

static void ValidTimesRec(uint8_t n, int* vcurr, bool* vtaken, int i) {
	if (i > 11)return;
	if (n == 0) {
		//calcolo le ore e minuti
		int hours = 0;
		int mins = 0;
		for (int j = 0; j < 11; j++) {
			if (vtaken[j] && j < 5)hours += vcurr[j];
			else if (vtaken[j])mins += vcurr[j];	//j è gia maggiore di 4
		}

		if (hours > 23)return;
		if (mins > 59)return;

		printf("%02d", hours);
		putchar(':');
		printf("%02d, ", mins);

		return;
	}

	vtaken[i] = 1;	//accendo un led
	ValidTimesRec(n - 1, vcurr, vtaken, i + 1);
	vtaken[i] = 0;	//tengo spento il led
	ValidTimesRec(n, vcurr, vtaken, i + 1);

}

void ValidTimes(uint8_t n) {
	if (n > 11)return;

	int* vcurr = calloc(12, sizeof(int));
	bool* vtaken = calloc(12, sizeof(bool));
	//fill vcurr
	int i = 0;
	for (int j = 0; j < 11; j++) {
		i = j == 5 ? 0 : i;
		vcurr[j] = (int)pow(2, (double)i);
		++i;
	}
	//0-5 sono ore
	//6-11 sono minuti

	ValidTimesRec(n, vcurr, vtaken, 0);

	free(vtaken);
	free(vcurr);
}

//int main(void) {
//	ValidTimes(5);
//}